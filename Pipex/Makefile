NAME = pipex

SRC = pipex.c ft_split.c ft_strjoin.c ft_strnstr.c ft_substr.c ft_strlen.c ex.c

BONUS	=	pipex_bonus.c get_next_line.c ft_strncmp.c

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -o pipex -fsanitize=address

OBJ				= $(SRC:.c=.o)
BONUS_OBJ		= $(BONUS:.c=.o)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ)

all:			$(NAME)

clean:
				$(RM) $(OBJ) $(BONUS_OBJ)

fclean: 		clean
				$(RM) $(NAME)

re:		fclean	$(NAME)

bonus:			$(BONUS_OBJ)
				$(CC) $(CFLAGS) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus
