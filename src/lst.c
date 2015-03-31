/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 01:00:29 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/01 00:46:19 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	del_lst(t_infos **alst)
{
	t_infos	*next_list;
	t_infos	*tmp;

	tmp = *alst;
	//ft_putstr("SALOPE\n");
	while (tmp)
	{
		next_list = tmp->next;
		//ft_printf("tmp->name: %s\n", tmp->name);
		ft_strdel(&tmp->name);
		//ft_printf("tmp->name: %s\n", tmp->name);
		ft_strdel(&tmp->path);
		free(&tmp->stat);
		free(tmp);
		tmp = next_list;
	}
	*alst = NULL;
}

int		len_lst(t_infos *tmp)
{
	int		i;

	i = 0;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next, i++;
	}
	else
		return (0);
	return (i);
}

void	display_lst(t_infos *lst)
{
	t_infos *tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->name, ".", 1) != 0)
			ft_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	// t_infos	*tmp;

	// tmp = lst;
	// // ft_printf("%s\n", lst->name);
	// // ft_printf("%s\n", tmp->name);
	// while (tmp)
	// {
	// 	//ft_printf("%s\n", lst->path);
	// 	//if (tmp->name[0] != '.')
	// 	 	ft_printf("%s\n", tmp->name);
	// 	tmp = tmp->next;
	// }
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

	// ft_printf("path: %s\nfilename: %s\n", path, filename);
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
