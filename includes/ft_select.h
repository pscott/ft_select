#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libterm.h"

typedef struct	s_arg_list {
	char				*name;
	int					len;
	struct s_arg_list	*next;
	struct s_arg_list	*prev;
}				t_arg_list;

t_arg_list	*create_list(char **av);
void		print_list(t_arg_list *lst);

void		free_list(t_arg_list *lst);
void		free_node(t_arg_list *lst);

int			err_usage(void);

void		signal_setup(void);

#endif
