/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:28:14 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/21 16:24:16 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int 	check_error(char c)
{
	if (c != 'a' && c != 'l' && c != 't' && c != 'r' && c != 'R')
		return (-1);
	return (1);
}

static int 	init_options(t_opt *opt, char *av)
{
	int i;
	int ret;

	i = 1;
	if (check_error(av[1]) == -1)
	{
		ft_printf("ls: illegal option -- %c\n", av[1]);
		ft_printf("usage: ls [-Ralrt] [file ...]\n");
		return (-1);
	}
	else
	{
		while (av[i])
		{
			if (av[i] == 'a')
				opt->a = 1, ret = 1;
			if (av[i] == 'l')
				opt->l = 1, ret = 1;
			if (av[i] == 'r')
				opt->r = 1, ret = 1;
			if (av[i] == 't')
				opt->t = 1, ret = 1;
			if (av[i] == 'R')
				opt->R = 1, ret = 1;
			i++;
		}
	}
	return (1);
}

int		check_options(t_opt *opt, char **av, int ac)
{
	int i;
	int ret;

	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1])
			ret = init_options(opt, av[i]);
		i++;
	}
	return (ret);
}
