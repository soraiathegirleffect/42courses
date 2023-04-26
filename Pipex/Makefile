NAME = pipex

SRC = pipex.c ft_split.c ft_strjoin.c ft_strnstr.c ft_substr.c ft_strlen.c get_next_line.c ex.c

BONUS	=	pipex_bonus.c ex_bonus.c

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -o pipex -fsanitize=address

OBJ = $(SRC:.c=.o)
BONUS_OBJS		= $(BONUS:.c=.o)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ)

all:			$(NAME)

clean:
				$(RM) $(OBJ) $(BONUS_OBJ)

fclean: 		clean
				$(RM) $(NAME)

re:		fclean	$(NAME)

bonus:	$(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus
