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
	int				print_width;
	struct winsize	w;
	t_pos			pos;
}				t_print_info;

t_arg_list		*create_list(char **av);
void			print_list(t_arg_list *lst, t_print_info *info);
void			print_selected(t_arg_list *lst, t_print_info *info);
t_arg_list		*lst_addr(t_arg_list **lst);
t_print_info	*info_addr(t_print_info **info);


void			print_info(t_print_info *info);
t_arg_list		*jump_nodes(t_arg_list *lst, int num);
void			free_list(t_arg_list *lst);
void			free_node(t_arg_list *lst);

int				err_usage(void);

void			signal_setup(void);
int				get_print_info(t_arg_list *lst, t_print_info *info);

int				move_vertically(t_arg_list *lst, t_print_info *info, char *direction);
int				move_horizontally(t_arg_list *lst, t_print_info *info, char *direction);

int				select_node(t_arg_list *lst, t_print_info *info);

#endif
