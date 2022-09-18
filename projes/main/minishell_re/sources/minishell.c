/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:57:07 by akaraca           #+#    #+#             */
/*   Updated: 2022/09/13 18:08:19 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

t_main	g_main;
/*
// gcc minishell.c ../includes/minishell.h -lreadline && ./a.out
// gcc -Wall -Werror -Wextra minishell.c ../includes/minishell.h  -lreadline -o minishell && ./minishell
// gcc minishell.c ../includes/minishell.h -lreadline -L .brew/opt/readline/lib -I .brew/opt/readline/include && ./a.out

//brew goinfire'a kurulu ise; gcc minishell.c -L/goinfre/homebrew/opt/readline/lib -I/goinfre/homebrew/opt/readline/include -lreadline && ./a.out
//brew dosyalarını alt dizinde çalıştırmak istiyorsan; gcc minishell.c -L../includes/readline/lib -I../includes/readline/include -lreadline && ./a.out //mac'de kullanmak readline kütüphanesi sil yeniden kur(zip).
*/

//-----Functions Must be removed-------//
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
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*temp;

	i = 0;
	k = 0;
	temp = NULL;
	if (!s1 || !s2)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + \
				ft_strlen(s2) + 1));
	if (!temp)
		return (NULL);
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		temp[k + i] = s2[k];
		k++;
	}
	temp[k + i] = '\0';
	return (temp);
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

//---------------------------//

void	ft_exit(int error, char *str1, char *str2, char *str3)
{
	if (str1 == NULL)
		printf("%s", "\0");
	else
		printf(RED"%s%s%s"END, str1, str2, str3);
	if (error < 0)
		exit(0);
	/*else if (error == 0)
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
		printf(RED"cd: %s: Not a directory\n"FINISH, str);*/
}

//girilen splitli argümanları temizliyor.
void	ft_free(char **line)
{
	int	i;

	i = -1;
	while (line[++i])
		free(line[i]);
	free(line);
}

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

int		ft_file_search(char *str)
{
	int	fd;

	fd = open(str, 0); //NO_MATCH (0)-> Flag olarak bir tanımlıyıcıya ihtiyacımız yok, belirtilen dizin içerisinde dosya varlık yokluk kontrolü gereklidir. (windowsta var)
	close(fd);
	if (fd == -1) //dosya yok ise -1 döner.
		return (0);
	return (1);
}

