/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:19:54 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/03 15:29:16 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	init_options(t_all *all)
{
	all->opt.a = 0;
	all->opt.l = 0;
	all->opt.t = 0;
	all->opt.r = 0;
	all->opt.R = 0;
	all->opt.no_opt = 0;
}

char	*create_path_directory(char	*arg)
{
	int		i;
	int		find;
	int		n;
	char	*path;

	i = -1;
	n = -1;
	find = 0;
	while (arg[++i])
	{
		if (arg[i] == '/')
			find = i;
	}
	if (find == 0)
		return (NULL);
	path = (char *)ft_memalloc(i + 1);
	while (++n != find + 1)
		path[n] = arg[n];
	i = -1;
	n--;
	while (arg[++n])
		arg[++i] = arg[n];
	while (arg[++i])
		arg[i] = 0;
	return (path);
}
