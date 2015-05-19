/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 19:04:19 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/19 01:51:30 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		main(int ac, char **av)
{
	t_all	*args;
	t_opt	*opt;
	int		i;

	args = NULL;
	opt = NULL;
	i = 1;
	if (!(opt = init_opt()))
		err();
	while (i < ac && av[i][0] == '-' && av[i][1])
		list_opts(opt, av[i++]);
	if (i == ac)
		list_elem(&args, opt, ".", ".");
	else
	{
		while (i < ac)
			list_elem(&args, opt, av[i], av[i]), i++;
		sort_args(&args);
	}
	read_files(&args, opt);
	free (opt);
	return (0);
}
