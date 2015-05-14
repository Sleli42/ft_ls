/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 03:30:19 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/14 18:25:35 by lubaujar         ###   ########.fr       */
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
		if (!is_parent_or_current(nav->content->name) && nav->content->is_dir
			&& nav->content->err == 0)
		{
			recurse = recurse_to_dir(opt, nav->content->path);
			if (recurse)
			{
				sort_lists(&recurse, opt);
				if (nav->content->path[ft_strlen(nav->content->path) - 1] == '/')
					nav->content->path[ft_strlen(nav->content->path) - 1] = ':';
				ft_putendl(nav->content->path);
				display_lst(recurse, opt);
				if ((opt->r) ? nav->prev != NULL : nav->next != NULL)
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
		{
			if (ft_strcmp(dir_name, "/dev/fd/3/") == 0)
			{
				ft_putendl(dir_name);
				put_error_dev(42);
			}
			else
				err();
		}
		while ((dirp = readdir(entry)) != NULL)
		{
			path = ft_strjoin(dir_name, dirp->d_name);
			list_elem(&list, opt, dirp->d_name, path);
			ft_strdel(&path);
		}
		if (closedir(entry) == -1)
			err();
	}
	return (list);
}
