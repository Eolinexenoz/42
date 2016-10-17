# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdupless <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 12:32:13 by qdupless          #+#    #+#              #
#    Updated: 2016/01/28 14:59:40 by qdupless         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c ft_check_sample.c ft_creatab.c ft_create_tab.c

INCLUDE = ./Includes/

PATH = Includes

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc $(FLAGS) -c $(SRC)
	gcc $(OBJS) -L $(INCLUDE) -lft  -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
