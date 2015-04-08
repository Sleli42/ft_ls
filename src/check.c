/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:28:14 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/08 02:55:45 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	check_options(t_opt *opt, char **av)
{
	char	*check;
	int		i;

	check = av[1];
	i = 0;
	if (check[i] == '-')
	{
		while (check[i])
		{
			if (check[i] == 'a')
				opt->a = 1;
			if (check[i] == 'l')
				opt->l = 1;
			if (check[i] == 't')
				opt->t = 1;
			if (check[i] == 'r')
				opt->r = 1;
			if (check[i] == 'R')
				opt->R = 1;
			i++;
		}
	}
	else
		opt->no_opt = 1;
}
