/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:08:09 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/25 03:05:41 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	read_directory(t_all *all)
{
	t_dirent	*dirp;
	DIR			*dir;

	if (all->infos.path == NULL)
		all->infos.path = "./";
	if (!(dir = opendir(all->infos.path)))
		return ;
	while ((dirp = readdir(dir)) != NULL)
	{
		all->infos.name = ft_strdup(dirp->d_name);
		lst_add_elem(&all->infos, dirp->d_name);
	}
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
	init_infos(&all);
	if (ac > 1)
	{
		if (check_options(&all, av) == 1)
			all.infos.path = ft_strdup(av[2]);
		else
			all.infos.path = ft_strdup(av[1]);
		read_directory(&all);
	}
	return (0);
}
