/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 01:00:29 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/09 03:20:17 by lubaujar         ###   ########.fr       */
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
		while (tmp != NULL)
			tmp = tmp->next, i++;
	}
	else
		return (0);
	return (i);
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

t_infos		*lst_create_elem(char *path, char *filename, t_dirent *dirp)
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
		new->is_dir = 0;
		new->path = path;
		new->name = filename;
		if (dirp->d_type == DT_DIR)
			new->is_dir = 1;
	}
	// ft_printf("[lst] |%s|\n", new->name);
	// ft_printf("[lst] |%d|\n", new->is_dir);
	new->next = NULL;
	return (new);
}
