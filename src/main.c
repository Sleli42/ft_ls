/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:08:09 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/03 16:34:08 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	read_directory(t_all *all)
{
	DIR			*dir;

	if (all->infos.path == NULL)
		all->infos.path = "./";
	if (!(dir = opendir(all->infos.path)))
		return ;
	if (all->opt.R == 1)
	{
		recurse_directory(all, all->infos.path, dir);
		/*
		while ((entry = readdir(dir)))
			printf("name: %s\n", entry->d_name);
		closedir(dir);
		*/
	}
}

int		main(int ac, char **av)
{
	t_all	all;

	init_options(&all);
	all.infos.path = NULL;
	if (ac > 1)
	{
		if (check_options(&all, av) == 1)
			all.infos.path = create_path_directory(av[2]);
		else
			all.infos.path = create_path_directory(av[1]);
		read_directory(&all);
	}
	return (0);
}
