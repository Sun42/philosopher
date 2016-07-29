/*
** state_astek.c for  in /u/all/sundas_c/cu/rendu/c/philo1
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar 29 15:50:39 2009 christophe sundas
** Last update Sun Mar 29 15:50:39 2009 christophe sundas
*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "philo.h"

int	usleep(useconds_t useconds);

void		*my_thread(void *data)
{
  t_astek	*astek;
  int		avg;

  astek = (t_astek *)data;
  while (nb_pizza(astek) > 0)
    {
      if (end_game(0))
	break ;
      avg = (astek->sum_pizza - nb_pizza(astek)) / astek->nb_astek;
      if (avg < astek->nb_eat)
        {
          put_astek(astek, "prend une penalite.");
	  xusleep(astek->nb_astek * 500);
	  continue ;
        }
      resting(astek);
    }
  pthread_exit(NULL);
}

void	*get_stick(t_astek *astek, int mode)
{
  if (astek->id % 2 == mode)
    return (astek->right);
  return (astek->left);
}

void	resting(t_astek *astek)
{
  put_astek(astek, "se repose.");
  xpthread_mutex_lock(get_stick(astek, REST));
  thinking(astek);
}

void	thinking(t_astek *astek)
{
  int	limit;

  put_astek(astek, "reflechit ...");
  limit = 0;
  while (pthread_mutex_trylock(get_stick(astek, THINK)) != 0)
    {
      usleep(100);
      limit++;
      if (limit > LIMIT_DIE)
        die(astek);
    }
  eating(astek);
}

void	eating(t_astek *astek)
{
  xpthread_mutex_lock(astek->mutex_pizza);
  if (astek->pizza[0] > 0)
    {
      astek->pizza[0]--;
      astek->nb_eat++;
      put_astek(astek, "mange.");
    }
  else
    put_astek(astek, "Putain Mox a encore bouffe toutes les pizzas");
  xpthread_mutex_unlock(astek->mutex_pizza);
  xpthread_mutex_unlock(astek->right);
  xpthread_mutex_unlock(astek->left);
}
