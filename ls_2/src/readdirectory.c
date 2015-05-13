/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdirectory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 02:20:50 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/13 01:23:57 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void 	read_files(t_all **args, t_opt *opt)
{
	t_all 	*nav;
	t_all 	*files;

	nav = *args;
	files = NULL;
	while (nav && !nav->content->is_dir)
	{
		list_elem(&files, opt, nav->content->name, nav->content->path);
		nav = nav->next;
	}
	if (files)
	{
		sort_lists(&files, opt);
		display_lst(files, opt);
		del_lst(files);
	}
	if (nav)
		read_dirs(nav, opt);
}

void 	read_dirs(t_all *args_dir, t_opt *opt)
{
	t_all 	*nav;
	t_all 	*dirs;

	nav = (opt->r) ? goto_last_elem(args_dir) : args_dir;
	while (nav)
	{
		if (nav->content->is_dir)
		{
			dirs = open_directory(opt, nav->content->path);
			sort_lists(&dirs, opt);
			display_lst(dirs, opt);
			if (opt->R)
				recurse_dir(dirs, opt);
			del_lst(dirs);
		}
		nav = (opt->r) ? nav->prev : nav->next;
	}
}

t_all 	*open_directory(t_opt *opt, char *dir_name)
{
	t_all 		*list;
	t_dirent 	*dirp;
	DIR 		*entry;
	char 		*path;

	list = NULL;
	if (!(entry = opendir(dir_name)))
		printf("error [open.directory] -> opendir\n"), exit(1);
	while ((dirp = readdir(entry)) != NULL)
	{
		path = ft_strjoin(dir_name, dirp->d_name);
		list_elem(&list, opt, dirp->d_name, path);
		ft_strdel(&path);
	}
	if (closedir(entry) == -1)
		printf("error [open.directory] -> closedir\n"), exit(1);
	return (list);
}
