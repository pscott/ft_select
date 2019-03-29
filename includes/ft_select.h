#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libterm.h"
# include <sys/ioctl.h>
# define BUF_SIZE 7
# define SPACING 2

typedef struct	s_arg_list {
	char				*name;
	int					len;
	struct s_arg_list	*next;
	struct s_arg_list	*prev;
	char				current;
	int					id;
	char				highlighted;
}				t_arg_list;

typedef struct	s_print_info {
	int				nb_elem;
	int				max_name_size;
	int				nb_chars;
	int				nb_lines;
	int				elem_per_line;
	struct winsize	w;
}				t_print_info;

t_arg_list		*create_list(char **av);
void			print_list(t_arg_list *lst, t_print_info *info);
void			print_selected(t_arg_list *lst);
t_arg_list		*lst_addr(t_arg_list **lst);
t_print_info	*info_addr(t_print_info **info);


void			print_info(t_print_info *info);
t_arg_list		*jump_nodes(t_arg_list *lst, int num);
void			free_list(t_arg_list *lst);
void			free_node(t_arg_list *lst);

int				err_usage(void);

void			signal_setup(void);
void			sigtstp_handler(int signo);
int				get_print_info(t_arg_list *lst, t_print_info *info);

int				move_vertically(t_arg_list *lst, char *direction);
int				move_horizontally(t_arg_list *lst, t_print_info *info, char *direction);

int				highlight_node(t_arg_list *lst);
t_arg_list		*delete_node(t_arg_list *lst, t_print_info *info);
void			reset_lst(t_arg_list *lst);

#endif
