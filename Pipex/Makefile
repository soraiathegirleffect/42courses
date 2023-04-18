NAME = pipex

CC = @cc

CFLAGS = -Wall -Wextra -Werror -g -o pipex

RM = @rm -f

SRC = pipex.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH = libft
LIBFT = libft/libft.a

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) $(LIBFT) 

all:			dolib $(NAME)

dolib:
	@$(MAKE) -C $(LIBFT_PATH)

clean:
				make clean -C $(LIBFT_PATH)
				$(RM) $(OBJ)

fclean: 		clean
				make fclean -C $(LIBFT_PATH)
				$(RM) $(NAME)

re:		fclean	$(NAME)

.PHONY: all clean fclean re