// env yapısını listeye atamak için oluşturulmuş fonksiyon.
void	ft_env_struct(char *env_arg)
{
	t_env	*new;
	t_env	*temp;
	int		i;

	new = (t_env *)malloc(sizeof(t_env));  // yeni node alanı.
	new->data = ft_split(env_arg, '=');  //data 2 boyutlu bir array olduğunda dolayı split ile 0. indexe PWD,OLDPWD,HOME argümanlar atanır. 1.index'e uzantıları atanır.
	new->next = NULL;
	if (new->data[2] != NULL) // kendi içerisinde "=" durumları olan argümanları ekleyebilmek için özel durum oluşturdum.
	{
		i = 1;
		while (new->data[++i] != NULL)
			new->data[1] = ft_strjoin(ft_strjoin(new->data[1], "="), new->data[i]);
		new->data[2] = NULL;
	}
	if (g_main.env == NULL) // ilk durumda değer atamak için yapıyoruz.
	{
		g_main.env = new;
		g_main.env->next = NULL;
	}
	else
	{
		temp = g_main.env; //main->env listesinin sabit kalmasını istediğimizden dolayı yedek liste oluşturup eşitliyoruz.
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

//env_name PWD,HOME,OLDPWD... argümanları tutmaktadır. if koşulu ile data[0] stringi strcmp ile karşılaştırılır ve eşit ise 0 döner.
char	*ft_env_findret(char *env_name)
{
	t_env	*tmp;

	tmp = g_main.env;
	while (tmp != NULL)
	{
		if (ft_strcmp_edited(env_name, tmp->data[0]) == 0)
			return (tmp->data[1]);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*ft_directory_name(char *path)
{
	char	*name;
	int		i;
	int		l;

	i = ft_strlen(path);
	l = i;
	if (i == 1)
		return ("/");
	while (path[i] != '/')
		i--;
	return (&path[++i]);
}

char	*ft_terminal_print(void)
{
	char	*name;
	char	*tmp;

	name = ft_directory_name(ft_env_findret("PWD"));
	tmp = ft_strjoin(GREEN"➟ "BLKB, name);
	name = ft_strjoin(tmp, " $ "END);
	free(tmp);
	return (name);
}

void	ft_detec(int sig)
{
	if (sig == 2)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_main.echo_val = 130;
	}
	else if (sig == 3)
		printf("%s", "\n");
}

void	ft_login_print(void)
{
	char	*name;

	name = ft_env_findret("NAME");
	if (name == NULL)
		name = "42kocaeli.com.tr";
	printf(GREEN"\nLOGIN INFORMATION: "RED"%s%s%s\n"END,\
		 ft_env_findret("LOGNAME"), "@" , name);
	printf("%s\n", GREEN"                _           _          "RED
	"__  __  ______  __      __ ");
	printf("%s\n", GREEN"   ____ ___    (_) ____    (_) "BLACK"_____  "RED
	"/ / / / / ____/ / /     / / ");
	printf("%s\n", GREEN"  / __ `__ \\  / / / __ \\  / / "BLACK"/ ___/ "RED
	"/ /_/ / / __/   / /     / /  ");
	printf("%s\n", GREEN" / / / / / / / / / / / / / / "BLACK"(__  ) "RED
	"/ __  / / /___  / /___  / /___");
	printf("%s\n", GREEN"/_/ /_/ /_/ /_/ /_/ /_/ /_/ "BLACK"/____/ "RED
	"/_/ /_/ /_____/ /_____/ /_____/"END);
	printf("\n");
}

/**
 * env argümanları tek tek çağırılıp, listeye aktarılacak.
 * getenv("PATH"); gibi çağırılacak.
 */
void	ft_set_argument(void)
{
	extern char	**environ;
	int			i;
	
	g_main.environ = environ;
	g_main.env = NULL;  // Listeyi yeni oluşturduğumuzdan dolayı NULL'a eşitlemeliyiz.
	i = -1;
	while (g_main.environ[++i])
		ft_env_struct(g_main.environ[i]);
	g_main.PATH = ft_split(ft_env_findret("PATH"), ':'); //env içerisinde bulunan PATH'i ':' işareti ile böldük.
	g_main.echo_val = 0; //Progamı başarılı bir şekilde başlattığını varsayarak değeri 0 olmalıdır :)
	ft_login_print();
}


// komut satırına sadece <enter> veya "    " <enter> girdilerinin history kayıt edilmesini önlemek için.
// static olma durumu; sürekli olarak girilen(arka arkaya) komutun hafızaya alınmasına engel oluyor.
static int	ft_history_empty_check(char *str)
{
	static char	*last_entry;
	int			i;
	int			l;

	if (ft_strcmp_edited(str, last_entry) == 0) // arka arkaya girdiyi engelliyor
		return (0);
	free(last_entry); //yeni girdiyi hafıza almadan önce, 2 adım önce girilen girdinin hafızadan temizlenmesi gerekiyor.
	last_entry = ft_strdup(str);
	l = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			l++;
		i++;
	}
	//free(last_entry);
	if (i == l)
		return (0);
	return (1);
}

int		ft_env_echo(char *str)
{
	t_env	*tmp;

	tmp = g_main.env;
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

void	ft_echo_print(int word)
{
	int	i;
	int	k;

	i = word;
	k = 1;
	while (ft_strncmp_edited(g_main.array_line[i], "-n", 2)) //echo -n -n -n -n ahmet karaca <enter> durumunda "-n" fonk./opsiyonunu atlamak için.
	{
		i++;
		k = 0;
	}
	if (g_main.array_line[i] == NULL) //echo -n <enter> durumu için kaçış görevi görüyor.
		printf("%s", "\0");
	else
	{
		while (g_main.array_line[i + 1])
			printf("%s ", g_main.array_line[i++]);
		printf("%s", g_main.array_line[i]);
		if (k == 1)
			printf("\n");
		else
			printf(SELECTED"%%"END"\n");
	}
}

//echo $(ls) <enter> fonk. için hazırlık yapılmalıdır.
void	ft_echo_command(void)
{
	int	i;

	if (g_main.array_line[1] == NULL) //echo <enter>
		printf("\n");
	else if (g_main.array_line[1][0] == '$') // echo $? <enter> || echo $USER <enter> // 2.argümanın 0.indexinde $ işareti kontrolü
	{
		//echo $? <enter>, son komut başarılı çalıştıysa 0, hata döndürdüyse 127, komut çalıştıysa ama işlem yapamıyorsa (örn: cd minishell.c) 1 değerini döndürecektir.
		// control -C sonrasın 130 değerini döndürür. <enter> girdisi sağlamak komut olarak algılanmaz. Bu yüzden bir önceki komutun değeri tutulur.
		if (ft_strncmp_edited(g_main.array_line[1], "$?", 2)) // bir önceki komut TRUE ise 0, FALSE ise 1 dönecektir.
			printf("%d\n", g_main.echo_val);
		else if (!ft_env_echo(&g_main.array_line[1][1])) //&g_main.array_line[1][1] durumu, 1 indexten itibaren argümanın geri kalanını döndürüyor.
			printf("\n");
	}
	else
		ft_echo_print(1); //echo ahmet karaca ... <enter> ||  //echo -n ... <enter> argümanlı, \n olmadan yazdırmak için kullanılıyor.
	g_main.echo_val = 0;
}

//list yapısındaki min stringi döndürüyor.
char	*ft_find_min_str(void)
{
	t_env	*tmp;
	char	*min;

	tmp = g_main.env;
	min = tmp->data[0];
	while (tmp != NULL)
	{
		if (ft_strcmp_edited(min, tmp->data[0]) > 0)
			min = tmp->data[0];
		tmp = tmp->next;
	}
	return (min);
}

//list yapısındaki en büyük stringin bir öncekini bulmaya yarıyor, max stringide döndürülebilir (değişken durumda)
char	*ft_find_max_str(void)
{
	t_env	*tmp;
	char	*max;
	//char	*max_before;

	tmp = g_main.env;
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

void	ft_export_print(void)
{
	t_env	*tmp_down;
	char	*str;
	char	*print;
	int		i;

	i = ft_lstsize(g_main.env);//export yazınca _ data'sı yazdırılmak istenmez ise -1 koyulur. ????
	print = ft_find_min_str(); //env argümanındaki min stringi buluyor.
	while (i-- > 0)
	{
		str = ft_env_findret(print); //program dışında b=(null) argüman girdisi olduğu zaman, export yazdırma işlemindede null olarak görüyor, bunu engellemek için.
		if (str == NULL)
			str = ""; // null yerine boş string atıyoruz.
		if (ft_strcmp_edited(print, "_")) // _= argümanı export çıktısında bulunmuyor.
			printf("declare -x %s=%c%s%c\n", print, '"', str, '"'); //bash'de export yazınca declare -x bilgisi bulunuyor ve argüman değerleri tırnak içerisinde.
		str = ft_find_max_str(); //env argümanındaki max stringi döndürüyor.
		tmp_down = g_main.env;
		while (tmp_down != NULL)
		{
			//printf("str: %s print: %s data: %s\n", str, print, tmp_down->data[0]);
			if (ft_strcmp_edited(print, tmp_down->data[0]) < 0 && ft_strcmp_edited(str, tmp_down->data[0]) > 0) // "> 0" en küçük argümanı çekiyor, "< 0" en büyük argümanı çekiyor. ???
				str = tmp_down->data[0];
			tmp_down = tmp_down->next;
		}
		print = str;
	}
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
int	ft_export_same_check(char *str)
{
	t_env	*check;
	char	**data;
	int		l;

	l = ft_chr_is_there(str, '=');
	data = ft_split(str, '=');
	check = g_main.env;
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
void	ft_export_add(void)
{
	t_env	*tmp;
	t_env	*new;
	int		i;

	i = 1;
	while (g_main.array_line[i])
	{
		if (ft_export_same_check(g_main.array_line[i]))
		{
			new = (t_env *)malloc(sizeof(t_env));
			new->data = ft_split(g_main.array_line[i], '='); //ABC=DEF'argümanı eşittirden(=) sonra farklı indexlere atanır.
			if (new->data[1] == NULL)
				new->data[1] = ""; //girilen argümanın değeri girilmediyse tırnak içerisinde gözükmelidir.
			tmp = g_main.env;
			while (tmp->next->next != NULL)
				tmp = tmp->next;
			new->next = tmp->next;
			tmp->next = new;
		}
		i++;
	}
}


// export edilen argümanın, tanımlayıcı isminde .(nokta) veya /(backslah) varlık yokluk kontrolü yapılıyor.
int	ft_dot_backslah_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=') // export AAAA=BBBB <enter> AAAA girdisinin ='ne kadar kontrol gerçekleştiriyor. // export CCC <enter> girdisi varsa satır sonuna kadar kontrol ediyor.
	{
		if (str[i] == '/' ||str[i] == '.') // ='den önce nokta veya ters eğik çizgi var ise hatalı argüman girdisi olarak sayılıyor.
			return (1);
		i++;
	}
	return (0);
}

int	ft_export_argument_check(char **str)
{
	int	i;
	int	l;
	int	k;

	i = 1;
	k = 1;
	while (str[i])
	{
		l = 0;
		while (str[i][l])
		{
			if (l == 0 && (str[i][l] == '=' || ft_dot_backslah_check(str[i]))) // export =AAAA <enter> argüman girişi hatalı bir girdidir, NULL değeri bir şey tutamaz. || export karac.a=sadada =p ./asda=131231
			{
				ft_exit(3, "export: '", str[i], "': not a valid identifier\n");
				k = 0;
				g_main.echo_val = 1;
			}
			l++;
		}
		i++;
	}
	return (k);
}

void	ft_export_command(void)
{
	g_main.echo_val = 0;
	// Girdisi yapılan argümanın tekrar girdisi oluyor, hatalı, sadece değeri değiştirilsin. ✓
	// export __CF son argümanı yazmıyor. ✓
	// export aaaa=aaaa yazınca export komutunda kayboluyor. ✓
	// export ABCD=DEFG LKG=OOO atamasının 1.atamasını görüyor. 2. ve daha sonrakiler atanmıyor düzelt. ✓
	// export BBBB yazınca export komutunda (null) gözüküyor. ' ' şeklinde gözükmeli. ✓
	// boş argüman ataması yapılan (BBBB), env listesinde gözükmemeli yani sağ tarafı null olan ekrana bastırılmamalıdır. ✓
	// export =KKK yazınca "zsh: KKKK not found" hatası çıkmalı. ve env ve exportta ataması yapılıyor engelle.KKK=NULL olarak. ✓
	// export çıktısı argüman eşitliği " " tırnak içerisinde olacak ✓
	if (g_main.array_line[1] == NULL)
		ft_export_print(); // export <enter> ile env listesinin alfabetik sıralanışı çıkıyor.
	//else if (g_main.array_line[1][0] == '=' || ft_dot_backslah_check(g_main.array_line[1])) 
	//		ft_exit(3, "export: '", g_main.array_line[1], "': not a valid identifier\n");
	else if (ft_export_argument_check(g_main.array_line)) //birden fazla argüman girişinde, hatalı argüman var ise, hangilerinin hatalı olduğu döndürülüyor ve işleme devam etmiyor.
		ft_export_add(); // export ..=... <enter> ile env listesine argüman uzantısı eklenmiş olunuyor.
}

void	ft_env_command(void)
{
	t_env	*tmp;

	tmp = g_main.env;
	while (tmp != NULL)
	{
		if (tmp->data[1] == NULL) //program dışında export ile boş argüman ataması yapıldıysa segmantation fault almamak için argüman kontrolü yapılmalıdır.
			tmp->data[1] = ""; //b=(null)'durumunu engellemek için, boş string atıyoruz.
		if (ft_strcmp_edited(tmp->data[1], "") != 0) //env komutunda boş argümanların yazılması istenilmiyor.
			printf("%s=%s\n", tmp->data[0], tmp->data[1]);
		tmp = tmp->next;
	}
	g_main.echo_val = 0;
}

void	ft_unset_command(void) //(unset A B C) birden fazla argümanlı çalışıyor.
{
	t_env	*tmp;
	t_env	*before;
	t_env	*del;
	//int		i;
	int		l;

	l = 0;
	while (g_main.array_line[++l] != NULL) // unset A B C, argümanları sırasıyla işleme sokulacak.
	{
		tmp = g_main.env;
		tmp->prev = NULL; //tmp'nin bir önceki argümanı olmadığından dolayı NULL' eşitlenir.
		while (tmp != NULL && g_main.array_line[l] != NULL)
		{
			//i = -1;
			//printf("line: %s data: %s\n", main->line[l], tmp->data[0]);
			if (ft_strcmp_edited(g_main.array_line[l], tmp->data[0]) == 0)
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
	g_main.echo_val = 0;
}



//env satırında değiştirilmesi istenilen argüman aranıyor ve str argümanına 1.indexi eşitleniyor.
void	ft_set_env(char *env_name, char *new_str)
{
	t_env	*tmp;
	int		exit;

	exit = 0;
	tmp = g_main.env;
	while (tmp != NULL && exit == 0)
	{
		if (ft_strcmp_edited(env_name, tmp->data[0]) == 0)
		{
			tmp->data[1] = new_str;
			exit = 1;
		}
		tmp = tmp->next;
	}
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

// path'in en sonundaki /'a kadar eşitler.
char	*ft_delete_back_backslah(char *str)
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

// cd source <enter>'i path'e dahil edebilmek için başına "/" koyar, root dizini ise koymaz. // cd source/////// <enter> durumunu engellemek için sondaki "/" siler.
char	*ft_clear_backslah(char *str)
{
	char	*tmp;
	int		i;
	int		l;

	l = 0;
	i = 0;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(str));
	if (!tmp)
		return (NULL);
	if (!ft_strncmp_edited(ft_env_findret("PWD"), "/", 1)) // root dizini olup olmadığı kontrol ediliyor, değilse "/" koyuluyor.
		tmp[l++] = '/';
	while (l <= ft_strlen(str) && str[i] != '/')
		tmp[l++] = str[i++];
	tmp[l] = '\0';
	return (tmp);
}


// cd /////usr <enter> girdisini, cd /usr olarak düzeltiyor. || cd ///// <enter> girdisini, cd / <enter> olarak düzeltiyor.
// cd ////usr////bin <enter> girdisini -> /usr////bin olarak döndürüyor, hatalı.
char	*ft_cd_backslah(char *str)
{
	int		i;
	int		l;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * ft_strlen(str)); // malloc problemi olabilir, gereğinden fazla yer açtım.
	if (!tmp)
		return (NULL);
	i = 0;
	l = 0;
	while (str[i] == '/') // cd ///// <enter> durumunda tek bir '/' koyabilmek için saydırıyoruz.
		i++;
	if (str[i] == '\0') // eğerki satır sonuna denk geliyorsa '/' işareti koyup l indexini arttırıyoruz.
		tmp[l++] = '/';
	while (str[i]) // satır sonu durumu söz konusu değilse string saydırma işlemi devam ediyor.
	{
		if (str[i - 1] == '/' && str[i] != '\0') // bir önceki index '/' ise ve şimdiki index satır sonu değilse '/' koy, bunun nedeni '/usr/bin/' gibi uzantı almamak içindir, sondaki backslahı görmezden gelmek amaçtır.
			tmp[l++] = '/';
		tmp[l++] = str[i++];
		while (str[i] == '/')
			i++;
	}
	tmp[l] = '\0';
	return (tmp);
}

void	ft_cd_command(void)
{
	g_main.echo_val = 0;
	if (g_main.array_line[1] == NULL || ft_strncmp_edited(g_main.array_line[1], "~", 1) || ft_strncmp_edited(g_main.array_line[1], "--", 2)) // cd <enter> || cd ~ <enter> || cd -- <enter> -> "/home/akaraca" dizinine gidiyor.
	{
		ft_set_env("OLDPWD", ft_env_findret("PWD"));
		ft_set_env("PWD", ft_env_findret("HOME"));
		chdir(ft_env_findret("HOME")); // "HOME" sistemdeki ana dizini bulmayı sağlıyor.
	}
	else if (ft_strncmp_edited(g_main.array_line[1], "-", 1)) // cd - <enter>
	{
		g_main.tmp_str = ft_env_findret("OLDPWD");
		ft_set_env("OLDPWD", ft_env_findret("PWD"));
		ft_set_env("PWD", g_main.tmp_str); // pwd komutunun çalışabilmesi için list env'sinin yenilenmesi gerekiyor.
		chdir(g_main.tmp_str); // OLDPWD'ye geçişi sağlıyor. // cd - <enter> ile bir önceki dizine geçişi, ardından cd - <enter> ile tekrardan bir önceki diziye geçiş sağlıyor, kısaca rec. bir işlem.
		printf("%s\n", g_main.tmp_str); // cd - <enter> komutu ile geçilen dizi çıktısı veriliyor.
	}
	else if (g_main.array_line[1] != NULL && ft_directory_search(g_main.array_line[1])) //cd .. <enter> || cd Desktop <enter> // bulunamadı durumu için dosya arama fonk. gerekiyor.
	{
		/// !!! "cd // <enter>" || "cd /// <enter>" durumunda dizin hatalı oluyor. -> her türlü root dizinine gitmesi gerekiyor. ✓
		/// !!! "cd . <enter>" durumunda /mnt/c/././. path oluşuyor. ✓
		ft_set_env("OLDPWD", ft_env_findret("PWD"));
		if (ft_strncmp_edited(g_main.array_line[1], "..", 2))
			ft_set_env("PWD", ft_delete_back_backslah(ft_env_findret("PWD"))); // path'in en sonundaki /'a kadar eşitler.
		else if (g_main.array_line[1][0] == '/') // cd / <enter> || cd /// <enter> || cd /usr <enter> durumu için birinci argüman kontolü yapılıyor. // cd / <enter> ile root dizinine erişim sağlamak için kullanılıyor.
			ft_set_env("PWD", ft_cd_backslah(g_main.array_line[1])); //ft_cd_backslah(), şu değerleri döndürüyor: /////usr -> /usr, /////// -> /, değerlerini döndürüyor. Kısaca başında yer alan birden fazla /'ı atlıyor.
		else if (!ft_strncmp_edited(g_main.array_line[1], ".", 1)) // cd . <enter> girdisi ile aynı pathe erişim gerekmediği anlamına gelmez bu yüzden oldpath değişmelidir(kısaca oldpath, path olacak). // ! durumu, buraya girip pathın sonuna "soruce/." eklenmemesi içindir.
		{
			g_main.tmp_str = ft_clear_backslah(g_main.array_line[1]); // cd source <enter>'i path'e dahil edebilmek için başına "/" koyar, root dizini ise koymaz. // cd source/////// <enter> durumunu engellemek için sondaki "/" siler.
			ft_set_env("PWD", ft_strjoin(ft_env_findret("PWD"), g_main.tmp_str));
		}
		chdir(ft_env_findret("PWD"));
	}
	else if (ft_file_search(g_main.array_line[1])) // cd 1.c <enter>, dizin içerisinde bulunan bir argümana directory olarak erişim olduğunda hata veriyor.
	{
		ft_exit(5, "cd: ", g_main.array_line[1], ": Not a directory\n");
		g_main.echo_val = 1;
	}
	else
	{
		ft_exit(2, "cd: ", g_main.array_line[1], ": No such file or directory\n"); // dizin içerisinde aranan argüman bulunmadığı zaman buraya girmesi gerekiyor.
		g_main.echo_val = 1;
	}
}

// ilk iki indexi "./" olmalıdır, son "/" 'dan sonrası çalıştırılması gereken dosyayı temsil etmektedir.
int	ft_search_and_launch(void)
{
	if (ft_strncmp(g_main.array_line[0], "./", 2))
		return (0);
	if (!ft_file_search(g_main.array_line[0]))
		return (0);
	return (1);
}

//girilen diğer komutların clear, ls, ls -la, man ... vb çalıştırılmasını sağlıyor.
int	ft_command_path(void) //leak durumu düzeltildi, düzene çekilmeli 
{
	int		i;
	char	*dir;
	char	*dir_2;

	i = -1;
	while (g_main.PATH[++i])
	{
		dir_2 = ft_strjoin("/", g_main.array_line[0]);
		dir = ft_strjoin(g_main.PATH[i], dir_2);
		free(dir_2);
		if (access(dir, 0) == 0) //access komut kontrolü yapıyor.
		{
			g_main.command_path = dir;
			return (1);
		}
		free(dir);
	}
	return (0);
}

void	ft_command_find(void)
{
	g_main.array_line = ft_split(g_main.input_line, ' '); //girdi argümanlarını içericek.
	if (g_main.array_line[0] == NULL) // <enter>
		printf("%s","\0");
	else if (ft_strncmp_edited(g_main.array_line[0], "echo", 4)) // echo ... <enter>
		ft_echo_command();
	else if (ft_strncmp_edited(g_main.array_line[0], "cd", 2)) // cd ... <enter>
		ft_cd_command();
	else if (ft_strncmp_edited(g_main.array_line[0], "pwd", 3)) // pwd <enter>
	{
		printf("%s\n", ft_env_findret("PWD"));
		g_main.echo_val = 0;
	}
	else if (ft_strncmp_edited(g_main.array_line[0], "unset", 5)) // export ile yapılan atama "unset ev" şeklinde kaldırılabiliniyor.
		ft_unset_command();
	else if (ft_strncmp_edited(g_main.array_line[0], "export", 6)) // "export ev=/mnt/c/Users/ViTT/Desktop" ataması env içerisine yapılabiliniyor. // export <enter> env'nin sıralanmış halini yazdırıyor. // env kendi içerisinde sıralanacak, export argümanları kendi içerisinde sıralanacak.
		ft_export_command();
	else if (ft_strncmp_edited(g_main.array_line[0], "env", 3)) // env <enter>
		ft_env_command();
	else if (ft_strncmp_edited(g_main.array_line[0], "exit", 4)) // exit <enter>
		ft_exit(-1, "exit\n", "\0", "\0");
	else if (ft_search_and_launch()) //dosya arama ve çalıştırma işlemini gerçekleştiriyor.
	{
		if (ft_directory_search(g_main.array_line[0])) // "./sources <enter>" girdisi olur ve program isim girdisi olmaz ve son "/"'den sonrası dizin ise hata döndürür.
		{
			ft_exit(4, g_main.array_line[0], ": Is a directory\n", "\0");
			g_main.echo_val = 1;
		}
		else
		{
			// "./sources/a.out" "./a.out" "../a.out" "./sources/.././a.out" "./sources/././a.out"
			int pi = fork();
			if (pi == 0)
				g_main.echo_val = execve(g_main.array_line[0], g_main.array_line, g_main.environ);
			wait(&g_main.echo_val); //değerin eşitlenmesini bekliyor.
			waitpid(pi, 0, 0);
		}
	}
	else if (ft_command_path()) //komutları path'te arama ve çalıştırma işlemini yapıyor.
	{
		int pi = fork(); //execve işlemi sonrasında sonlandırma yaptığından dolayı bu işlemi alt proseslerde yapıyoruz.
		if (pi == 0)
		{	
			//printf("| path: %s, line[0]: %s, line[1]: %s, line[2]: %s |\n", g_main.command_path, g_main.array_line[0], g_main.array_line[1], g_main.array_line[2]);
			g_main.echo_val = execve(g_main.command_path, g_main.array_line, g_main.environ);
			//execve(const char *filename, char *const argv[], char *const envp[]);
		}
		wait(&g_main.echo_val); //değerin eşitlenmesini bekliyor.
		waitpid(pi, 0, 0);
		free(g_main.command_path);
	}
	else
	{
		ft_exit(0, g_main.array_line[0], ": command not found\n", "\0");
		g_main.echo_val = 127;
	}
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
	> $? bir önceki komut TRUE ise 0, FALSE ise 1 dönecektir. ✓
	> Bash'deki gibi davranması gereken ctrl-C, ctrl-D ve ctrl-\'yi kullanın. ✓

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
int main(void)
{
	//printf("\e[1;1H\e[2J"); // Derleme sonrasında önceki girdileri silmeye yarıyor.
	ft_set_argument();
	while (1)
	{
		signal(SIGINT, ft_detec); // control-C signal, yeni bir satıra geçiş yapmalı.
		signal(SIGQUIT, ft_detec); // "control-\" , ingilizce klavyeye alıp(mac klavye) "control-," ile çalışıyor.
		g_main.terminal_name = ft_terminal_print();
		g_main.input_line = readline(g_main.terminal_name);  // terminal adının silinmemesi için " " girilmesi gerekiyor, NULL durumunda siliyor. 
		if (!g_main.input_line) //control-D tuş kombinasyonu ile terminal kapatılmalı.
			ft_exit(-1, "exit\n", "\0", "\0");
		if (ft_history_empty_check(g_main.input_line)) // boş girilen satırları atlamak için. // arda arda giriş gerçekleşmiş ise yok sayılıyor.
			add_history(g_main.input_line);
		ft_command_find();
		free(g_main.input_line);
		free(g_main.terminal_name);
		ft_free(g_main.array_line);
		//system("leaks a.out");
	}
	return (0);
}

// . <enter> girdisi sonucunda yeni fork girdisi oluşuyor. //forklarla alaklı
// cd .. <enter>'ın ardından cd source girdisi olunca malloc hatası dönüyor. (ft_free() fonk. geçerliyken.) //cd ile alakalı