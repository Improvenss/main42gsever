/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_old.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:57:07 by akaraca           #+#    #+#             */
/*   Updated: 2022/09/12 14:48:32 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

// gcc minishell.c ../includes/minishell.h -lreadline && ./a.out
// gcc -Wall -Werror -Wextra minishell.c ../includes/minishell.h  -lreadline -o minishell && ./minishell
// gcc minishell.c ../includes/minishell.h -lreadline -L .brew/opt/readline/lib -I .brew/opt/readline/include && ./a.out

//brew goinfire'a kurulu ise; gcc minishell.c -L/goinfre/homebrew/opt/readline/lib -I/goinfre/homebrew/opt/readline/include -lreadline && ./a.out
//brew dosyalarını alt dizinde çalıştırmak istiyorsan; gcc minishell.c -L../includes/readline/lib -I../includes/readline/include -lreadline && ./a.out //mac'de kullanmak readline kütüphanesi sil yeniden kur(zip).

//ft_strncmp
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	if (n == 0)
		return (0);
	counter = 0;
	while (counter < (n - 1) && s1[counter] && s2[counter])
	{
		if (s1[counter] != s2[counter])
			break ;
		counter++;
	}
	return (((unsigned char *)s1)[counter] - ((unsigned char *)s2)[counter]);
}

//ft_strlen
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

//ft_lstsize
int	ft_lstsize(t_env *lst)
{
	size_t	count;

	count = 0;
	while (lst && ++count)
		lst = lst->next;
	return (count);
}

//ft_split
static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		count++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

static char	*stringf(const char *s, char c)
{
	char	*temp;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(const char *s, char c)
{
	char	**temp;
	int		wordc;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	wordc = ft_wordcount(s, c);
	temp = (char **)malloc(sizeof(char *) * (wordc + 1));
	if (!temp)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			temp[i] = stringf(s, c);
			i++;
		}
		while (*s && *s != c)
		s++;
	}
	temp[i] = NULL;
	return (temp);
}


//ft_strjoin
char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}

//ft_strdup
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


//history_empty_check için if (!s1 || !s2) durumu eklendi.
int	ft_strcmp_edited(char *s1, char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}


void	ft_exit(int error, char *str)
{
	if (str == NULL)
		printf("%s", "\0");
	else if (error == 0)
		printf(RED"%s: command not found\n"FINISH, str);
	else if (error == 1)
		printf(RED"%s"FINISH, str);
	else if (error == 2)
		printf(RED"cd: %s: No such file or directory\n"FINISH, str);
	else if (error == 3)
		printf(RED"export: '%s': not a valid identifier\n"FINISH, str);
	else if (error == 4)
		printf(RED"%s: Is a directory\n"FINISH, str);
	else if (error == 5)
		printf(RED"cd: %s: Not a directory\n"FINISH, str);
}

 //girilen splitli argümanları temizliyor.
void	ft_free(char **line)
{
	int	i;

	i = -1;
	while (line[++i])
		free((void *)line[i]);
	free((void *)line);
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

void	ft_input_line(const char *str, t_main *main)
{
	char	*tmp;

	main->line = ft_split(str, ' '); //space karakterli komut argümanlarını içericek.
	main->const_line = ft_split(str, ' '); //komut argümanlarını içericek.
	main->i = -1; //fonksiyonlarda destek verisi olarak kullanıyorum.
	while (main->line[++main->i] && main->line[main->i + 1] != NULL)
	{
		tmp = main->line[main->i];
		tmp[ft_strlen(tmp)] = ' '; // "echo - -ahmet" durumu için boşluk ekliyorum.
		main->line[main->i] = tmp;
	}
}

//env_name PWD,HOME,OLDPWD... argümanları tutmaktadır. if koşulu ile data[0] stringi strcmp ile karşılaştırılır ve eşit ise 0 döner.
char	*ft_env_findret(char *env_name, t_main *main)
{
	t_env	*tmp;

	tmp = main->env;
	while (tmp != NULL)
	{
		if (ft_strcmp_edited(env_name, tmp->data[0]) == 0)
			return (tmp->data[1]);
		tmp = tmp->next;
	}
	return (NULL);
}

// env yapısını listeye atamak için oluşturulmuş fonksiyon.
void	ft_env_struct(t_main *main, char *env_arg)
{
	t_env	*new;
	t_env	*temp;
	int		i;

	new = (t_env *)malloc(sizeof(t_env)); // yeni node alanı.
	new->data = ft_split(env_arg, '='); //data 2 boyutlu bir array olduğunda dolayı split ile 0. indexe PWD,OLDPWD,HOME argümanlar atanır. 1.index'e uzantıları atanır.
	new->next = NULL;
	if (new->data[2] != NULL) // kendi içerisinde "=" durumları olan argümanları ekleyebilmek için özel durum oluşturdum.
	{
		i = 1;
		while (new->data[++i] != NULL)
			new->data[1] = ft_strjoin(ft_strjoin(new->data[1], "="), new->data[i]);
		new->data[2] = NULL;
	}
	if (main->env == NULL) // ilk durumda değer atamak için yapıyoruz.
	{
		main->env = new;
		main->env->next = NULL;
	}
	else
	{
		temp = main->env; //main->env listesinin sabit kalmasını istediğimizden dolayı yedek liste oluşturup eşitliyoruz.
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	ft_login_print(void)
{
	printf("\n");
	printf("%s\n", GREEN"                _           _          "RED"__  __  ______  __      __ ");
	printf("%s\n", GREEN"   ____ ___    (_) ____    (_) "BLACK"_____  "RED"/ / / / / ____/ / /     / / ");
	printf("%s\n", GREEN"  / __ `__ \\  / / / __ \\  / / "BLACK"/ ___/ "RED"/ /_/ / / __/   / /     / /  ");
	printf("%s\n", GREEN" / / / / / / / / / / / / / / "BLACK"(__  ) "RED"/ __  / / /___  / /___  / /___");
	printf("%s\n", GREEN"/_/ /_/ /_/ /_/ /_/ /_/ /_/ "BLACK"/____/ "RED"/_/ /_/ /_____/ /_____/ /_____/"FINISH);
	printf("\n");
}

/**
 * env argümanları tek tek çağırılıp, listeye aktarılacak.
 * getenv("PATH"); gibi çağırılacak.
 */
