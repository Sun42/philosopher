/*
** output.c for  in /u/all/sundas_c/cu/rendu/c/philo1
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar 29 15:50:07 2009 christophe sundas
** Last update Thu Apr  2 11:25:10 2009 christophe sundas
*/
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "philo.h"

void	put_astek(t_astek *astek, char *str)
{
  if (printf("%s #%i : %s\n", get_name(astek->id), astek->id, str) < 0)
    write(2, "ERROR", strlen("error"));
}

char	*get_name(int id)
{
  char	*tab_name[16];

  tab_name[0] = "\033[0;32mCorfa_u     \033[0;m";
  tab_name[1] = "\033[0;31mBarthe_f\033[0;m";
  tab_name[2] = "\033[0;33mVieux_v \033[0;m";
  tab_name[3] = "\033[0;34mBeeone  \033[0;m";
  tab_name[4] = "\033[0;35mPradel_f\033[0;m";
  tab_name[5] = "\033[0;36mBucheron\033[0;m";
  tab_name[6] = "\033[0;37mChobix  \033[0;m";
  tab_name[7] = "\033[0;31mNikita  \033[0;m";
  tab_name[8] = "\033[0;32mGrandh_o\033[0;m";
  tab_name[9] = "\033[0;33mJog     \033[0;m";
  tab_name[10] = "\033[0;34mValent_j\033[0;m";
  tab_name[11] = "\033[0;35mPradel_f\033[0;m";
  tab_name[12] = "\033[0;36mLabori_a\033[0;m";
  tab_name[13] = "\033[0;37mFreier_n\033[0;m";
  tab_name[14] = "\033[0;32mDavid_g \033[0;m";
  tab_name[15] = "\033[0;31mLapie_t \033[0;m";
  if (id > 15)
    return ("Astek");
  else
    return (tab_name[id]);
}

void	show_res(t_astek **astek)
{
  int	i;
  int	sum;

  sum = 0;
  i = 0;
  if (printf("Fin du repas...\n\n\n\n") < 0)
    write(2, "ERROR", strlen("error"));
  while (i < astek[0]->nb_astek)
    {
      if (printf("%s #%i a mange %d pizza(s)\n",
	 get_name(astek[i]->id), astek[i]->id, astek[i]->nb_eat) < 0)
	write(2, "ERROR", strlen("error"));
      sum += astek[i]->nb_eat;
      i++;
    }
  if (printf("Pizzas mangees %d \nMoyenne theorique %d pizzas/astek\n",
     sum, astek[0]->sum_pizza / astek[0]->nb_astek) < 0)
    write(2, "ERROR", strlen("error"));
}
