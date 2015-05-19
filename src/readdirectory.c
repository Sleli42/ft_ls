/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdirectory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 02:20:50 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/19 01:56:29 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	read_files(t_all **args, t_opt *opt)
{
	t_all	*nav;
	int		i;

	nav = *args;
	sort_lists(&nav, opt);
	i = 0;
	while (nav && !nav->content->is_dir)
	{
		if (opt->l)
			display_statfile(nav->content, define_maxlen(*args, opt), opt), i++;
		else
			ft_putendl(nav->content->name), i++;
		nav = nav->next;
	}
	if (nav && i > 0)
		write(1, "\n", 1);
	if (nav)
		read_dirs(nav, opt);
}

void	read_dirs(t_all *args_dir, t_opt *opt)
{
	t_all	*nav;
	t_all	*dirs;

	nav = (opt->r) ? goto_last_elem(args_dir) : args_dir;
	while (nav && nav->content->is_dir)
	{
		if (len_lst(args_dir) > 1)
			ft_putstr(nav->content->name), write(1, ":\n", 2);
		if (nav->content->err == 1)
			put_error_perms(nav->content->name);
		dirs = open_directory(opt, nav->content->path);
		sort_lists(&dirs, opt);
		display_lst(dirs, opt);
		if (opt->big_r)
			write(1, "\n", 1), recurse_dir(dirs, opt);
		del_lst(dirs);
		if ((opt->r) ? nav->prev != NULL : nav->next != NULL)
			write(1, "\n", 1);
		nav = (opt->r) ? nav->prev : nav->next;
	}
	del_lst(nav);
}

t_all	*open_directory(t_opt *opt, char *dir_name)
{
	t_all		*list;
	t_dirent	*dirp;
	DIR			*entry;
	char		*path;

	list = NULL;
	if (!(entry = opendir(dir_name)))
		err();
	while ((dirp = readdir(entry)) != NULL)
	{
		path = ft_strjoin(dir_name, dirp->d_name);
		list_elem(&list, opt, dirp->d_name, path);
		ft_strdel(&path);
	}
	if (closedir(entry) == -1)
		err();
	return (list);
}
