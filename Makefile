CC = cc 

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft.a
LIBFT = $(LIBFT_DIR)/libft.a

NAME = libftprintf.a

SRC = ft_printf.c ft_char_print.c ft_hex_print.c ft_int_print.c ft_str_print.c ft_uns_print.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o: 
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ) $(LIBFT)
	ar rcs $@ $(OBJ) $(LIBFT)

LIBFT:
	@make -C $(LIBFT_DIR)

clean: 
	@rm -f $(OBJ) $(OBJ_BONUS) $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) $(LIBFT_DIR)

re: fclean all

.PHONY:	all clean fclean re bonus
