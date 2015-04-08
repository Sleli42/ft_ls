/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:08:09 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/08 02:55:45 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"


void	test_path(t_infos *lst)
{
	t_infos *tmp;

	tmp = lst;
	while (tmp)
	{
		ft_printf("path: %s\n", tmp->path);
		tmp = tmp->next;
	}
}

void	test_opt(t_opt *opt)
{
	ft_printf("opt->%c = %d\n", 'a', opt->a);
	ft_printf("opt->%c = %d\n", 'l', opt->l);
	ft_printf("opt->%c = %d\n", 'r', opt->r);
	ft_printf("opt->%c = %d\n", 't', opt->t);
	ft_printf("opt->%c = %d\n", 'R', opt->R);
}

void	test_dir(t_infos *lst)
{
	t_infos	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->next == NULL)
			ft_printf("lastpath: %s\n", tmp->path);
		 tmp = tmp->next;
	}
}

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
		test_recurse(lst, opt, infos->path);
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
