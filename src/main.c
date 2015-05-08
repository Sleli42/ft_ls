/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:08:09 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/08 18:36:47 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_error(char *err, int ex)
{
	if (err && *err)
		ft_putendl(err);
	if (ex)
		exit(ex);
}

void	read_directory(t_opt *opt, t_all *all)
{
	t_dirent	*dirp;
	t_all		*lst;
	DIR			*dir;
	char		*tmp;

	//lst = NULL;
	//lst = (t_all *)malloc(sizeof(t_all));
	lst = NULL;
	if (all->content->path[ft_strlen(all->content->path) - 1] != '/')
		all->content->path= ft_strjoin(all->content->path, "/");
	if (!(dir = opendir(all->content->path)))
		return ;
	while ((dirp = readdir(dir)) != NULL)
	{
		tmp = ft_strjoin(all->content->path, dirp->d_name);
		lst_add_elem_back(&lst, lst_create_elem(add_statfile(tmp, dirp->d_name, dirp)));
	}
	ft_strdel(&tmp);
	//test_major_minor(lst);
	 //exit(1);


	/* sticky bit (background jaune) */


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

void 	display_alone_file(t_all *all, t_opt *opt, char **av, int ac)
{
	t_infos 	*file;

	if (opt->l == 1)
	{
		file = add_statfile(all->content->path, all->content->path, NULL);
		display_infos(file);
	}
	else
		ft_printf("%s\n", av[ac]);
}

void 	list_file(t_all *all, t_opt *opt, char **av, int ac, int i)
{
	while (i < ac)
	{
		if (av[i][0] != '-')
		{
			all->content->path = ft_strdup(av[i]);
			if (lstat(all->content->path, &all->content->stat) != -1
				&& S_ISREG(all->content->stat.st_mode))
				display_alone_file(all, opt, av, i);
		}
		i++;
	}
}

void 	list_dir(t_all *all, t_opt *opt, char **av, int ac, int i)
{
	int 	ct;

	ct = count_dir(ac, av);
	while (i < ac)
	{
		if (av[i][0] != '-')
		{
			all->content->path = ft_strdup(av[i]);
			if (lstat(all->content->path, &all->content->stat) != -1
				&& S_ISDIR(all->content->stat.st_mode))
			{
				if (ct > 1)
					ft_printf("\n%s:\n", av[i]);
				read_directory(opt, all);
			}
			ft_strdel(&all->content->path);
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	t_opt		opt;
	t_all 		all;
	int 		i;
									/* multi directory */
	// ft_printf("nb de dirs: %d\n", i);
	// exit (1);
	i = 1;
	init(&opt, &all);
	i += check_options(&opt, av, ac);
	if (i == ac)
	{
		//write(1, "yolo\n", 5);
		all.content->path = ft_strdup(".");
		read_directory(&opt, &all);
	}
	else
	{
		list_file(&all, &opt, av, ac, i);
		list_dir(&all, &opt, av, ac, i);
	}
	return (0);
}
