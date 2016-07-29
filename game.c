/*
** game.c for  in /u/all/sundas_c/cu/rendu/c/philo1
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar 29 15:49:49 2009 christophe sundas
** Last update Sun Mar 29 15:49:50 2009 christophe sundas
*/
#include <string.h>
#include <stdlib.h>
#include "philo.h"

int	parse_arg_pizza(int ac, char **av)
{
  int	ret;

  ret = -1;
  if (ac > 1 && av[1] != NULL)
    ret = atoi(av[1]);
  if (ret < 2)
    {
      write(2, USAGE, strlen(USAGE));
      exit(EXIT_FAILURE);
    }
  return (ret);
}

int	parse_arg_astek(int ac, char **av)
{
  int	ret;

  ret = -1;
  if (ac > 2 && av[2] != NULL)
    ret = atoi(av[2]);
  if (ret < 2 || ret > NB_ASTEK)
    {
      write(2, USAGE, strlen(USAGE));
      exit(EXIT_FAILURE);
    }
  return (ret);
}

void	die(t_astek *astek)
{
  xpthread_mutex_unlock(get_stick(astek, REST));
  put_astek(astek, " est mort !");
  end_game(1);
}

int	nb_pizza(t_astek *ptr_astek)
{
  int	nb_pizza;

  xpthread_mutex_lock(ptr_astek->mutex_pizza);
  nb_pizza = ptr_astek->pizza[0];
  xpthread_mutex_unlock(ptr_astek->mutex_pizza);
  return (nb_pizza);
}
