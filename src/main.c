/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:08:09 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/11 20:20:30 by lubaujar         ###   ########.fr       */
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

	lst = NULL;
	if (all->content->path[ft_strlen(all->content->path) - 1] != '/')
		all->content->path= ft_strjoin(all->content->path, "/");
	if (!(dir = opendir(all->content->path)))
		return ;
	while ((dirp = readdir(dir)) != NULL)
	{
		tmp = ft_strjoin(all->content->path, dirp->d_name);
		lst_add_elem_back(&lst, lst_create_elem(add_statfile(tmp, dirp->d_name)));
		ft_strdel(&tmp);
	}
	ft_strdel(&all->content->path);
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

void	list_args(t_all **args, char *filename, char *path)
{

}

int		main(int ac, char **av)
{
	t_opt		*opt;
	t_all 		*all;
	t_all 		*args;
	int 		i;

	i = 1;
	init(opt, all);
	i += check_options(&opt, av, ac);
	if (i == ac)
	{
		list_args(&args, ".", ".");
	}
	else
	{
		while (i < ac)

	}
	return (0);
}
