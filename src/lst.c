/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 01:00:29 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/29 23:17:50 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	display_lst(t_infos *lst)
{
	t_infos	*tmp;

	tmp = lst;
	while (lst)
	{
		ft_printf("%s\n", lst->path);
		ft_printf("%s\n", lst->name);
		lst = lst->next;
	}
}

void	lst_add_elem_back(t_infos **alst, t_infos *new_elem)
{
	t_infos	*curr;

	curr = *alst;
	if (curr)
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new_elem;
	}
	else
		*alst = new_elem;
}

t_infos		*lst_create_elem(char *path, char *filename)
{
	t_infos	*new;


	if (!(new = (t_infos *)malloc(sizeof(t_infos))))
		ft_printf("error malloc\n");
	if (path == NULL || filename == NULL)
	{
			new->path = NULL;
			new->name = NULL;
	}
	else
	{
		new->path = path;
		new->name = filename;
	}
	new->next = NULL;
	return (new);
}
