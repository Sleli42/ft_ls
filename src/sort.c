/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 17:14:33 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/06 01:42:25 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ls.h"

static void	swap_elem(t_infos *a, t_infos *b)
{
	t_infos	*c;
	t_stat	tempstat;

	c = (t_infos *)malloc(sizeof(t_infos));
	c->name = a->name;
	c->path = a->path;
	tempstat = a->stat;
	a->name = b->name;
	a->path = b->path;
	a->stat = b->stat;
	b->name = c->name;
	b->path = b->path;
	b->stat = tempstat;
}

t_infos	*sort_maj(t_infos *lst)
{
	t_infos *tmp;
	t_infos	*ret;
	int		i;

	i = 0;
	ret = lst;
	tmp = ret;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->name, tmp->next->name) > 0)
		{
			swap_elem(tmp, tmp->next);
			tmp = ret;
		}
		tmp = tmp->next;
	}
	return (ret);
}