void	ft_argument_set(t_main *main)
{
	extern char	**environ;
	int			i;

	main->tmp_environ = environ;
	main->env = NULL; // Listeyi yeni oluşturduğumuzdan dolayı NULL'a eşitlemeliyiz.
	i = -1;
	while (main->tmp_environ[++i])
		ft_env_struct(main, main->tmp_environ[i]);
	main->path = ft_env_findret("PWD", main);
	ft_login_print();
}

// komut satırına sadece <enter> veya "    " <enter> girdilerinin history kayıt edilmesini önlemek için.
// static olma durumu; sürekli olarak girilen(arka arkaya) komutun hafızaya alınmasına engel oluyor.
static int	ft_history_empty_check(const char *str)
{
	int			i;
	int			l;
	static char	*last_entry;

	if (ft_strcmp_edited((char *)str, last_entry) == 0) // arka arkaya girdiyi engelliyor
		return (0);
	last_entry = ft_strdup((char *)str);
	l = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			l++;
		i++;
	}
	//free((void *)str); //readline() leak oluşturduğundan dolayı bu fonk.'na argüman alma işlemi yaptığımızdan dolayı extra leak oluşuyor.
	if (i == l)
		return (0);
	return (1);
}




int	ft_strncmp_edited(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
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

int		ft_env_echo(char *str, t_main *main)
{
	t_env	*tmp;

	tmp = main->env;
	while (tmp != NULL)
	{
		if(ft_strcmp_edited(str, tmp->data[0]) == 0)
		{
			printf("%s\n", tmp->data[1]);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_print(t_main *main, int word)
{
	main->i = word;
	while (main->line[word])
		printf("%s", main->line[word++]);
	if (!ft_strncmp_edited(main->line[main->i - 1], "-n", 2))
		printf("\n");
}

void	ft_echo_command(t_main *main)
{
	if (main->line[1] == NULL) //echo <enter>
		printf("\n");
	else if (ft_strncmp_edited(main->line[1], "-n", 2)) //echo -n ahmet <enter>
	{
		main->i = 2; //fonksiyonlarda destek verisi olarak kullanıyorum.
		while (ft_strncmp_edited(main->line[main->i], "-n", 2)) //echo -n -n -n -n ahmet karaca <enter> durumunda "-n" fonk./opsiyonunu atlamak için.
			main->i++;
		if (main->line[main->i] == NULL) //echo -n <enter> durumu için kaçış görevi görüyor.
			printf("%s", "\0");
		else
			ft_print(main, main->i); //echo -n ... <enter> argümanlı, \n olmadan yazdırmak için kullanılıyor.
	}
	else if (main->line[1][0] == '$') // echo $? <enter> || echo $USER <enter> // 2.argümanın 0.indexinde $ işareti kontrolü
	{
		/*if (ft_strncmp_edited(main->line[1], "$?", 2)) // bir önceki komut TRUE ise 0, FALSE ise 1 dönecektir.
			printf("%d\n", main->command_run);
		else 
		*/if (!ft_env_echo(&main->line[1][1], main)) //&main->line[1][1] durumu, 1 indexten itibaren argümanın geri kalanını döndürüyor.
			printf("\n");
	}
	else
		ft_print(main, 1); //echo ahmet karaca ... <enter>
}


int		ft_file_search(char *str)
{
	int	fd;

	fd = open(str, 0); //NO_MATCH -> Flag olarak bir tanımlıyıcıya ihtiyacımız yok, belirtilen dizin içerisinde dosya varlık yokluk kontrolü gereklidir. (windowsta var)
	close(fd);
	if (fd == -1) //dosya yok ise -1 döner.
		return (0);
	return (1);
}

//env satırında değiştirilmesi istenilen argüman aranıyor ve str argümanına 1.indexi eşitleniyor.
void	ft_set_env(char *env_name, char *new_str, t_main *main)
{
	t_env	*tmp;
	
	tmp = main->env;
	while (tmp != NULL)
	{
		if (ft_strcmp_edited(env_name, tmp->data[0]) == 0)
		{
			tmp->data[1] = new_str;
			break;
		}
		tmp = tmp->next;
	}
}

//cd .. <enter> girdisinde bir önceki / dizinin eşitiliğine verebilmek için sondaki "/" aranıyor ve önceki string döndürülüyor.
char	*ft_cut_directory(char *str)
{
	int		i;
	int		l;
	char	*tmp;

	i = -1;
	l = -1;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (str[++i])
	{
		if (str[i] == '/')
			l = i;
	}
	i = -1;
	while (str[++i] && i < l)
		tmp[i] = str[i];
	tmp[i] = '\0';
	if (tmp[0] == '\0') // root dizini için "/" işareti bırakmıyor bu yüzden koşul belirlemek durumundayız.
		return ("/");
	return (tmp);
}

// cd komutu ile dizine erişim gerçekleştirirken, dizinin varlık ve yokluğu kontrol edilir.
int	ft_directory_search(char *str)
{
	int		fd;

	fd = open(str, O_DIRECTORY); //O_DIRECTORY -> Yol adı bir dizin değilse, açmanın başarısız olmasına neden olur.
	close(fd);
	if (fd == -1) //dizin yok ise -1 döner.
		return (0);
	return (1);
}

char	*ft_clear_backslah(char *str)
{
	int		i;
	int		l;
	char	*tmp;

	l = 0;
	i = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * i);
	while (l < i && str[l] != '/')
	{
		tmp[l] = str[l];
		l++;
	}
	tmp[l] = '\0';
	free(str);
	return (tmp);
}

char	*ft_double_dot(char *str)
{
	char	*tmp;
	int		l;
	int		i;

	i = 0;
	l = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * l);
	while (str[l] != '/')
		l--;
	while (i < l)
	{
		tmp[i] = str[i];
		i++;
	}
	if (l == 0)
		tmp[i++] = '/';
	tmp[i] = '\0';
	return (tmp);
}

void	ft_cd_command(t_main *main)
{
	if (main->line[1] == NULL || ft_strncmp_edited(main->line[1], "~", 1) || ft_strncmp_edited(main->line[1], "--", 2)) // cd <enter> || cd ~ <enter> || cd -- <enter> -> "/home/akaraca" dizinine gidiyor.
	{
		ft_set_env("OLDPWD", main->path, main);
		main->old_path = main->path;
		chdir(ft_env_findret("HOME", main)); // "HOME" sistemdeki ana dizini bulmayı sağlıyor.
		main->path = ft_env_findret("HOME", main);
		ft_set_env("PWD", main->path, main);
	}
	else if (ft_strncmp_edited(main->line[1], "-", 1)) // cd - <enter>
	{
		main->old_path = ft_env_findret("OLDPWD", main);
		main->path = ft_env_findret("PWD", main); // cd --, cd-, cd --, cd-, cd --, durumunda hatalı.
		ft_set_env("PWD", ft_env_findret("OLDPWD", main), main); // pwd komutunun çalışabilmesi için list env'sinin yenilenmesi gerekiyor.
		ft_set_env("OLDPWD", main->path, main); // pwd komutunun çalışabilmesi için list env'sinin yenilenmesi gerekiyor.
		chdir(main->old_path); // bir önceki /'li dizine geçişi sağlıyor.
		printf("%s\n", ft_env_findret("PWD", main)); // cd - <enter> komutu ile geçilen dizi çıktısı veriliyor.
		main->old_path = main->path; // cd - <enter> ile bir önceki dizine geçişi, ardından cd - <enter> ile tekrardan bir önceki diziye geçiş sağlıyor, kısaca rec. bir fonk.
	}
	else if (main->line[1] != NULL && ft_directory_search(main->line[1])) //cd .. <enter> || cd Desktop <enter> // bulunamadı durumu için ls komutu gerekiyor.
	{
		/// !!! "cd . <enter>" durumunda /mnt/c/././. path oluşuyor. ✓
		main->old_path = main->path;
		if (ft_strncmp_edited(main->line[1], "..", 2))
		{
			ft_set_env("PWD", ft_double_dot(main->path), main);
			main->path = ft_env_findret("PWD", main);
		}
		else
		{	if (main->path[0] == '/' && main->path[1] == '\0') // root dizinin üzerine tekrardan "/" atılmaması için özel durum belirliyoruz.
				main->path = ft_strjoin(main->path, main->line[1]);
			else
			{
				if (!ft_strncmp_edited(main->line[1], ".", 1)) // cd . <enter> girdisinin sonucu "/mnt/c/././." gibi bir path oluşmaması için eklenmelidir. lakin bu aynı pathe erişim gerekmediği anlamına gelmez bu yüzden oldpath değişmelidir(kısaca oldpath aynı path olacak).
				{	
					main->line[1] = ft_clear_backslah(main->line[1]); // cd soruces///////// <enter> girdisi sonucunda sources///// dizinine giriyordu(var olmayan bir dizi), bu yüzden sondaki '/' işaretlerini kaldırdım.
					main->path = ft_strjoin(main->path, ft_strjoin("/", main->line[1]));
				}
			}
			ft_set_env("PWD", main->path, main); //gerçekleştirilen dizin değişimini env'ye belirtmeliyiz.
		}
		ft_set_env("OLDPWD", main->old_path, main);
		chdir(main->path);
	}
	else if (ft_file_search(main->line[1])) // cd 1.c <enter>, dizin içerisinde bulunan bir argümana directory olarak erişim olduğunda hata veriyor.
		ft_exit(5, main->line[1]);
	else
		ft_exit(2, main->line[1]); // dizin içerisinde aranan argüman bulunmadığı zaman buraya girmesi gerekiyor.
}

void	ft_pwd_command(t_main *main)
{
	printf("%s\n", ft_env_findret("PWD", main));
}

void	ft_env_command(t_main *main)
{
	t_env	*tmp;

	tmp = main->env;
	while (tmp != NULL)
	{
		if (tmp->data[1] == NULL) //program dışında export ile boş argüman ataması yapıldıysa segmantation fault almamak için argüman kontrolü yapılmalıdır.
			tmp->data[1] = ""; //b=(null)'durumunu engellemek için, boş string atıyoruz.
		if (ft_strcmp_edited(tmp->data[1], "' '") != 0) //env komutunda boş argümanların yazılması istenilmiyor.
			printf("%s=%s\n", tmp->data[0], tmp->data[1]);
		tmp = tmp->next;
	}
}

//girilen diğer komutların clear, ls, ls -la, man ... vb çalıştırılmasını sağlıyor.
int	ft_command_path(t_main *main) //leak durumu düzeltildi, düzene çekilmeli 
{
	char	**PATH;
	int		i;
	char	*directory;
	char	*directory_2;
	char	**cmd;

	i = -1;
	PATH = ft_split(ft_env_findret("PATH", main), ':'); //PATH dizininlerini tutuyor.
	cmd = ft_split(main->cmd, ' ');
	while (PATH[++i])
	{
		directory_2 = ft_strjoin(PATH[i], "/");
		directory = ft_strjoin(directory_2, cmd[0]);
		free(directory_2);
		if (access(directory, 0) == 0) //access komut kontrolü yapıyor.
		{
			main->command_path = directory;
			ft_free(PATH);
			ft_free(cmd);
			//free(directory); //açık olursa mac'ta problem olmuyor ancak windows pcde çıktılar ekrana yazmıyor.
			return (1);
		}
		free(directory);
	}
	ft_free(PATH);
	ft_free(cmd);
	return (0);
}


//list yapısındaki en büyük stringin bir öncekini bulmaya yarıyor, max stringide döndürülebilir (değişken durumda)
char	*ft_find_max_str(t_main *main)
{
	t_env	*tmp;
	char	*max;
	//char	*max_before;

	tmp = main->env;
	max = tmp->data[0];
	while (tmp != NULL)
	{
		//max_before = max;
		if (ft_strcmp_edited(max, tmp->data[0]) < 0)
			max = tmp->data[0];
		tmp = tmp->next;
	}
	return (max);
	//return (max_before); //max = _ olduğundan dolayı bir önceki değeri döndürüyorum.
}

//list yapısındaki min stringi döndürüyor.
char	*ft_find_min_str(t_main *main)
{
	t_env	*tmp;
	char	*min;

	tmp = main->env;
	min = tmp->data[0];
	while (tmp != NULL)
	{
		if (ft_strcmp_edited(min, tmp->data[0]) > 0)
			min = tmp->data[0];
		tmp = tmp->next;
	}
	return (min);
}


void	ft_export_print(t_main *main)
{
	t_env	*tmp_down;
	char	*str;
	char	*print;
	int		i;

	i = ft_lstsize(main->env);//export yazınca _ data'sı yazdırılmak istenmez ise -1 koyulur. ????
	print = ft_find_min_str(main); //env argümanındaki min stringi buluyor.
	while (i-- > 0)
	{
		str = ft_env_findret(print, main); //program dışında b=(null) argüman girdisi olduğu zaman, export yazdırma işlemindede null olarak görüyor, bunu engellemek için.
		if (str == NULL)
			str = ""; // null yerine boş string atıyoruz.
		if (ft_strcmp_edited(print, "_=") != 0) // _= argümanı export çıktısında bulunmuyor.
			printf("declare -x %s=%c%s%c\n", print, '"', str, '"'); //bash'de export yazınca declare -x bilgisi bulunuyor ve argüman değerleri tırnak içerisinde.
		str = ft_find_max_str(main); //env argümanındaki max stringi döndürüyor.
		tmp_down = main->env;
		while (tmp_down != NULL)
		{
			//printf("str: %s print: %s data: %s\n", str, print, tmp_down->data[0]);
			if (ft_strcmp_edited(print, tmp_down->data[0]) < 0 && ft_strcmp_edited(str, tmp_down->data[0]) > 0) // "> 0" en küçük argümanı çekiyor, "< 0" en büyük argümanı çekiyor. ???
				str = tmp_down->data[0];
			tmp_down = tmp_down->next;
		}
		print = str;
	}
	//printf("declare -x %s=%c%s%c\n", print, '"', ft_env_findret(print, main), '"'); //son argümanı yazdırmıyor bu yüzden yazdırdım.
}


//string içerisinde belirtilen karakteri arar, var ise 1 döner.
int	ft_chr_is_there(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

//export girdisinde aynı argüman girdisi var ise, argüman değeri girdi değeri ile değişecek ve 0 dönecek.
//!!! A=AHMET argüman girdisi bulunuyor ise ve "export A <enter>" şeklinde boş argüman girdisi olur ise değişiklik yapılmayacak.
//!!! "export A= <enter>" girdisi yapılırsa değer NULL olarak değiştirilir.
int	ft_export_same_check(char *str, t_main *main)
{
	t_env	*check;
	char	**data;
	int		l;

	l = ft_chr_is_there(str, '=');
	data = ft_split(str, '=');
	check = main->env;
	while (check != NULL)
	{
		if (ft_strcmp_edited(data[0], check->data[0]) == 0) //Girdisi yapılmış aynı argüman varmı onun kontrolünü yapıyor.
		{
			if (l != 0) // '=' işareti var ise girdide argüman girdisi NULL olsa dahi değişecek.
				check->data[1] = data[1]; //girdisi yapılan aynı argümanın değeri değiştiriliyor.
			return (0); //0 değeri dönerek bir önceki fonk.'da yeni node oluşturması engelleniyor.
		}
		check = check->next;
	}
	return (1);
}

//env'nin son argümanından öncesine argüman eklemeye yarıyor. (_ argümanının gerisine)
//export ABC=DEF KLM=PRS JKH=OPRS girdileri tek tek eklenmelidir.
//export A A A, şeklinde ayni argüman girdisi olur ise tek bir argüman olarak sayılacak.
//Daha önceden girdisi olan aynı argüman tekrar girildiği zaman değeri(eşittir karşılığı) değişecek.
//export A=AHMET A=KARACA A=AAAA, girdi sonucu A=AAAA olarak kaydedilir.
void	ft_export_add(t_main *main)
{
	t_env	*tmp;
	t_env	*new;
	int		i;

	i = 1;
	while (main->const_line[i])
	{
		if (ft_export_same_check(main->const_line[i], main))
		{
			new = (t_env *)malloc(sizeof(t_env));
			new->data = ft_split(main->const_line[i], '='); //ABC=DEF'argümanı eşittirden(=) sonra farklı indexlere atanır.
			if (new->data[1] == NULL)
				new->data[1] = ""; //girilen argümanın değeri girilmediyse tırnak içerisinde gözükmelidir.
			tmp = main->env;
			while (tmp->next->next != NULL)
				tmp = tmp->next;
			new->next = tmp->next;
			tmp->next = new;
		}
		i++;
	}
}

void	ft_export_command(t_main *main)
{
	// Girdisi yapılan argümanın tekrar girdisi oluyor, hatalı, sadece değeri değiştirilsin. ✓
	// export __CF son argümanı yazmıyor. ✓
	// export aaaa=aaaa yazınca export komutunda kayboluyor. ✓
	// export ABCD=DEFG LKG=OOO atamasının 1.atamasını görüyor. 2. ve daha sonrakiler atanmıyor düzelt. ✓
	// export BBBB yazınca export komutunda (null) gözüküyor. ' ' şeklinde gözükmeli. ✓
	// boş argüman ataması yapılan (BBBB), env listesinde gözükmemeli yani sağ tarafı null olan ekrana bastırılmamalıdır. ✓
	// export =KKK yazınca "zsh: KKKK not found" hatası çıkmalı. ve env ve exportta ataması yapılıyor engelle.KKK=NULL olarak. ✓
	// export çıktısı argüman eşitliği " " tırnak içerisinde olacak ✓
	if (main->line[1] == NULL)
		ft_export_print(main); // export <enter> ile env listesinin alfabetik sıralanışı çıkıyor.
	else if (main->line[1][0] == '=') // export =AAAA <enter> argüman girişi hatalı bir girdidir, NULL değeri bir şey tutamaz.
			ft_exit(3, main->line[1]);
	else
		ft_export_add(main); // export ..=... <enter> ile env listesine argüman uzantısı eklenmiş olunuyor.
}

void	ft_unset_command(t_main *main) //(unset A B C) birden fazla argümanlı çalışıyor.
{
	t_env	*tmp;
	t_env	*before;
	t_env	*del;
	//int		i;
	int		l;

	l = 0;
	while (main->const_line[++l] != NULL) // unset A B C, argümanları sırasıyla işleme sokulacak.
	{
		tmp = main->env;
		tmp->prev = NULL; //tmp'nin bir önceki argümanı olmadığından dolayı NULL' eşitlenir.
		while (tmp != NULL && main->const_line[l] != NULL)
		{
			//i = -1;
			//printf("line: %s data: %s\n", main->line[l], tmp->data[0]);
			if (ft_strcmp_edited(main->const_line[l], tmp->data[0]) == 0)
			{
				del = tmp; //unset edilmesi gereken argümanın adresini bulabilmek için işaretciye ihtiyacımız var.
				tmp->prev->next = tmp->next;
				//while (del->data[++i]) //birdan fazla stringi barındırdığı için while döngüsü ile temizliyoruz.
				//	free(del->data[i]); // unset A B C, çoklu unset yapma işleminde hata verdiyor bu freeleme işlemi. bu yüzden kapattım. boş argüman eşitliğinde hata veriyor.
				free(del->data); //2 boyutlu stringin içeriği free'lendikten sonra stringin kendisini freeliyoruz.
			}
			before = tmp; //tmp'nin bir önceki argümanının hafızada tutabilmek için yardımcı liste kullanılır.
			tmp = tmp->next; //liste üzerinde gezinmeyi sağlar.
			if (tmp != NULL) // tmp'nin NULL durumunda işaretçiler bulunmayacağından dolayı segmantation fault döndürür bu yüzden bu koşul gereklidir.
				tmp->prev = before; //tmp listesinin argümanlarının bir önceki adres(node) eşitliğini sağlamak için kullanılır.
		}
	}
}



// ilk iki indexi "./" olmalıdır, son "/" 'dan sonrası çalıştırılması gereken dosyayı temsil etmektedir.
int	ft_search_and_launch(t_main *main)
{
	if (ft_strncmp(main->const_line[0], "./", 2))
		return (0);
	if (!ft_file_search(main->const_line[0]))
		return (0);
	return (1);
}

void	ft_command_find(t_main *main) //echo, cd, pwd... array'e alınıp karşılaştırması yapılıp bulunduğu 2boyutlu indexi döndürülerek komut yönlendirmesi yapılabilir. Bu sayede birden fazla komut eklenebilir.
{
	if (main->line[0] == NULL) // <enter>
		printf("%s","\0");
	else if (ft_strncmp_edited(main->line[0], "echo", 4)) // echo ... <enter>
		ft_echo_command(main);
	else if (ft_strncmp_edited(main->line[0], "cd", 2)) // cd ... <enter>
		ft_cd_command(main);
	else if (ft_strncmp_edited(main->line[0], "pwd", 3)) // pwd <enter>
		ft_pwd_command(main);
	else if (ft_strncmp_edited(main->line[0], "unset", 5)) // export ile yapılan atama "unset ev" şeklinde kaldırılabiliniyor.
		ft_unset_command(main);
	else if (ft_strncmp_edited(main->line[0], "export", 6)) // "export ev=/mnt/c/Users/ViTT/Desktop" ataması env içerisine yapılabiliniyor. // export <enter> env'nin sıralanmış halini yazdırıyor. // env kendi içerisinde sıralanacak, export argümanları kendi içerisinde sıralanacak.
		ft_export_command(main);
	else if (ft_strncmp_edited(main->line[0], "env", 3)) // env <enter>
		ft_env_command(main);
	else if (ft_strncmp_edited(main->line[0], "exit", 4)) // exit <enter>
		exit(0);
	else if (ft_search_and_launch(main)) //dosya arama ve çalıştırma işlemini gerçekleştiriyor.
	{
		if (ft_directory_search(main->const_line[0])) // "./sources <enter>" girdisi olur ve program isim girdisi olmaz ve son "/"'den sonrası dizin ise hata döndürür.
			ft_exit(4, main->const_line[0]);
		else
		{
			// "./sources/a.out" "./a.out" "../a.out" "./sources/.././a.out" "./sources/././a.out"
			int pi = fork();
			if (pi == 0)
				execve(main->const_line[0], main->const_line, main->tmp_environ);
			waitpid(pi, 0, 0);
		}
	}
	else if (ft_command_path(main)) //komutları path'te arama ve çalıştırma işlemini yapıyor.
	{
		int pi = fork(); //execve işlemi sonrasında sonlandırma yaptığından dolayı bu işlemi alt proseslerde yapıyoruz.
		if (pi == 0)
		{
			//printf("| path: %s, line[0]: %s, line[1]: %s, line[2]: %s |\n", main->command_path, main->const_line[0], main->const_line[1], main->const_line[2]);
			execve(main->command_path, main->const_line, main->tmp_environ);
			//execve(const char *filename, char *const argv[], char *const envp[]);
		}
		waitpid(pi, 0, 0);
	}
	else
		ft_exit(0, main->line[0]);
}

//Terminal ismi, tasarımı vs. bozuluyor???
char	*ft_terminal_print(t_main *main)
{
	char	*name;
	char	*logname;
	char	*str;
	char	*tmp;

	logname = ft_env_findret("LOGNAME", main);
	name = ft_env_findret("NAME", main);
	if (name == NULL)
		name = "42kocaeli.com.tr";
	str = "\n\e[0;32m┌──(\e[0;31m";
	tmp = ft_strjoin(str, logname);
	str = ft_strjoin(tmp, "@");
	free(tmp);
	tmp = ft_strjoin(str, name);
	str = ft_strjoin(tmp, "\e[0;32m)-[\e[0;37m");
	free(tmp);
	tmp = ft_strjoin(str, ft_env_findret("PWD", main));
	str = ft_strjoin(tmp, "\e[0;32m]\n└─\e[0;36m$\e[m ");
	free(tmp);
	return (str);
	//return ("┌──(", logname, "@", name, ")-[", pwd, "]\n└─$ ");
}



char	*ft_string_concatenation(char *str1, char *str2, char *str3, char *str4)
{
	char	*tmp;
	int		l;
	int		i;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3) + ft_strlen(str4)));
	i = 0;
	l = 0;
	while (str1[i])
		tmp[l++] = str1[i++];
	i = 0;
	while (str2[i])
		tmp[l++] = str2[i++];
	i = 0;
	while (str3[i])
		tmp[l++] = str3[i++];
	i = 0;
	while (str4[i])
		tmp[l++] = str4[i++];
	tmp[l] = '\0';
	return (tmp);
}

