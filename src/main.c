/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:08:09 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/22 22:11:48 by lubaujar         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_opt		opt;
	t_all 		all;
	t_infos 	*file;
	//t_dirent 	*dirp;
	int 	i;
									/* multi directory */
	i = 0;
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
	if (lstat(all.content->path, &all.content->stat) != -1
		&& S_ISREG(all.content->stat.st_mode))
	{
		if (opt.l == 1)
		{
			file = add_statfile(all.content->path, all.content->path, NULL);
			display_infos(file);
		}
		else
			ft_printf("%s\n", av[ac - 1]);
	}
	read_directory(&opt, &all);
	return (0);
}
