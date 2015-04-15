/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 17:14:33 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/16 01:33:39 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ls.h"

void 	swap_elem(t_all **a, t_all **b)
{
	t_infos *temp;

	temp = (*a)->content;
	(*a)->content = (*b)->content;
	(*b)->content = temp;
}

void 	sort_name(t_all **alst)
{
	t_all 	*tmp;
	int 	i;

	tmp = *alst;
	i = 0;
	if (tmp)
	{
		while (i++ < len_lst(*alst))
		{
			while (tmp->next)
			{
				if (ft_strcmp(tmp->content->name, tmp->next->content->name) > 0)
					swap_elem(&tmp, &tmp->next);
				tmp = tmp->next;
			}
			tmp = *alst;
		}
	}
}

void 	sort_time(t_all **alst)
{
	t_all *tmp;
	int 	i;

	tmp = *alst;
	i = 0;
	if (tmp)
	{
		while (i++ < len_lst(*alst))
		{
			while (tmp->next)
			{
				if (lstat(tmp->content->path, &tmp->content->stat) == -1)
					return ;
				if (tmp->content->stat.st_mtime <
					tmp->next->content->stat.st_mtime)
					swap_elem(&tmp, &tmp->next);
				tmp = tmp->next;
			}
			tmp = *alst;
		}
	}
}
