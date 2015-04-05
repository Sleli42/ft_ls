/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:08:09 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/06 01:42:26 by lubaujar         ###   ########.fr       */
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
		lst_add_elem_back(&lst, lst_create_elem(tmp, dirp->d_name));
	}
	lst = sort_maj(lst);
	display_lst(lst, opt);
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
