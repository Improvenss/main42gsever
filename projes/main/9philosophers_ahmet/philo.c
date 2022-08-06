#include "Philo.h"

void	ft_exit(int err)
{
	if (err == 0)
		printf("Hatalı / Eksik Argüman Girişi!\n");
	exit(0);
}

int *ft_atoi(int argc, char **argv)
{
	int *x;
	int i = 0;
	int l = 0;
	int val = 0;
	
	x = (int *)malloc(sizeof(int *) * argc);
	while (argv[i])
	{
		while (argv[i][l])
		{
			if (argv[i][l] < 48 || argv[i][l] > 57)
			{
				free(x);
				ft_exit(0);
			}
			val = val * 10 + (argv[i][l] - 48);
			l++;
		}
		x[i] = val;
		l = 0;
		val = 0;
		i++;
	}
	return (x);
}

void	*assignment()
{
	
	return (0);
}

void	philo_creater(int argv_i, t_list *sub)
{
	int i = 0;
	pthread_t th[argv_i];
	pthread_mutex_init(&sub->philo, NULL);
	while (i < argv_i)
		pthread_create(&th[i], NULL, &assignment, NULL);
	i = 0;
	while (i < argv_i)
		pthread_join(th[i], NULL);

}

/**
 * Bilgilendirme:
 * -> Bir veya daha fazla filozof yuvarlak bir masada oturuyor.
 * 		Masanın ortasında büyük bir kase pirinç var.
 * 
 * -> Filozoflar'ın davranışları; Yemek yer, düşünür veya uyur.
 * 		Yemek yerken ne düşünürler ne de uyurlar.
 * 		Düşünürken yemek yemezler ve uyumazlar.
 * 		Uyurken yemek yemezler ve düşünmezler.
 * 
 * -> Masada çubuklar(forks) bulunuyor ve sayısı filozofların sayısı kadardır.
 * 		Pirinç yemek için 2 çubuğa ihtiyacı olduğundan dolayı, sağ ve sol
 * 			çubukları her elinde birer tane olacak şekilde yer.
 * 
 * -> Filozof yemeğini bitirince çubukları masaya koyar ve uyumaya başlar.
 * 		Uyandıklarında tekrar düşünmeye başlarlar.
 * 		Bir filozof açlıktan öldüğünde simülasyon durur.
 * 
 * Kurallar:
 * -> Her filozof yemek yemelidir ve asla aç kalmamalıdır.
 * -> Filozoflar birbiriyle konuşamazlar.
 * -> Filozoflar başka bir filozofun durumu hakkında bilgiye sahip değildir.
 * -> Amaç filozofları öldürmemektedir.
 * 
 * Proje Kuralları:
 * -> Bonus bölüm için ayrı bir program yazılmalıdır.
 * -> Global değişkenler yasaktır.
 * -> Programların alacağı argümanlar;
 * 		(1)Filozof Sayısı, (2)Ölme Süresi, (3)Yemek Yeme Süresi,
 * 		(4)Uyuma Süresi, (5)Her Filozofun Yemek Yeme Sayısı.
 * 
 * (1) -> Filozofların sayısını ve çubukların(forks) sayısını belirliyor.
 * (2) (milisaniye cinsinden)
 * 	   -> Filozofun, son yemeğinin başlangıcından veya
 * 			simülasyonun başlangıcından bu yana (2) ms
 * 			süre içinde yemek yemeye başlamadıysa, ölürler.
 * (3) (milisaniye cinsinden)
 * 	   -> Filozofun yemek yemek için harcadığı süredir.
 * 			Bu süre dahilinde iki çubuğuda(forks) tutmaları gerekecektir.
 * (4) (milisaniye cinsinden)
 * 	   -> Filozofun uyumak için harcadığı süredir.
 * (5) (isteğe bağlı bir argümandır)
 * 	   -> Tüm filozoflar en az sayıda, (5) kez yemek yemişse simülasyon durur.
 * 			Belirtilmez ise program bir filozof öldüğünde simülasyonu durdurur.
 * 
 * -> Her filozofun numaralandırması vardır;
 * 		Numaralandırma 1'den başlar.
 * 		Son filozof (1) numarasına sahiptir.
 * 		Ara sayılar ile diğer filozoflar numaralandırılır.
 * -> 1 Numaralı filozof, (1) numaralı filozofun yanına oturur.
 * 		(n) numaralı başka herhangi bir filozof,
 * 			(n-1) ile (n+1) filozof arasında oturur.
 * 
 * Programın Günlük Bilgisi: (Terminal Çıktısı)
 * -> Filozofların durum değişiklikleri şu şekilde biçimlendirilir;
 * 		> timestamp_int_ms X has taken a fork
 * 		> timestamp_int_ms X is eating
 * 		> timestamp_int_ms X is sleeping
 * 		> timestamp_int_ms X is thinking
 * 		> timestamp_int_ms X died
 * -> timestamp_int_ms öğesini milisaniye cinsinden geçerli zaman damgasıyla,
 * 		X öğesini filozof numarasıyla değiştirin.
 * 
 * -> Görüntülenen durum mesajı başka bir mesajla karıştırılmamalıdır.
 * -> Bir filozofun öldüğünü bildiren bir mesaj, filozofun gerçek ölümünden
 * 		en fazla 10 ms sonra görüntülenmelidir.
 * -> Program herhangi bir "data races" sahip olmamalıdır.
 * 
 * 
 * Kullanlılabilir Fonksiyonlar:
 * > memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create,
 * 	 pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy,
 * 	 pthread_mutex_lock, pthread_mutex_unlock.
 * 
 * 	>memset, bir bellek bloğunu belirli bir değerle doldurmak için kullanılır.
 * 
 * 	>printf, ekrana biçimlendirilmiş çıktı göndermek için kullanılır.
 * 
 * 	>free, calloc(), malloc(), realloc() işlevleri tarafından
 * 		 tahsis edilen bellek bloklarını serbest bırakmak için kullanılır.
 * 
 * 	>write, arabellekten veri yazmak için kullanılan bir sistem çağrısıdır.
 * 
 * 	>usleep, kendisine belirtilen ms sayısı için geçerli işlemi askıya alan bir
 * 		C API'sidir. Bir işi geciktirmek için kullanılır.
 * 
 * 	>gettimeofday, sistemin saat zamanını alır. Geçerli zaman,
 * 		1 Ocak 1970'den bu yana geçen saniye ve ms cinsinden ifade edilir.
 * 
 * 	>pthread_crate, (Crate a thread) (İplik oluşturma) (iş parçacığı oluşturma)
 * 		Bir işlem içinde "attr" tarafından belirtilen niteliklerle
 * 		yeni bir iş parçacığı oluşturmak için kullanılır. Eğer attr NULL ise
 * 		varsayılan özellik kullanılır. attr tarafından belirtilen nitelik
 * 		daha sonra değiştirilirse, iş parçacığının nitelikleri etkilenmez.
 * 		Attr(Attributes(öznitelikler)), varsayılandan farklı olan davranışı
 * 			 belirtmenin bir yoludur.
 * 
 * 	>pthread_detach, iş parçacığı sona erdiğinde iş parçacığında tahsis edilen
 * 		kaynakların kurtarılabileceğini belirtir.
 * 		İplikler(threads) artık ihtiyaç duyulmadığında ayrılmalıdır.
 * 
 * 	>pthread_join, Hedef evre sona ermedikçe kendisini çağıran evrenin
 * 		yürütülmesini askıya alacaktır.
 * 		Bu, ana iş parçacığında daha fazla işlem yapmadan önce,
 * 		iş parçacıklarının sona ermesini beklemek istediğiniz
 * 		durumlarda kullanışlıdır.
 * 		İş parçacığının sonlandırılmasını beklemenin uygun bir yoludur.
 * 
 * 	>pthread_mutex_init, belirtilen nitekliklere sahip mutex'i başlatır.
 * 		Öznitelik(attr), NULL olarak belirtilirse, mutex için varsayılan
 * 		attr'e göre ayarlanır. Başarılı başlatmanın ardından,
 * 		mutex'in durumu başlatılır ve kilidi açılır.
 * 		Önceden başlatılmış bir mutex'i başlatmaya çalışmak,
 * 		tanımsız davranışa neden olur.
 * 
 * 	>pthread_mutex_destroy, mutex tarafından başvurulan
 * 		mutex nesnesini yok eder; mutex nesnesi aslında başlatılmamış
 * 		hale gelir. Yok edilen bir mutex nesnesi, pthread_mutex_init();
 * 		kullanılarak yeniden başlatılabilir.
 * 		Kilidi açılmış, başlatılmış bir mutex'i yok etmek güvenlidir.
 * 		Kilitli bir mutex'i yok etmeye çalışmak tanımsız davranışa neden olur.
 * 
 * 	>pthread_mutex_lock, verilen mutex'i kilitler.
 * 		Mutex kilitli değilse, kilitlenir, çağıran evre tarafından sahiplenilir
 * 		ve pthread_mutex_lock hemen döner. Eğer mutex zaten başka bir evre
 * 		tarafından kilitlendiyse, pthread_mutex_lock mutexin kilidi açılana
 * 		kadar çağıran evreyi askıya alır.
 * 		Eğer mutex çağıran evre tarafından önceden kilitlenmişse,
 * 		pthread_mutex_lock davranışı mutex türüne bağlıdır.
 * 		Eğer mutex "hızlı" türdeyse, çağıran evre askıya alınır. Sonsuza
 * 		kadar askıda kalır, çünkü başka bir evre mutex'in kilidini açamaz.
 * 		Eğer mutex "özyinelemeli" türdeyse, _lock başarılı olur ve çağıran
 * 		evrenin mutex'i kaç kez kilitlediğini kaydederek hemen döner.
 * 		Mutex'i kilitsiz hale düşürmek için eşit sayıda _unlock işlemi
 * 		uygulanmalıdır.
 * 
 * 	>ptread_mutex_unlock, verilen mutex'in kilidini açar. 
 * 		Eğer mutex "hızlı" türdeyse, kilitsiz duruma döndürür.
 * 		Eğer "özyinelemeli" türdeyse, mutex'in kilit sayısını azaltır(çağıran
 * 		evre tarafından uygulanan _lock işlem sayısı), ve ancak bu sayı
 * 		sıfıra ulaştığından mutex kilidi açılımış olur.
 * 	
 **/
int	main(int argc, char **argv)
{
	int *argv_i;
	int i = 0;
	t_list *sub;

	argc = argc - 1;
	argv++;
	argv_i = ft_atoi(argc, argv);
	while (argv_i[i])
		printf("%d\n", argv_i[i++]);
	if (argc > 3 && argc < 6)
	{
		philo_creater(argv_i[0], sub);
	}
	else
		ft_exit(0);
	printf("\033[0;31m");
	printf("----\n");
	//system("leaks a.out");
	return (0);
}
