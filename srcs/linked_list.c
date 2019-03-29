#include "ft_select.h"

static t_arg_list	*create_node(char *name, int id)
{
	t_arg_list *res;

	if (!name)
		return (NULL);
	if (!(res = (t_arg_list*)malloc(sizeof(*res))))
		return (NULL);
	if (!(res->name = ft_strdup(name)))
		return (NULL);
	res->len = ft_strlen(name);
	res->current = 0;
	res->highlighted = 0;
	res->prev = 0;
	res->id = id;
	res->next = res;
	res->prev = res;
	return (res);
}

static t_arg_list	*add_node(t_arg_list *new, t_arg_list **lst)
{
	t_arg_list	*tail;
	t_arg_list	*head;

	if (!lst)
		return (NULL);
	if (!*lst)
		return (new);
	if (!new)
		return (*lst);
	head = (*lst);
	tail = head->prev;
	new->prev = tail;
	new->next = head;
	tail->next = new;
	head->prev = new;
	return (head);
}

t_arg_list			*create_list(char **av)
{
	t_arg_list *lst;
	int			id;

	id = 1;
	if (!av || !(*av))
		return (NULL);
	lst = NULL;
	while (*av)
	{
		lst = add_node(create_node(*av, id), &lst);
		av++;
		id++;
	}
	lst_addr(&lst);
	return (lst);
}

void			reset_lst(t_arg_list *lst)
{
	t_arg_list *tmp;

	tmp = lst;
	tmp->highlighted= 0;
	while ((tmp = tmp->next) && (tmp != lst))
		tmp->highlighted = 0;
}

t_print_info	*info_addr(t_print_info **new)
{
	static t_print_info	*info = NULL;

	if (new)
		info = *new;
	return (info);
}

/*
** This function replaces a global variable.
** Global are fobidden at 42 (except for g_saved_attr)
** Call get_lst(NULL) to retrieve the current list address,
** or call get_lst(&lst) to set the static variable to lst's address.
*/

t_arg_list			*lst_addr(t_arg_list **new)
{
	static t_arg_list *lst = NULL;

	if (new)
		lst = *new;
	return (lst);
}
