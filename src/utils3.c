/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 18:57:03 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/07 16:29:32 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

#include <stdio.h>

char 	*major_minor_to_str(t_stat *stat)
{
	char 	*s;
	char 	*minor_s;
	char 	*major_s;

	s = (char *)malloc(sizeof(char) * 11);
	s = ft_strcpy(s, " ");
	minor_s = ft_itoa(minor(stat->st_rdev));
	major_s = ft_itoa(major(stat->st_rdev));
	if (ft_strlen(major_s) == 1)
		s[1] = ' ';
	s = ft_strcat(s, major_s);
	s = ft_strcat(s, ",");
	s = ft_strncat(s, "    ", (4 - ft_strlen(minor_s)));
	s = ft_strcat(s, minor_s);
	ft_strdel(&major_s);
	ft_strdel(&minor_s);
	return (s);
}

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
