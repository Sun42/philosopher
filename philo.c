/*
** philo.c for  in /u/all/sundas_c/cu/rendu/c/philo1
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar 29 15:50:24 2009 christophe sundas
** Last update Sun Mar 29 15:53:08 2009 christophe sundas
*/
#include <signal.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "philo.h"

int	main(int ac, char **av)
{
  int	pizza;
  int	nb_astek;

  if (signal(SIGINT, activ) == SIG_ERR)
    exit(EXIT_FAILURE);
  pizza = parse_arg_pizza(ac, av);
  nb_astek = parse_arg_astek(ac, av);
  start_game(pizza, nb_astek);
  pthread_exit(NULL);
  return (EXIT_SUCCESS);
}

int				end_game(int n)
{
  static volatile sig_atomic_t	end;

  if (n == 1)
    end = n;
  return (end);
}

void	activ(int n)
{
  if (signal(n, activ) == SIG_ERR)
    exit(EXIT_FAILURE);
  end_game(1);
}

void			start_game(int nbpizza, int nb_astek)
{
  pthread_t		threads[NB_ASTEK];
  t_astek		**astek;
  pthread_mutex_t	mutex_pizza;
  int			i;

  astek = init_astek(&nbpizza, (void *)&mutex_pizza, nb_astek);
  xpthread_mutex_init((void *)&mutex_pizza);
  i = 0;
  while (i < nb_astek)
    {
      astek[i]->sum_pizza = nbpizza;
      astek[i]->nb_astek = nb_astek;
      xpthread_create(&threads[i], my_thread, (void *)astek[i]);
      i++;
    }
  xjoin(threads, nb_astek);
  show_res(astek);
  xpthread_mutex_destroy(&mutex_pizza);
  free(astek[0]->left);
  xfree(astek, nb_astek);
  free(astek);
}

t_astek			**init_astek(int *pizza, void *mutex_pizza, int nb_astek)
{
  int			i;
  pthread_mutex_t	*mut_stick;
  t_astek		**astek;

  astek = xmalloc(sizeof(*astek) * nb_astek);
  mut_stick = xmalloc(sizeof(*mut_stick) * nb_astek);
  i = 0;
  while (i < nb_astek)
    {
      astek[i] = xmalloc(sizeof(*astek[i]));
      xpthread_mutex_init((void *)&mut_stick[i]);
      astek[i]->left = mut_stick + i;
      if (i == 0)
	astek[i]->right = mut_stick + nb_astek - 1;
      else
	astek[i]->right = mut_stick + i - 1;
      astek[i]->pizza = pizza;
      astek[i]->mutex_pizza = mutex_pizza;
      astek[i]->nb_eat = 0;
      astek[i]->id = i;
      i++;
    }
  return (astek);
}
