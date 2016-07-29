##
## Makefile for  in /u/all/sundas_c/cu/rendu/c/philo1
## 
## Made by christophe sundas
## Login   <sundas_c@epitech.net>
## 
## Started on  Sun Mar 29 15:53:17 2009 christophe sundas
## Last update Sun Mar 29 15:53:18 2009 christophe sundas
##
NAME = philo1
CC = gcc
SRC = philo.c \
	game.c \
	output.c\
	state_astek.c \
	xfunc.c \
	xfunc2.c
OBJ = $(SRC:.c=.o)
CFLAGS += -W -Wall -ansi -pedantic -g3
LIB = -lpthread
RM = rm -f

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME)