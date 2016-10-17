NAME = ft_ls

SRC = ft_ls_fichier.c

INCLUDE = ./Includes/libft/

PATH = Includes

OBJS = $(SRC:.c=.o)

FLAGS = -g -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc -c $(SRC)
	gcc $(OBJS) -L $(INCLUDE) -lft  -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
