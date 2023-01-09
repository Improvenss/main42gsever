/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:42:56 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/23 11:31:13 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @author Ahmet KARACA (akaraca)
 * @author Gorkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../includes/minishell.h"

int	set_arg(t_base *base, char **environ)
{
	base->cmd = NULL;
	base->lexer = NULL;
	base->env = set_env(environ);
	if (base->env == NULL)
	{
		exit_status(1, 0);
		return (ERROR);
	}
	base->mem_1 = env_findret(base->env, "PATH");
	base->env_path = ft_split(base->mem_1, ':');
	//free(base->mem_1);
	return (0);
}

/**
 * @brief Main.
 * 
 * brew install comands in /goinfre/$USER
 * 
* ************************************************************************** *

				You can use this area in makefile.
						make brew_readline

1. STEP: git clone --depth=1 https://github.com/Homebrew/brew \
/goinfre/$USER/brew \
&& echo 'export PATH=/goinfre/$USER/brew/bin:$PATH' >> $HOME/.zshrc

2. STEP: brew install readline
3. STEP: brew link --force readline
4. STEP: echo 'export C_INCLUDE_PATH="/goinfre/$USER/brew/\
include:$C_INCLUDE_PATH"' >> ~/.zshrc
5. STEP: echo 'export LIBRARY_PATH="/goinfre/$USER/brew/\
lib:$LIBRARY_PATH"' >> ~/.zshrc

* ************************************************************************** *

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
	> Alıntılanan dizideki meta karakterlerin tek tırnak içerisinde
		iken engellenmesi gerekmektedir.
	> Alıntılanan dizideki $ işaretinin argüman çağırması gerektiğini tanıt.

> Uygulanması gerekenler;
	> "< should redirect input" "<" işaretnin işlevini yerine getirin.
	> "> should redirect output" ">" işaretinin işlevini yerine getirin.
	> "<< bir sınırlayıcı verilmeli"
		ardından sınırlayıcıyı içeren bir satır görülene kadar
			girişi okumalısınız.
		Ancak, geçmişi güncellemek zorunda değildir!
	> Boruları (| karakter) uygulayın. Boru hattındaki her komutun çıkışı,
		bir sonraki komutun girişine bir boru aracılığıyla bağlanır.
	> Değerlerine genişlemesi gereken ortam değişkenlerini
		($ ardından bir karakter dizisi) kullanın.
	> $? bir önceki komut TRUE ise 0, FALSE ise 1 dönecektir. ✓
	> Bash'deki gibi davranması gereken ctrl-C,
		ctrl-D ve ctrl-\'yi kullanın. ✓

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
	
> Meanings -> lexer -> parser -> expander -> executor
	LEXER: -> -Tarayici-
Sözcük, anlamsız dizeyi "sayı değişmezi",
 "dize değişmezi", "tanımlayıcı" veya "işleç" gibi düz bir
 listeye dönüştürür ve ayrılmış tanımlayıcıları ("anahtar kelimeler")
 tanımak ve boşlukları atmak gibi şeyler yapabilir.
Bunlara tarayıcısız ayrıştırıcılar denir. Bir lexer(sozluk) ve
 bir parser(ayristirici) sırayla çalışır: sözcü girdiyi tarar
 ve eşleşen simgeleri üretir, ayrıştırıcı daha sonra simgeleri tarar ve
 ayrıştırma sonucunu üretir.
	PARSER: -> -Ayristirici-
Ayrıştırıcı, başka bir dile kolay çeviri için verileri daha küçük öğelere
 ayıran bir derleyici veya yorumlayıcı bileşenidir. Ayrıştırıcı, bir
 dizi belirteç, etkileşimli komutlar veya program talimatları biçiminde
 girdi alır ve bunları diğer bileşenler tarafından programlamada
 kullanılabilecek parçalara ayırır.
				DIFFERENCE - FARKLARI
	Lexer, sözcük analizi yapan bir yazılım programıdır.
 ... Ayrıştırıcı, sözcüden bir düzey daha ileri gider ve sözcü tarafından
 üretilen belirteçleri alır ve uygun tümcelerin oluşturulup oluşturulmadığını
 belirlemeye çalışır. Ayrıştırıcılar dilbilgisi düzeyinde,
 sözlükler sözcük düzeyinde çalışır.
	EXPANDER: -> -Birlestirici-
	EXECUTOR: -> -Calistirici-
 
 * @fn signal(): Klayeden girilen CTRL+C,D,\ sinyallerini kontrol ediyor.
 * @fn env_init(): Program baslatma konumlarini falan hafizasinda tutan
 *  degiskenler.
 * @fn action(): CTRL+*'dan gelen sinyal sonucunda hangi func()
 *  calismasini istedigimiz func().
 * @fn get_input(): readline() ile terminale yazilan girdiyi
 *  string tipinde aldigimiz func().
 * @fn isatty(): Terminal(tty) var mi yok mu onu kontrol ediyor.
 * @fn ft_putendl_fd(): libft-> file descriptor'a istedigimiz str'yi yazar.
 * @fn process_input(): get_input()'tan aldigimiz girdiyi calistiriyoruz.
 * @fn rl_clear_history(): readline kutuphanesi icin gerekli.
 * @fn ft_free_split(): Ozel olarak yazilmis split icin teker teker
 *  free'leme islemi yapiyor.
 * @fn exit(): Exit BRUH.
 * @fn exec_exit_status_get(): return/error degerimiz icin kullaniyoruz,
 *  boylelikle girdi hangi err kodunu donduruyor onu anlayabiliyoruz.
 * 
 * NOTE: malloc() durumlari kontrol edilecek
 * TODO:malloc()
 * 	if (malloc == NULL),
 * TODO: cd'nin leaks'leri giderilecek,
 * TODO: < operatoru olusturulmayan dosya gordugunde hata
 * 	dondurmeli -> islemi durdurmali,
 * TODO: norminette icin ayirma islemi yapilacak,
 * TODO: unset icin leaks var,
 * TODO: cat << $pwd -> $pwd'nin expand edilmemesi gerekiyor, heredoc $pwd argümanı ile kapatılması gerekiyor.
 * TODO: cd $pwd -> $pwd'nin içeriği olmadığından dolayı, sadece cd komutu çalışmalıdır.
 * TODO: export A= giridisi sonrasında random argüman girince patlıyor.
 * TODO: export'taki _= argumanını yazdırmayacagız eklemeyı unutma.
 * @return int 
 */
int	main(int argc __attribute((unused))
	, char **argv __attribute((unused))
	, char **envp)
{
	//t_base	base;

	char *a = ft_strdup("ahmet");
	printf("%s\n", a);
	free(a);
	(void)envp;
//	if (set_arg(&base, envp) != ERROR)
//		printf("---\n");
		//minishell(&base);
	return (exit_status(0, 1));
}
