/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:08:09 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/13 01:46:43 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	read_directory(t_opt *opt, t_infos *infos)
{
	t_dirent	*dirp;
	t_infos		*lst;
	DIR			*dir;
	char		*tmp;

	if (infos->path == NULL)
		infos->path = "./";
	if (infos->path[ft_strlen(infos->path) - 1] != '/')
		infos->path = ft_strjoin(infos->path, "/");
	if (!(dir = opendir(infos->path)))
		return ;
	lst = NULL;
	while ((dirp = readdir(dir)) != NULL)
	{
		tmp = ft_strjoin(infos->path, dirp->d_name);
		lst_add_elem_back(&lst, lst_create_elem(tmp, dirp->d_name, dirp));
	}
	// test_dir2(lst);
	// return ;
	//lst = sort_maj(lst);				/* --> GROS probleme de tri */
	// test_sort(&lst);
	// return ;
	display_lst(lst, opt);
	// lst = sort_name(&lst);
	// write(1, "\n", 1);
	// display_lst(lst, opt);
	// return ;
	if (opt->R == 1)
		test_recurse(lst, opt);
	if ((closedir(dir)) == -1)
		ft_printf("error closedir\n");
}

int		main(int ac, char **av)
{
	t_opt	opt;
	t_infos	infos;

	init_all(&opt, &infos);
	check_options(&opt, av);
	if (ac > 1)
	{
		if (opt.no_opt == 0)
			infos.path = ft_strdup(av[2]);
		else
			infos.path = ft_strdup(av[1]);
		read_directory(&opt, &infos);
	}
	return (0);
}
