/*
** xfunc.c for  in /u/all/sundas_c/cu/rendu/c/philo1
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar 29 15:51:06 2009 christophe sundas
** Last update Sun Mar 29 15:51:07 2009 christophe sundas
*/
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "philo.h"

void	*xmalloc(size_t size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    exit(EXIT_FAILURE);
  return (ptr);
}

void	xpthread_mutex_init(void *ptr)
{
  int	r;

  r = pthread_mutex_init(ptr, NULL);
  if (r != 0)
    {
      perror("pthread_mutex_init failed");
      exit(EXIT_FAILURE);
    }
}

void	xpthread_create(pthread_t * th, void *(*routine)(void *), void *arg)
{
  int	r;

  r = pthread_create(th, NULL, routine, arg);
  if (r != 0)
    {
      perror("error pthread create");
      exit(EXIT_FAILURE);
    }
}

void    xpthread_mutex_destroy(pthread_mutex_t *mutex)
{
  int	r;

  r = pthread_mutex_destroy(mutex);
  if (r != 0)
    {
      perror("error pthread destroy");
    }
}

void	xpthread_join(pthread_t thread)
{
  int	r;

  r = pthread_join(thread, NULL);
  if (r != 0)
    {
      perror("error pthread destroy");
      exit(EXIT_FAILURE);
    }
}
