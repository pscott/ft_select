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
ITOADIR		:= srcs/ft_itoa
LIBDIR		:= srcs/libft
INCLDIR		:= -I includes/
CONVDIR		:= srcs/conversion
FORMDIR		:= srcs/formats
GETLENDIR	:= srcs/get_len
HELPERSDIR	:= srcs/helpers
INCREMDIR	:= srcs/incrementers

CFLAGS	:= -Wall -Werror -Wextra $(INCLDIR)
ARFLAGS	:=

LIBS	:= ft_atoi.c  ft_bzero.c  ft_isalnum.c  ft_isalpha.c  ft_isascii.c \
	ft_isdigit.c  ft_isprint.c  ft_lstadd.c \
	ft_lstappend.c  ft_lstdel.c  ft_lstdelone.c  ft_lstiter.c  ft_lstlen.c \
	ft_lstmap.c  ft_lstnew.c  ft_lstrmdup.c  ft_lstsort.c  ft_memalloc.c \
	ft_memccpy.c  ft_memchr.c  ft_memcmp.c  ft_memcpy.c  ft_memdel.c \
	ft_memmove.c  ft_memset.c  ft_putchar.c  ft_putchar_fd.c  ft_putendl.c \
	ft_putendl_fd.c  ft_putnbr.c  ft_putnbr_fd.c  ft_putstr.c  ft_putstr_fd.c \
	ft_strcat.c  ft_strchr.c  ft_strclr.c  ft_strcmp.c  ft_strcpy.c \
	ft_strdel.c  ft_strdup.c  ft_strequ.c  ft_striter.c  ft_striteri.c \
	ft_strjoin.c  ft_strlcat.c  ft_strlen.c  ft_strmap.c  ft_strmapi.c \
	ft_strncat.c  ft_strncmp.c  ft_strncpy.c  ft_strnequ.c  ft_strnew.c \
	ft_strnstr.c  ft_strrchr.c  ft_strrev.c  ft_strsplit.c  ft_strstr.c \
	ft_strsub.c  ft_strtrim.c  ft_tolower.c  ft_toupper.c ft_itoa.c ft_realloc.c


ITOA	:= ft_nitoa.c  ft_litoa.c ft_llitoa.c ft_hitoa.c ft_hhitoa.c ft_uitoa.c
CONV	:= conv_helper.c converters.c
FORM	:= format_int.c format_char.c format_unsigned.c format_string.c \
	format_conv.c format_p.c format_float.c
GETLEN	:= get_len.c get_ulen.c
HELPERS	:= ft_atoi_move.c null_data.c ft_special_memset.c ft_strncat_move.c \
	utils.c values.c unsigned_helper.c choose_value.c float_helper.c
INCREM	:= increm_format.c increm_string.c 

PRINTF	:= ft_printf.c parse_struct.c getters.c spec_init.c \
	isprint_special.c set_data_len.c wildcard.c

CONV	:= $(addprefix $(CONVDIR)/, $(CONV))
ITOA	:= $(addprefix $(ITOADIR)/, $(ITOA))
FORM	:= $(addprefix $(FORMDIR)/, $(FORM))
GETLEN	:= $(addprefix $(GETLENDIR)/, $(GETLEN))
HELPERS	:= $(addprefix $(HELPERSDIR)/, $(HELPERS))
INCREM	:= $(addprefix $(INCREMDIR)/, $(INCREM))
LIBS	:= $(addprefix $(LIBDIR)/, $(LIBS))
PRINTF	:= $(addprefix $(SRCDIR)/, $(PRINTF))

SRCS	:= $(LIBS) $(ITOA) $(PRINTF) $(CONV) $(FORM) $(GETLEN) $(HELPERS) \
	$(INCREM)
OBJS	:= $(SRCS:.c=.o)
DEPS	:= Makefile includes/ft_printf.h includes/libft.h
NAME	:= libft.a

all: $(NAME)

d: all
	@gcc main.c $(INCLDIR) $(NAME)
	@./a.out
	@$(RM) a.out*

val:
	@gcc main.c $(INCLDIR) $(NAME)
	@valgrind --leak-check=yes ./a.out
	@$(RM) a.out*

fsa:
	@gcc main.c $(INCLDIR) $(NAME) -fsanitize=address -g3
	@./a.out
	@$(RM) a.out*

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) a.out

re: fclean all

.PHONY: all clean fclean re comp
