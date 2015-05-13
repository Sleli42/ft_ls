/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 01:03:47 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/13 01:39:59 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_all	*goto_last_elem(t_all *all)
{
	t_all *tmp;

	tmp = all;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	return (tmp);
}

int 	define_blksize(t_all *all, t_opt *opt)
{
	t_all *tmp;
	int   ret;

	tmp = all;
	ret = 0;
	if (tmp == NULL)
		return (-1);
	else
	{
		while (tmp)
		{
			if (opt->a)
				if (tmp->content->blksize != 0)
					ret += tmp->content->blksize;
			else
				if (tmp->content->name[0] != '.')
					ret += tmp->content->blksize;
			tmp = tmp->next;
		}
	}
	del_lst(tmp);
	return (ret);
}
