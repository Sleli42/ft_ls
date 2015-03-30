/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:08:09 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/30 17:40:26 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	read_directory(t_opt *opt, t_infos *infos)
{
	t_dirent	*dirp;
	t_infos		*lst;
	DIR			*dir;

	if (!(lst = (t_infos *)malloc(sizeof(t_infos))))
		ft_printf("malloc error\n");
	if (infos->path == NULL)
		infos->path = "./";
	if (!(dir = opendir(infos->path)))
		return ;
	lst = NULL;
	while ((dirp = readdir(dir)) != NULL)
	{
		//ft_printf("dirp->d_name: %s\n", dirp->d_name);
		lst_add_elem_back(&lst, lst_create_elem(
			ft_strjoin(infos->path, dirp->d_name), dirp->d_name));
	}
	//test_statfile(lst);
	lst = sort_maj(lst);
//	display_lst(lst);
	if (opt->R == 1)
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
	t_opt	opt;
	t_infos	infos;

	init_all(&opt, &infos);
	if (ac > 1)
	{
		if (check_options(&opt, av) == 1)
			infos.path = ft_strdup(av[2]);
		else
			infos.path = ft_strdup(av[1]);
		read_directory(&opt, &infos);
	}
	return (0);
}
