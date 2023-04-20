NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -o pipex -fsanitize=address

RM = rm -f

SRC = pipex.c libft.c

OBJ = $(SRC:.c=.o)



all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ)

clean:
				$(RM) $(OBJ)

fclean: 		clean
				$(RM) $(NAME)

re:		fclean	$(NAME)

.PHONY: all clean fclean re
