#include <pthread.h>
#include <stdio.h>

int x = 0;
pthread_mutex_t mutex;

void *rutin()
{
	int i = 0;
	int y = 0;
	while (i < 10)
	{
		pthread_mutex_lock(&mutex);
		//printf("y: %d\n", y);
		i++;
		x++;
		pthread_mutex_unlock(&mutex);
	}
	printf("Finito-Emanuel\n");
	return(0);
}

int main(int argc, char **argv)
{
	int y = 3;
	pthread_t th[y];
	int i = 0;
	//pthread_t t1, t2, t3, t4;
	pthread_mutex_init(&mutex, NULL);
	while(i < y)
	{
		if (pthread_create(&th[i], NULL, &rutin, NULL))
		{
			perror("Failed to crate thread");
			return (1);
		}
		printf("Thread numarası Start: %d\n", i);
		//if (pthread_join(th[i], NULL) != 0)
		//	return (2);
		//printf("Thread numarası Finish: %d\n", i);
		i++;
	}
	
	i = 0;
	while(i < y)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (2);
		printf("Thread numarası Finish: %d\n", i);
		i++;
	}
	/*
	pthread_create(&t1, NULL, &rutin, NULL);
	pthread_create(&t2, NULL, &rutin, NULL);
	pthread_create(&t3, NULL, &rutin, NULL);
	pthread_create(&t4, NULL, &rutin, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	*/
	pthread_mutex_destroy(&mutex);
	printf("x: %d\n", x);
	return (0);
}