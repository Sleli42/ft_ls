/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 01:00:29 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/08 18:52:04 by lubaujar         ###   ########.fr       */
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
			if (tmp)
				free(tmp);
			tmp = next_list;
		}
	}
}

int		len_lst(t_all **tmp)
{
	int		i;
	t_all	*count;

	i = 0;
	count = *tmp;
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

void 	lst_add_elem_back(t_all **alst, t_all *new_elem)
{
	t_all *curr;

	curr = *alst;
	if (new_elem != NULL)
	{
		if (*alst == NULL)
		{
			//ft_printf("%s\n", "premier tour lst_add_elem_back");
			*alst = new_elem;
		}
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
		ft_error("lst_add_elem_back, new_elem NULL", 4);
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
		ft_error("lst_create_elem", 2);
		//new = NULL;
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
