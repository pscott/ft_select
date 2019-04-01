# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pscott <pscott@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 10:29:04 by pscott            #+#    #+#              #
#    Updated: 2019/04/01 16:22:39 by pscott           ###   ########.fr        #
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
SRC		:= execute_cap.c termcap_settings.c print_line.c cursor.c
ERR		:= error_attr.c error_tgetent.c error_getenv.c error_getstr.c \
	error_isatty.c error_tgoto.c

ERRS	:= $(addprefix $(ERRDIR)/, $(ERR))
SRCS	:= $(addprefix $(SRCDIR)/, $(SRC))
SOURCE	:= $(SRCS) $(ERRS)
OBJS	:= $(SOURCE:.c=.o)
DEPS	:= Makefile $(INCLDIR)/libterm.h $(INCLDIR)/cursor.h ../libft/libft.a
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
