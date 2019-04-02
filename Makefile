# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pscott <pscott@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/26 18:25:41 by pscott            #+#    #+#              #
#    Updated: 2019/04/02 16:28:34 by pscott           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:= gcc
WFLAGS		:= -Wall -Wextra -g
RM			:= rm -rf
NAME		:= ft_select

SRCDIR		:= srcs

SRC			:= main.c linked_list.c free.c signals.c printing.c arrows.c \
	info_utils.c selector.c deletor.c signal_utils.c
ERR			:= error_usage.c

INCL		:= -I includes/ -I libft/includes/ -I libterm/includes/

LIBS		:= -L libft -lft -L libterm -lterm -ltermcap
ERRS		:= $(addprefix $(SRCDIR)/errors/, $(ERR))
SRCS		:= $(addprefix $(SRCDIR)/, $(SRC)) $(ERRS)

OBJS		:= $(SRCS:.c=.o)
DEPS		:= includes/ft_select.h Makefile

COMP		:= $(CC) $(WFLAGS) $(INCL) $(LIBS)
ENV			:= env
OPT			:= 123 4567 8901011 abc defgghh

all: $(NAME)

libft:
	@$(MAKE) -C libft -j

libterm:
	@$(MAKE) -C libterm -j

d: all
	@$(ENV) ./$(NAME) $(OPT)

val: all
	@$(COMP) -o $(NAME) $(SRCS) -g
	valgrind --leak-check=full $(ENV) ./$(NAME) $(OPT)

fsa:
	@$(COMP) -o $(NAME) $(SRCS) -fsanitize=address -g3
	@$(ENV) ./$(NAME) $(OPT)

$(NAME): $(OBJS) libft libterm Makefile
	$(COMP) -o $(NAME) $(SRCS)

%.o: %.c $(DEPS)
	$(CC) -o $@ -c $< $(WFLAGS) $(INCL)

clean:
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C libterm
	@$(RM) *dSYM*
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C libft
	@$(MAKE) fclean -C libterm
	@$(RM) $(NAME)
	@$(RM) a.out

re: fclean all

.PHONY: all clean fclean re d fsa val libterm libft
