/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 01:00:29 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/14 19:41:08 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	del_lst(t_all *alst)
{
	t_all	*next_list;
	t_all	*tmp;

	tmp = alst;
	next_list = NULL;
	//ft_putstr("SALOPE\n");
	if (tmp)
	{
		while (tmp)
		{
			next_list = tmp->next;
			if (tmp->content->path)
				free(tmp->content->path);
			if (tmp->content->name)
				free(tmp->content->name);
			if (tmp)
				free(tmp);
			tmp = next_list;
		}
	}
}

int		len_lst(t_all *tmp)
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

void 	lst_add_elem_back(t_all **alst, t_all *new_elem)
{
	t_all *curr;

	curr = *alst;
	if (new_elem)
	{
		if (*alst == NULL)
			*alst = new_elem;
		else
		{
			while (curr->next != NULL)
				curr = curr->next;
			curr->next = new_elem;
			new_elem->prev = curr;
			new_elem->next = NULL;
		}
	}
	else
		exit (1);
}

void	lst_add_elem(t_all **alst, t_all *new_elem)
{
	if (new_elem != NULL)
	{
		if (*alst != NULL)
		{
			new_elem->next = *alst;
			(*alst)->prev = new_elem;
			*alst = new_elem;
		}
	}
	else
		*alst = new_elem;
}

t_all		*lst_create_elem(t_infos *infos)
{
	t_all		*new;

	//ft_printf("path: %s\nfilename: %s\n", path, filename);
	if (!(new = (t_all *)malloc(sizeof(t_all))))
		new = NULL;
	if (infos == NULL)
		new->content = NULL;
	else
	{
		new->content = (t_infos *)malloc(sizeof(t_infos));
		if (new->content == NULL)
			return (NULL);
		new->content = infos;
	}
	//ft_printf("[lst] |%s|\n", new->content->name);
	// ft_printf("[lst] |%d|\n", new->content.is_dir);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
