/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 18:57:03 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/23 11:41:16 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int 	define_blksize(t_all **all, t_opt *opt)
{
	t_all *tmp;
	int   ret;

	tmp = *all;
	ret = 0;
	if (*all)
	{
		while (tmp)
		{
			if (opt->a)
			{
				if (tmp->content->blksize != 0)
					ret += tmp->content->blksize;
			}
			else
			{
				if (tmp->content->name[0] != '.')
					ret += tmp->content->blksize;
			}
			tmp = tmp->next;
		}
	}
	return (ret);
}

t_all	*goto_last_elem(t_all *all)
{
	t_all *tmp;

	tmp = all;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	return (tmp);
}

int 	count_dir(int ac, char **av)
{
	int 	ret;

	ret = 0;
	while (ac-- > 1)
		if (av[ac - 1][0] != '-')
			ret++;
	return (ret);
}
