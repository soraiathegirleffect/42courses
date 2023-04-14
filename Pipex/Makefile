NAME	= pipex
CC	= gcc
SRCS	= pipex.c
BSRCS	= pipex_bonus.c bonustuff.c 
FLAGS	= -Wall -Werror -Wextra -fsanitize=address
RM	= rm -f


all:	$(NAME)
clean:	${RM} ${NAME}
fclean:	clean
	make -C libft fclean

re:	fclean all



.PHONY: all re clean fclean