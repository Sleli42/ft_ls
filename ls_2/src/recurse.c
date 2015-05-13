/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 03:30:19 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/13 01:27:11 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void 	recurse_dir(t_all *dirs, t_opt *opt)
{
	t_all 	*nav;
	t_all 	*recurse;

	nav = (opt->r) ? goto_last_elem(dirs) : dirs;
	recurse = NULL;
	while (nav)
	{
		if (!is_parent_or_current(nav->content->name) && nav->content->is_dir)
		{
			recurse = open_directory(opt, nav->content->path);
			if (recurse)
			{
				sort_lists(&recurse, opt);
				ft_putendl(nav->content->path);
				display_lst(recurse, opt);
				write(1, "\n", 1);
				recurse_dir(recurse, opt);
				del_lst(recurse);
			}
		}
		nav = (opt->r) ? nav->prev : nav->next;
	}
}

t_all 	*recurse_to_dir(t_opt *opt, char *dir_name)
{
	t_all 		*list;
	t_dirent 	*dirp;
	DIR 		*entry;
	char 		*path;

	list = NULL;
	if (!is_parent_or_current(dir_name))
	{
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
	}
	return (list);
}
