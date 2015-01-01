/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 08:45:28 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/27 12:23:31 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	init_opt(t_opt *opt)
{
	opt->l = 0;
	opt->a = 0;
	opt->r = 0;
	opt->t = 0;
	opt->no_option = 0;
}

void	enable_opt(t_opt *opt, char c)
{
	if (c == 'a')
		opt->a = 1;
	else if (c == 'l')
		opt->l = 1;
	else if (c == 'r')
		opt->r = 1;
	else if (c == 't')
		opt->t = 1;
}

int		check_opt(t_opt *opt, char **argv)
{
	int		i;
	int		ct;

	i = 1;
	if (argv[i])
	{
		ct = 0;
		if (argv[i][ct] == '-')
		{
			ct = ct + 1;
			while (argv[i][ct])
			{
				enable_opt(opt, argv[i][ct]);
				ct++;
			}
		}
		else
		{
			opt->no_option = 1; /* fct ls no_option */
			return (0);
		}
	}
	return (1);
}
