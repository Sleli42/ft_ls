/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:28:14 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/29 23:17:46 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		check_options(t_opt *opt, char **av)
{
	char	*check;

	check = av[1];
	if (check[0] == '-')
	{
		if (check[1] == 'a')
			opt->a = 1;
		if (check[1] == 'l')
			opt->l = 1;
		if (check[1] == 't')
			opt->t = 1;
		if (check[1] == 'r')
			opt->r = 1;
		if (check[1] == 'R')
			opt->R = 1;
		return (1);
	}
	else
		opt->no_opt = 1;
	return (0);
}
