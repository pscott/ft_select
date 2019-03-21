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
ERRDIR		:= $(SRCDIR)/errors
LIBDIR		:= ../libft

LIBS	:= -L $(LIBDIR) -lft -ltermcap
CFLAGS	:= -Wall -Werror -I $(INCLDIR) -I $(LIBDIR)/includes
SRC		:= execute_cap.c termcap_settings.c
ERR		:= error_attr.c error_tgetent.c error_getenv.c error_getstr.c \
	error_isatty.c

ERRS	:= $(addprefix $(ERRDIR)/, $(ERR))
SRCS	:= $(addprefix $(SRCDIR)/, $(SRC))
SOURCE	:= $(SRCS) $(ERRS)
OBJS	:= $(SOURCE:.c=.o)
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
