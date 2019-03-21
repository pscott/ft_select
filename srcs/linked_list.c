#include "ft_select.h"

void		print_arg_list(t_list_addr *addr)
{
	t_arg_list	*tmp;

	ft_printf("\n");
	if (!(tmp = addr->head))
	{
		ft_putstr_fd("error: arg_list is empty\n", 2);
		return ;
	}
	ft_printf("%-10s", tmp->name);
	while ((tmp = tmp->next) && (tmp != addr->head))
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
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

void		add_node(t_arg_list *new, t_list_addr *addr)
{
	t_arg_list	*tail;

	if (!addr || !(addr->tail) || !(addr->head))
	{
		ft_putstr_fd("error with addr tail or head\n", 2);
		return ;
	}
	tail = addr->tail;
	tail->next = new;
	new->prev = tail;
	new->next = addr->head;
	addr->tail = new;
}

t_arg_list	*create_list(char **av, t_list_addr *addr)
{
	t_arg_list *lst;

	if (!av || !(*av))
		return (NULL);
	lst = create_node(*av);
	addr->head = lst;
	addr->tail = lst;
	av++;
	while (*av)
	{
		add_node(create_node(*av), addr);
		av++;
	}
	return (lst);
}
