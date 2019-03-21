#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdio.h>
# include "libterm.h"

typedef struct	s_arg_list {
	char				*name;
	int					len;
	struct s_arg_list	*next;
	struct s_arg_list	*prev;
}				t_arg_list;

typedef struct	s_list_addr {
	struct s_arg_list	*head;
	struct s_arg_list	*tail;
}				t_list_addr;

t_arg_list	*create_list(char **av, t_list_addr *addr);
void		print_arg_list(t_list_addr *addr);

void		free_list(t_list_addr *addr);

int			err_usage(void);

#endif
