/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 23:22:14 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/12 04:00:53 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_all		*lst_create_elem(t_infos *infos)
{
	t_all		*new;

	if (!(new = (t_all *)malloc(sizeof(t_all))))
		printf("malloc error [lst.create.elem]\n");
	if (infos == NULL)
		new->content = NULL;
	else
	{
		new->content = infos;
		if (new->content == NULL)
			return (NULL);
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void 	lst_add_elem_back(t_all **alst, t_all *new_elem)
{
	t_all *curr;

	curr = *alst;
	if (new_elem != NULL)
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
		printf("error [lst.add.elem.back]\n");
}

int		len_lst(t_all *tmp)
{
	int		i;
	t_all	*count;

	i = 0;
	count = tmp;
	if (count)
	{
		while (count)
		{
			i++;
			count = count->next;
		}
	}
	else
		return (0);
	return (i);
}

void	del_lst(t_all *alst)
{
	t_all	*next_list;
	t_all	*tmp;

	tmp = alst;
	next_list = NULL;
	if (tmp)
	{
		while (tmp)
		{
			next_list = tmp->next;
			if (tmp->content->path)
				free(tmp->content->path);
			if (tmp->content->name)
				free(tmp->content->name);
			if (tmp->content->date)
				free(tmp->content->date);
			if (tmp->content->rights)
				free(tmp->content->rights);
			if (tmp->content->link)
				free(tmp->content->link);
			if (tmp->content->size)
				free(tmp->content->size);
			if (tmp->content->s_uid)
				free(tmp->content->s_uid);
			if (tmp->content->s_gid)
				free(tmp->content->s_gid);
			if (tmp->content)
				free(tmp->content);
			if (tmp)
				free(tmp);
			tmp = next_list;
		}
	}
}