void	ft_detec(int sig) //düzenlenecek. //struct yapısına kaydedilen bölgeye dönüyor.(hatalı)
{
	t_main *main;
	extern char	**environ;
	int			i;

	main->env = NULL; // Listeyi yeni oluşturduğumuzdan dolayı NULL'a eşitlemeliyiz.
	i = -1;
	while (environ[++i])
		ft_env_struct(main, environ[i]);
	if (sig == 2)
	{
		char *s = ft_string_concatenation("\n\e[0;32m┌──(\e[0;31m", ft_env_findret("LOGNAME", main), "@", ft_env_findret("NAME", main));

		printf("\n%s", ft_string_concatenation(s, "\e[0;32m)-[\e[0;37m", ft_env_findret("PWD", main), "\e[0;32m]\n"));
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == 3)
		printf("%s", "\n");
}

/*
> Tanım:
	> Bu proje basit bir kabuk(shell) oluşturmakla ilgilidir.
		İşlemler ve dosya tanımlayıcıları hakkındadır.
> İzin verilen fonksiyonlar:
	> readline, rl_clear_history, rl_on_new_line, rl_replace_line,
	rl_redisplay, add_history, printf, malloc, free, write, access,
	open, read, close, fork, wait, waitpid, wait3, wait4, signal,
	sigaction, sigemptyset, sigaddset, kill, exit, getcwd, chdir,
	stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir,
	readdir, closedir, strerror, perror, isatty, ttyname, ttyslot,
	ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum,
	tgetstr, tgoto, tputsc

> Kabukta olması gereken özellikler:
	> Yeni bir komut beklerken bir bilgi istemi görüntüleyin. ✓
	> Girdileri hafıza tutarak history oluşturun. ✓
	> Search and launch, dosyayı arayın ve başlatın. ✓
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
	> ctrl-C, yeni bir satırda yeni bir bilgi istemi görüntüler. ✓
	> ctrl-D exits the shell. ✓
	> ctrl-\ does nothing. ✓

> Terminalin uygulaması gereken komutları:
	> echo with option -n ✓
	> cd with only a relative or absolute path ✓
	> pwd with no options ✓
	> export with no options ✓
	> unset with no options ✓
	> env with no options or arguments ✓
	> exit with no options ✓

> READLINE WHAT MEAN??
	> THIS MEAN IS "FUCK OFF LEAKS",
	> readline() işlevi bellek sızıntılarına neden olabilir.
	Onları düzeltmek zorunda değilsin.
	Ancak bu kendi kodunuz anlamına gelmez,
	evet yazdığınız kodda bellek sızıntısı olabilir.
*/
int	main(void)
{
	t_main	main;

	//printf("\e[1;1H\e[2J"); // Derleme sonrasında önceki girdileri silmeye yarıyor.
	ft_argument_set(&main); //while dışında olmalı!! Olmaz ise sürekli standart env değerleri ile eşitlenecek.
	while (1)
	{
		//signal(SIGINT, ft_detec); // control-C signal, yeni bir satıra geçiş yapmalı.
		//signal(SIGQUIT, ft_detec); // "control-\" , ingilizce klavyede "control-," ile çalışıyor.
		main.cmd = readline(ft_terminal_print(&main)); // terminal adının silinmemesi için " " girilmesi gerekiyor, NULL durumunda siliyor. //terminal history durumunda buga giriyor
		if (!main.cmd) //control-D tuş kombinasyonu ile terminal kapatılmalı.
			exit(0);
		if (ft_history_empty_check(main.cmd)) // boş girilen satırları atlamak için. //
			add_history(main.cmd); //history bro, use fucking keyboard arrow and you see that shits
		ft_input_line(main.cmd, &main);
		ft_command_find(&main);
		ft_free(main.line);
		free((void *)main.cmd);
		//system("leaks a.out");
	}
	return (0);
}