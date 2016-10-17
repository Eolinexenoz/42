NAME = libftprintf.a

#==============#
#_- Compiler -_#
#==============#
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
MAKE = make -sC

#====================#
#_- Programes Path -_#
#====================#
SRC_PATH = ./
OBJ_PATH = ./objs/
INC_PATH = ./
LIB_PATH =

#===========#
#_- Color -_#
#===========#

# color #
# red = 9
# hard_red = 196
# orange = 214
# violet = 140
# green = 47

TITLE_COLOR = 214
CLEAN_COLOR = 9
LINK_COLOR = 47
OBJ_COLOR = 47

MAKE_COLOR = 47
MAKE_ALREADY = 140
MAKE_FAIL = 9

NORME_COLOR = 47
NORME_COLOR_ERR = 9
NORME_COLOR_WAR = 196

#==============#
#_- Fonction -_#
#==============#

cmd_make = echo "\033[38;5;$(MAKE_COLOR)m$(MAKE) $(1)\033[0m"; \
		   $(MAKE) $(1)

cmd_color = echo "\033[38;5;$(1)m$(2)\033[0m"; \
			$(2)

put_title = echo "\033[38;5;$(TITLE_COLOR)m[ $(1) ]\033[0m"

#==================#
#_- Source Files -_#
#==================#
MAIN = ./main.c

SRC_NAME = ft_newprintf.c ft_printf_conv.c ft_printf_conv2.c ft_printf_conv3.c \
	  ft_printf_solve.c ft_printf_solve2.c ft_printf_solve3.c

LIBFT_SRCS = ft_putchar.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
      ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c \
      ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
      ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
      ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
      ft_strcpy.c ft_strdup.c ft_strequ.c ft_strlen.c ft_strncat.c \
      ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnstr.c ft_strrchr.c \
      ft_strstr.c ft_tolower.c ft_toupper.c ft_striter.c  \
      ft_strlcat.c ft_memalloc.c ft_itoa.c ft_strtrim.c ft_strsub.c \
      ft_strnew.c ft_strmapi.c ft_strsplit.c ft_strmap.c ft_strjoin.c \
      ft_striteri.c ft_strdel.c ft_memdel.c ft_lstnew.c ft_lstmap.c \
      ft_lstiter.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_strtolow.c \
      ft_strtoupp.c ft_strrev.c ft_power.c ft_isspace.c ft_putnbr_tab.c \
      ft_base.c ft_putnbr_ud.c ft_putstr_end.c \
      ft_convert_base.c ft_convert_base_maj.c ft_convert_base_uintmax_t.c \
      ft_convert_base_un.c ft_putnbr_ul.c ft_convert_base_ul.c ft_putwchar.c \
      ft_convert_base_l.c ft_itoa_printf.c ft_anco.c


LIB_SRC = $(addprefix libft/, $(LIBFT_SRCS))

OBJ_NAME = $(SRC_NAME:.c=.o) $(LIB_SRC:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME) $(LIB_SRC))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC = $(addprefix -I, $(INC_PATH))

#===========#
#_- Rules -_#
#===========#
all: $(NAME)

#	linking
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(call cmd_color,$(LINK_COLOR),$(CC) $(CFLAGS) $(INC) -o $@ -c $<)

#	preLinking
$(OBJ_PATH):
	@$(call put_title,Linking)

#	Object Compiation
$(NAME): $(OBJ_PATH) $(OBJ)
	@$(call put_title,Compilation)
	@$(call cmd_color,$(OBJ_COLOR),ar rc $@ $(OBJ))
	@$(call cmd_color,$(OBJ_COLOR),ranlib $@)

#	Removing object
clean:
	@$(call put_title,Cleaning)
	@$(RM) $(OBJ_PATH)
	@$(call cmd_color,$(CLEAN_COLOR),rm -rf $(OBJ))

#	Removeing binary
fclean : clean
	@$(RM) $(NAME)
	@$(call cmd_color,$(CLEAN_COLOR),rm -rf $(NAME))

re: fclean all

#	check norme for includes and ./srcs/ files
norme:
	@norminette $(SRC) $(INC_PATH) | sed "s/Norme/[0;1;47m\
	[0;38;5;$(NORME_COLOR)mNorme/g; s/Warning/[38;5;$(NORME_COLOR_WAR)m\
	Warning/g; s/Error/\[38;5;$(NORME_COLOR_ERR)m Error/g"

size:
	cat $(SRC) | wc -l

test: all
	@$(call cmd_color,$(OBJ_COLOR),$(CC) $(MAIN) -o ft_printf $(INC) $(NAME))

#	run the program
run: test
	@echo "\033[38;5;214mRuning Test:\033[0m"
	@./ft_printf

.PHONY: all clean fclean re norme test run
