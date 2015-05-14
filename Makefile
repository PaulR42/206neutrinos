##
## Makefile for . in /home/rollan_e/rendu/206neutrinos
## 
## Made by Paul Rolland
## Login   <rollan_e@epitech.net>
## 
## Started on  Sun May 10 19:54:18 2015 Paul Rolland
## Last update Sun May 10 19:56:02 2015 Paul Rolland
##

NAME= 206neutrinos

SRCS= main.c \
      moy.c

OBJS= $(SRCS:.c=.o)

CC=   gcc

RM=   rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
