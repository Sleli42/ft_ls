# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/03 12:31:07 by lubaujar          #+#    #+#              #
#    Updated: 2015/04/06 01:42:33 by lubaujar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
RM = rm -rf
FLAGS = -g -Wall -Wextra -Werror
LDFLAGS = -I./include/ -I./libft/include/

SRC = main.c\
	  check.c\
	  init.c\
	  recurse.c\
	  lst.c\
	  utils.c\
	  test.c\
	  sort.c\

OBJ = $(SRC:.c=.o)
	SRCDIR	= ./src/
	OBJDIR	= ./obj/
	INCDIR	= ./include/
	SRCS	= $(addprefix $(SRCDIR), $(SRC))
	OBJS	= $(addprefix $(OBJDIR), $(OBJ))
	INCS	= $(addprefix $(INCDIR), $(INC))

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	@gcc $(FLAGS) -o $@ $^ -L./libft/ include/libftprintf.a -lft
	@echo "\n\t \033[32m[All Fine's]\033[0m\n"

$(OBJS): $(SRCS)
	make -C libft/
	@gcc $(FLAGS) -c $(SRCS) $(LDFLAGS)
	@echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)

clean:
	@echo "\nRM *.o.. \t      \033[32mOK BITCH!\033[0m"
	@$(RM) $(OBJS)
	@$(RM) *.o

fclean: clean
	make fclean -C libft/
	@echo "RM ./ft_ls.. \t      \033[32mOK BITCH!\033[0m"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
