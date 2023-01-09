#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#define THREAD_NUM 3

void	*rutin(){
	sleep(1);
	printf("Finito\n");
	return (0);
}


int main()
{
	pthread_t th[THREAD_NUM];
	int i;
	for (i = 0; i < THREAD_NUM; i++)
	{
		
		if (pthread_create(&th[i], NULL, &rutin, NULL) != 0)
			perror("Failed to crate thread");
		printf("%d\n", i);
	}
	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
	pthread_detach(th[2]);
	return (0);
}