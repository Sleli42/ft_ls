# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/12 19:50:41 by lubaujar          #+#    #+#              #
#    Updated: 2015/03/03 13:08:33 by lubaujar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_atoi.c\
	  ft_bzero.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_islower.c\
	  ft_isprint.c\
	  ft_isspace.c\
	  ft_isupper.c\
	  ft_iswhite.c\
	  ft_itoa.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putchar.c\
	  ft_putchar_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_fd.c\
	  ft_putstr.c\
	  ft_putstr_fd.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strequ.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnequ.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strsplit.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_realloc.c\
	  ft_strrev.c\
	  ft_atoi_long.c\
	  ft_itoa_long.c\
	  ft_uitoa_long.c\
	  ft_uitoa.c\
	  ft_rand_a_b.c\
	  ft_intlen.c\
	  get_next_line.c

OBJ = $(SRC:.c=.o)

INC = -I./include/

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(INC) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\n\t \033[32m[All Fine's]\033[0m\n"

clean:
	@echo "\nRM *.o.. \t      \033[32mOK BITCH!\033[0m"
	@$(RM) $(OBJ)
	@$(RM) *.o

fclean: clean
	@echo "RM libft.a..\t      \033[32mOK BITCH!\033[0m"
	@$(RM) $(NAME)

re: fclean all

exec:
	@echo "\033[37mgcc *.c -I./includes/ ..\033[0m"
	@echo "  \033[37m..exec ./a.out\033[0m\n"
	@gcc *.c -g $(FLAGS) -I./includes/
	@echo "\033[31m./a.out\033[m\n"
	@./a.out

.PHONY: all clean fclean re exec
