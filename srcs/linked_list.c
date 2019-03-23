#include "ft_select.h"

void		print_list(t_arg_list *lst)
{
	t_arg_list	*tmp;

	ft_printf("\n");
	if (!(tmp = lst))
	{
		ft_putstr_fd("error: arg_list is empty\n", 2);
		return ;
	}
	ft_printf("%-10s", tmp->name);
	while ((tmp = tmp->next) && (tmp != lst))
		ft_printf("%-10s", tmp->name);
	ft_printf("\n");
}

t_arg_list	*create_node(char *name)
{
	t_arg_list *res;

	if (!name)
		return (NULL);
	if (!(res = (t_arg_list*)malloc(sizeof(*res))))
		return (NULL);
	if (!(res->name = ft_strdup(name)))
		return (NULL);
	res->len = ft_strlen(name);
	res->next = res;
	res->prev = res;
	return (res);
}

t_arg_list	*add_node(t_arg_list *new, t_arg_list **lst)
{
	t_arg_list	*tail;
	t_arg_list	*head;

	if (!lst)
		return (NULL);
	if (!*lst)
		return (new);
	head = (*lst);
	tail = head->prev;
	new->prev = tail;
	new->next = head;
	tail->next = new;
	head->prev = new;
	return (head);
}


t_arg_list	*create_list(char **av)
{
	t_arg_list *lst;

	if (!av || !(*av))
		return (NULL);
	lst = NULL;
	while (*av)
	{
		lst = add_node(create_node(*av), &lst);
		av++;
	}
	return (lst);
}
