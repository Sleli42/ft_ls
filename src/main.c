/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:08:09 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/16 06:16:14 by lubaujar         ###   ########.fr       */
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
	sort_name(&all);
	if (opt->t == 1)
		sort_time(&all);
	displays(lst, opt);
	//write (1, "\n", 1);
	if (opt->R == 1)
	{
		test_recurse(lst, opt);
	}
	if ((closedir(dir)) == -1)
		ft_printf("error closedir\n");
}

int		main(int ac, char **av)
{
	t_opt	opt;
	t_all 	all;
	int 	i;

	i = 0;
	init(&opt, &all);
	check_options(&opt, av, ac);
	if (ac == 1)
		all.content->path = ft_strdup(".");
	else if (ac > 1)
		if (av[ac - 1][0] != '-')
			all.content->path = ft_strdup(av[ac - 1]);
	read_directory(&opt, &all);
	return (0);
}
