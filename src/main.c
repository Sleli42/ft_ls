/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:08:09 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/23 11:43:18 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	read_directory(t_opt *opt, t_all *all)
{
	t_dirent	*dirp;
	t_all		*lst;
	DIR			*dir;
	char		*tmp;

	lst = (t_all *)malloc(sizeof(t_all));
	lst = NULL;
	if (all->content->path == NULL)
		all->content->path = ft_strdup("./");
	if (all->content->path[ft_strlen(all->content->path) - 1] != '/')
		all->content->path= ft_strjoin(all->content->path, "/");
	if (!(dir = opendir(all->content->path)))
		return ;
	while ((dirp = readdir(dir)) != NULL)
	{
		tmp = ft_strjoin(all->content->path, dirp->d_name);
		lst_add_elem_back(&lst, lst_create_elem(
			add_statfile(tmp, dirp->d_name, dirp)));
	}
	displays(lst, opt);
	if (opt->R == 1)
	{
		if (opt->r)
			lst = goto_last_elem(lst);
		test_recurse(lst, opt);
	}
	if ((closedir(dir)) == -1)
		return ;
	del_lst(lst);
}

void 	check_if_file(t_all *all, t_opt *opt, char **av, int ac)
{
	t_infos 	*file;

	if (lstat(all->content->path, &all->content->stat) != -1 /* si c'est un fichier */
		&& S_ISREG(all->content->stat.st_mode))
	{
		if (opt->l == 1)
		{
			file = add_statfile(all->content->path, all->content->path, NULL);
			display_infos(file);
		}
		else
			ft_printf("%s\n", av[ac - 1]);
	}
}

int		main(int ac, char **av)
{
	t_opt		opt;
	t_all 		all;
	int 	i;
									/* multi directory */
	i = count_dir(ac, av);
	init(&opt, &all);
	if (check_options(&opt, av, ac) == -1)
		exit (1);
	if (ac == 1)
		all.content->path = ft_strdup(".");
	else if (ac > 1)
	{
		if (av[ac - 1][0] != '-')
			all.content->path = ft_strdup(av[ac - 1]);
	}
	check_if_file(&all, &opt, av, ac);
	read_directory(&opt, &all);
	return (0);
}
