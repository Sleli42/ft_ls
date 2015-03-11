/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:28:14 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/03 13:03:09 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		check_options(t_all *all, char **av)
{
	char	*check;

	check = av[1];
	if (check[0] == '-')
	{
		if (check[1] == 'a')
			all->opt.a = 1;
		if (check[1] == 'l')
			all->opt.l = 1;
		if (check[1] == 't')
			all->opt.t = 1;
		if (check[1] == 'r')
			all->opt.r = 1;
		if (check[1] == 'R')
			all->opt.R = 1;
		return (1);
	}
	else
		all->opt.no_opt = 1;
	return (0);
}
