#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;
int x = 0;

void *rutin()
{
	int i = 0;
	printf("1\n");
	while (i < 10000)
	{
		pthread_mutex_lock(&mutex);
		i++;
		x++;
	}
	pthread_mutex_unlock(&mutex);
	return (0);
}

int main()
{
	pthread_t th[4];

	pthread_mutex_init(&mutex, NULL);
	for (int i = 0; i < 4; i++)
	{
		pthread_create(&th[i], NULL, &rutin, NULL);
	}
	for (int i = 0; i < 4; i++)
	{
		pthread_join(th[i], NULL);
	}
	printf(":: %d\n", x);
	return (0);
}