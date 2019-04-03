/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:42:37 by pscott            #+#    #+#             */
/*   Updated: 2019/04/03 13:42:40 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_arg_list	*lst;
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

void				reset_lst(t_arg_list *lst)
{
	t_arg_list *tmp;

	tmp = lst;
	tmp->highlighted = 0;
	while ((tmp = tmp->next) && (tmp != lst))
		tmp->highlighted = 0;
}
