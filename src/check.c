/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:28:14 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/16 01:33:33 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void 	init_options(t_opt *opt, char *av)
{
	int i;

	i = 1;
	//ft_putstr("hallo\n");
	while (av[i])
	{
		if (av[i] == 'a')
			opt->a = 1;
		if (av[i] == 'l')
			opt->l = 1;
		if (av[i] == 'r')
			opt->r = 1;
		if (av[i] == 't')
			opt->t = 1;
		if (av[i] == 'R')
			opt->R = 1;
		i++;
	}
}

void 		check_options(t_opt *opt, char **av, int ac)
{
	int i;

	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1])
			init_options(opt, av[i]);
		i++;
	}
}
