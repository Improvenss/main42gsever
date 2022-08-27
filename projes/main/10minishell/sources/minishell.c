/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:57:07 by akaraca           #+#    #+#             */
/*   Updated: 2022/08/27 22:10:19 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(int error, char *str)
{
	if (str == NULL)
		printf("%s", "\0");
	else if (error == 0)
		printf(RED"zsh: command not found: "PURPLE"%s\n"FINISH, str);
	else if (error == 1)
		printf(RED"%s"FINISH, str);
	else if (error == 2)
		printf(RED"cd: %s: No such file or directory\n"FINISH, str);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_word_count(const char *str)
{
	int	i;
	int	l;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	l = 0;
	if (i == 0)
		l++;
	while (str[i])
	{
		if (((str[i - 1] >= 9 && str[i - 1] <= 13) || str[i - 1] == 32) &&\
		(str[i] < 9 || str[i] > 13) && str[i] != 32)
			l++;
		i++;
	}
	return (l);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (s1 && (*s1 != '\0') && (*s1 == *s2) && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0 && (s1[n] == ' ' || s1[n] == '\0')) // "(s1[n] == ' ' || s1[n] == '\0')" cd .. <enter> durumu, cd.. <enter> şeklinde kullanılmasını engellemek için konuldu.
		return (1);
	return (0);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	ft_argument_set(t_main *main)
{
	char CWD[256];

	getcwd(CWD, sizeof(CWD));
	main->path = ft_strdup(CWD); //ft_strdup olmaz ise fonksiyon dışında string bozuluyor. ??
}

void	ft_input_line(const char *str, t_main *main)
{
	main->word_count = ft_word_count(str); //son argüman kontrolü için uzunluk tutuyorum. (ileriye dönük)
	main->line = (char **)malloc(sizeof(char **) * (main->word_count));
	if (!main->line)
		ft_exit(1, "malloc() failed: Insufficient memory!"\
			" Failed to allocate bytes.");
	main->line = ft_split(str, ' ');
	main->i = -1; //fonksiyonlarda destek verisi olarak kullanıyorum.
	while (main->line[++main->i] && main->line[main->i + 1] != NULL)
		main->line[main->i] = ft_strjoin(main->line[main->i], " "); // "echo - -ahmet" durumu için boşluk ekliyorum.
}

void	ft_print(t_main *main, int word)
{
	main->i = word;
	while (main->line[word])
	{
		printf("%s", main->line[word]);
		word++;
	}
	if (!ft_strncmp(main->line[main->i - 1], "-n", 2))
		printf("\n");
}

void	ft_echo_command(t_main *main)
{
	if (main->line[1] == NULL) //echo <enter>
		printf("\n");
	else if (ft_strncmp(main->line[1], "-n", 2)) //echo -n ahmet <enter>
	{
		main->i = 2; //fonksiyonlarda destek verisi olarak kullanıyorum.
		while (ft_strncmp(main->line[main->i], "-n", 2)) //echo -n -n -n -n ahmet karaca <enter> durumunda "-n" fonk. atlamak için.
			main->i++;
		if (main->line[main->i] == NULL) //echo -n <enter> durumu için kaçış görevi görüyor.
			printf("%s", "\0");
		else
			ft_print(main, main->i);
	}/*
	else if (ft_strncmp(main->line[1][0], "$", 1)) // echo $? <enter> || echo $USER <enter>
	{
		if (env_check(&main->line[1][1]))
		{
			
		}
	}
	*/
	else
		ft_print(main, 1); //echo ahmet karaca ... <enter>
}

/**
 * Bir önceki dizi konumuna gitmeyi sağlıyor.
 * Aldığı path'in sonunda başlayarak bakıyor.
 * İlk gördüğü '/' 'de size konumunu alıyor.
 * Tmp'ye size'ı azaltarak kopyalıyor ve döndürüyor.
 */
char	*ft_down_to_backslash(char *path)
{
	int		size;
	char	*tmp;

	size = ft_strlen(path);
	while (path[size] != '/')
		size--;
	tmp = (char *)malloc(sizeof(char) * size);
	if (!tmp)
		ft_exit(1, "malloc() failed: Insufficient memory!"\
			" Failed to allocate bytes.");
	tmp[size] = '\0';
	while (size >= 0)
	{
		tmp[size] = path[size];
		size--;
	}
	return (tmp);
}

void	ft_cd_command(t_main *main)
{
	if (main->line[1] == NULL || ft_strncmp(main->line[1], "~", 1) || ft_strncmp(main->line[1], "--", 2)) // cd <enter> || cd ~ <enter> || cd -- <enter> -> "/home/akaraca" dizinine gidiyor.
	{
		main->old_path = main->path;
		chdir(getenv("HOME")); // getenv("HOME"), sistemdeki ana dizini bulmayı sağlıyor.
	}
	else if (ft_strncmp(main->line[1], "-", 1)) // cd - <enter>
		chdir(main->old_path); // bir önceki /'li dizine geçişi sağlıyor.
	else if (main->line[1] != NULL) //cd .. <enter> || cd Desktop <enter>
	{
		main->old_path = main->path;
		main->path = ft_strjoin(main->path,ft_strjoin("/", main->line[1]));
		chdir(main->path);
	}
	else
		ft_exit(2, main->line[1]);
}

