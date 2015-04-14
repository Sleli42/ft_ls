/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:08:09 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/14 05:09:13 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	read_directory(t_opt *opt, t_all *all)
{
	t_dirent	*dirp;
	t_all		*lst;
	t_infos 	*new;
	DIR			*dir;
	char		*tmp;

	lst = (t_all *)malloc(sizeof(t_all));
	if (all->content->path== NULL)
		all->content->path= "./";
	if (all->content->path[ft_strlen(all->content->path) - 1] != '/')
		all->content->path= ft_strjoin(all->content->path, "/");
	if (!(dir = opendir(all->content->path)))
		return ;
	while ((dirp = readdir(dir)) != NULL)
	{
		new = add_statfile(tmp, dirp->d_name, dirp);
		tmp = ft_strjoin(all->content->path, dirp->d_name);
		lst_add_elem_back(&lst, lst_create_elem(new));
	}
	//test_lst(lst);
	//ft_printf("name: %s\npath: %s\n", lst->content->name, lst->content->path);
	display_lst2(lst, opt);
	//display_lst(lst, opt);
	exit (1);
	if (opt->R == 1)
		test_recurse(lst, opt);
	if ((closedir(dir)) == -1)
		ft_printf("error closedir\n");
}

int		main(int ac, char **av)
{
	t_opt	opt;
	t_all 	all;

	init(&opt, &all);
	check_options(&opt, av);
	if (ac > 1)
	{
		if (opt.no_opt == 0)
			all.content->path= ft_strdup(av[2]);
		else
			all.content->path= ft_strdup(av[1]);
		read_directory(&opt, &all);
	}
	return (0);
}
