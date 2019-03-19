# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pscott <pscott@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 10:29:04 by pscott            #+#    #+#              #
#    Updated: 2019/01/27 12:02:30 by pscott           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
RM		:= rm -rf


SRCDIR		:= srcs
INCLDIR		:= includes

LIBDIR	:= ../libft
LIBS	:= -L $(LIBDIR) -lft -ltermcap
CFLAGS	:= -Wall -Werror -I $(INCLDIR) -I $(LIBDIR)/includes
SRC		:= termcap_str.c termcap_init.c \
	errors/error_attr.c errors/error_tgetent.c errors/error_getenv.c errors/error_getstr.c

SRCS	:= $(addprefix $(SRCDIR)/, $(SRC))
OBJS	:= $(SRCS:.c=.o)
DEPS	:= Makefile $(INCLDIR)/libterm.h ../libft/libft.a
NAME	:= libterm.a

all: $(NAME)

../libft/libft.a:
	@$(MAKE) -C $(LIBDIR) -j

$(NAME): $(OBJS) $(DEPS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(DEPS) $(LIBDIR)/libft.a
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re comp