void	ft_pwd_command(t_main *main)
{
	char CWD[256];

	getcwd(CWD, sizeof(CWD));
	printf("%s\n", CWD);
}

void	ft_command_find(t_main *main) //echo, cd, pwd... arraya alınıp karşılaştırması yapılıp bulunduğu 2boyutlu indexi döndürülerek komut yönlendirmesi yapılabilir. Bu sayede birden fazla komut eklenebilir.
{
	if (ft_strncmp(main->line[0], "echo", 4))
		ft_echo_command(main);
	else if (ft_strncmp(main->line[0], "cd", 2))
		ft_cd_command(main);
	else if (ft_strncmp(main->line[0], "pwd", 3))
		ft_pwd_command(main);
	/*else if (ft_strncmp(main->line[0], "unset", 5))
		ft_unset_command(main);
	else if (ft_strncmp(main->line[0], "export", 6))
		ft_export_command(main);
	else if (ft_strncmp(main->line[0], "env", 3))
		ft_env_command(main);*/
	else if (ft_strncmp(main->line[0], "exit", 4))
		exit(0);
	else if (ft_strncmp(main->line[0], "clear", 5))
		printf("\e[1;1H\e[2J");
	else
		ft_exit(0, main->line[0]);
}

/*
> Tanım:
	> Bu proje basit bir kabuk(shell) oluşturmakla ilgilidir.
		İşlemler ve dosya tanımlayıcıları hakkındadır.
> İzin verilen fonksiyonlar:
	> readline(), rl_clear_history(), rl_on_new_line(), rl_replace_line(),
	rl_redisplay(), add_history(), printf(), malloc(), free(), write(), access(),
	open(), read(), close(), fork(), wait(), waitpid(), wait3(), wait4(), signal(),
	sigaction(), sigemptyset(), sigaddset(), kill(), exit(), getcwd(), chdir(),
	stat(), lstat(), fstat(), unlink(), execve(), dup(), dup2(), pipe(), opendir(),
	readdir(), closedir(), strerror(), perror(), isatty(), ttyname(), ttyslot(),
	ioctl(), getenv(), tcsetattr(), tcgetattr(), tgetent(), tgetflag(), tgetnum(),
	tgetstr(), tgoto(), tputs()

> Kabukta olması gereken özellikler:
	> Yeni bir komut beklerken bir bilgi istemi görüntüleyin.
	> Girdileri hafıza tutarak history oluşturun.
	> Search and launch, dosyayı arayın ve başlatın.
	> Min 1 global değişken kullanılabilir. Açıklanmalıdır.
	> Kapatılmamış alıntıları veya
		özel karakterleri yorumlamayın. "\" (backslash) or ";" (semicolon)
	> Alıntılanan dizideki meta karakterlerin tek tırnak içerisinde iken engellenmesi gerekmektedir.
	> Alıntılanan dizideki $ işaretinin argüman çağırması gerektiğini tanıt.

> Uygulanması gerekenler;
	> "< should redirect input" "<" işaretnin işlevini yerine getirin.
	> "> should redirect output" ">" işaretinin işlevini yerine getirin.
	> "<< bir sınırlayıcı verilmeli"
		ardından sınırlayıcıyı içeren bir satır görülene kadar girişi okumalısınız.
		Ancak, geçmişi güncellemek zorunda değildir!
	> Boruları (| karakter) uygulayın. Boru hattındaki her komutun çıkışı,
		bir sonraki komutun girişine bir boru aracılığıyla bağlanır.
	> Değerlerine genişlemesi gereken ortam değişkenlerini ($ ardından bir karakter dizisi) kullanın.
	> $? bir önceki komut TRUE ise 0, FALSE ise 1 dönecektir.
	> Bash'deki gibi davranması gereken ctrl-C, ctrl-D ve ctrl-\'yi kullanın.

> Terminal ile etkileşim içinde iken:
	> ctrl-C, yeni bir satırda yeni bir bilgi istemi görüntüler.
	> ctrl-D exits the shell.
	> ctrl-\ does nothing.

> Terminalin uygulaması gereken komutları:
	> echo with option -n
	> cd with only a relative or absolute path
	> pwd with no options
	> export with no options
	> unset with no options
	> env with no options or arguments
	> exit with no options


> READLINE WHAT MEAN??
	> THIS MEAN IS "FUCK OFF LEAKS",
	> readline() işlevi bellek sızıntılarına neden olabilir.
	Onları düzeltmek zorunda değilsin.
	Ancak bu kendi kodunuz anlamına gelmez,
	evet yazdığınız kodda bellek sızıntısı olabilir.
*/
int	main(void)
{
	const char	*cmd;
	t_main		main;

	//printf("\e[1;1H\e[2J"); // Derleme sonrasında önceki girdileri silmeye yarıyor.
	while (1)
	{
		cmd = readline(COMMAND_SIGN); // terminal adının silinmemesi için " " girilmesi gerekiyor, NULL durumunda siliyor.
		add_history(cmd); //history bro, use fucking keyboard arrow and you see that shits
		ft_argument_set(&main);
		ft_input_line(cmd, &main);
		ft_command_find(&main);
	}
	
	return (0);
}