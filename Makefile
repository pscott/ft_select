# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pscott <pscott@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/26 18:25:41 by pscott            #+#    #+#              #
#    Updated: 2019/02/11 16:28:23 by pscott           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
WFLAGS	:= -Wall -Wextra
RM		:= rm -rf
NAME	:= ft_select

SRCDIR			:= srcs

SRC			:= main.c

INCL	:= -I includes/ -I libft/includes

LIBS		:= -L libft -lft
LIBTERM		:= -L libterm -lterm
SRCS		:= $(addprefix $(SRCDIR)/, $(SRC))

OBJS	:= $(SRCS:.c=.o)
DEPS	:= includes/ft_select.h Makefile

COMP	:= $(CC) $(WFLAGS) $(INCL) $(LIBS)

all: $(NAME)

libft/libft.a:
	$(MAKE) -C libft -j

d: all
	@./$(NAME)

val: all
	@$(COMP) -o $(NAME) $(SRCS) -g
	valgrind --leak-check=full ./$(NAME)

fsa:
	@$(COMP) -o $(NAME) $(SRCS) -fsanitize=address -g3
	@./$(NAME)

$(NAME): $(OBJS) libft/libft.a Makefile
	$(COMP) -o $(NAME) $(SRCS)

%.o: %.c $(DEPS)
	$(CC) -o $@ -c $< $(WFLAGS) $(INCL)

clean:
	@make clean -C libft
	@make clean -C libterm
	@$(RM) *dSYM*
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft
	@make fclean -C libterm
	@$(RM) $(NAME)
	@$(RM) a.out

re: fclean all

.PHONY: all clean fclean re d fsa val
