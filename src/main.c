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
	t_infos		*lst;
	DIR			*dir;

	if (!(lst = (t_infos *)malloc(sizeof(t_infos))))
		ft_printf("malloc error\n");
	if (all->infos.path == NULL)
		all->infos.path = "./";
	if (!(dir = opendir(all->infos.path)))
		return ;
	lst = NULL;
	while ((dirp = readdir(dir)) != NULL)
	{
		//ft_printf("dirp->d_name: %s\n", dirp->d_name);
		lst_add_elem_back(&lst, lst_create_elem(
			ft_strjoin(all->infos.path, dirp->d_name), dirp->d_name));
	}
	test_statfile(lst);
	//display_lst(lst);
	if (all->opt.R == 1)
	{
		//recurse_directory(all, all->infos.path, dir);
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

	init_all(&all);
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
