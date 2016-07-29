/*
** philo.h for  in /u/all/sundas_c/cu/rendu/c/philo1
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar 29 15:53:49 2009 christophe sundas
** Last update Sun Mar 29 22:42:05 2009 christophe sundas
*/
#ifndef __H__PHILO__H
# define __H__PHILO__H

# include <pthread.h>
# include <unistd.h>
#define USAGE "./philo1 pizzas(>1) astek(1-42)\n\0"
#define NB_ASTEK 42
#define NB_PIZZA 1000
#define LEFT 0
#define RIGHT 1
#define LIMIT_DIE 20
#define REST   0
#define THINK  1

#ifdef __linux__
# ifndef __useconds_t_defined
typedef __useconds_t useconds_t;
#  define __useconds_t_define
# endif
#endif

typedef struct	s_philo
{
  int		id;
  void		*mutex_pizza;
  int		*pizza;
  int		nb_eat;
  void		*left;
  void		*right;
  int		nb_astek;
  int		sum_pizza;
}		t_astek;

void	start_game(int nbpizza, int nbastek);
t_astek	**init_astek(int *pizza, void *mutex_pizza, int nb_astek);
void	decrem_pizza(t_astek *ptr_astek);
void	activ(int n);
int	end_game(int n);

/*
** game
*/
int	parse_arg_pizza(int ac, char **av);
int	parse_arg_astek(int ac, char **av);
void	die(t_astek * astek);
int	nb_pizza(t_astek *ptr_astek);
/*
** output
*/
void	put_astek(t_astek *astek, char *str);
void	show_res(t_astek **astek);
char	*get_name(int id);

/*
** state_astek
*/
void	*my_thread(void *data);
void	*get_stick(t_astek *astek, int mode);
void	resting(t_astek *astek);
void	thinking(t_astek *astek);
void	eating(t_astek *astek);

/*
** xfuncs
*/
void	xjoin(pthread_t threads[NB_ASTEK], int nb);
void	xfree(t_astek **astek, int nb);
void	xpthread_mutex_init(void *ptr);
void	xpthread_create(pthread_t * th, void *(*routine)(void *), void *arg);
void	xpthread_mutex_destroy(pthread_mutex_t *mutex);
void	xpthread_join(pthread_t thread);
void	xpthread_mutex_unlock(pthread_mutex_t *mutex);
void	xpthread_mutex_lock(pthread_mutex_t *mutex);
void	xusleep(useconds_t useconds);
void	*xmalloc(size_t size);
#endif
