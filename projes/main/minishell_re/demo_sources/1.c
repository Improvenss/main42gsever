# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <stdarg.h>

/*char *args[] = { "./a.out", <other arguments>, NULL };
			execve("a.out", args, NULL);*/


int main(int argc, char **argv)
{
	printf("---> | 0:%s 1:%s 2:%s|\n", argv[0], argv[1], argv[2]);
	//extern char **environ;

      //char *args[] = { "minishell", NULL, NULL};
	//		execve("minishell", NULL, environ);


//char *argv[] = {"ahmet", "karaca", "42", NULL};
			//execve("a.out", argv, main->tmp_environ);
}

/*
int main(int argc, char **argv)
{

	Integer value   Name
       0        Standard input (stdin)
       1        Standard output (stdout)
       2        Standard error (stderr)

	char ch;

	while (read(0, &ch, 1) > 0){

	}
	char c;
	int flag=0;
	printf("- ");

while (flag != EOF) {
    flag = scanf(" %c", &c);
    printf("- ");
	}
	return 0;
}*/