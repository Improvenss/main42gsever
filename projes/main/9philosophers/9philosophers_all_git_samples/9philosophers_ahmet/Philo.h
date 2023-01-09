#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct p_list
{
	int name;
}t_p_list;

typedef struct s_list
{
	int	name;
	pthread_mutex_t	philo;
	pthread_mutex_t	forks;
	t_p_list	p;
}t_list;


int main(int argc, char **argv);

#endif