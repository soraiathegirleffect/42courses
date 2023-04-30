NAME = pipex

SRC = pipex.c ft_split.c ft_strjoin.c ft_strnstr.c ft_substr.c ft_strlen.c ft_strncmp.c ex.c

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -o pipex -fsanitize=address

OBJ				= $(SRC:.c=.o)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ)

all:			$(NAME)

clean:
				$(RM) $(OBJ) 

fclean: 		clean
				$(RM) $(NAME)

re:		fclean	all

.PHONY: all clean fclean re bonus
