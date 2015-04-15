/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 14:23:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/16 01:33:40 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	test_recurse(t_all *lst, t_opt *opt)
{
	t_all	*tmp;
	t_all	*recurse;

	tmp = lst;
	recurse = NULL;
	if (!tmp)
		return ;
	if (lstat(tmp->content->path, &tmp->content->stat) == -1)
		return ;
	if (tmp->content->is_dir == 1
		&& get_type(tmp->content->stat.st_mode) == 'd')
	{
		if (is_parent_or_current(tmp->content->name) != 1)
		{
			if (opt->a != 1 && tmp->content->name[0] == '.')
				tmp = tmp->next;
			else
			{
				recurse = create_lst(tmp->content->path);
				display_recurse(tmp->content->path, recurse, opt);
				if (recurse)
					test_recurse(recurse, opt), del_lst(recurse);
			}
		}
	}
	test_recurse(tmp->next, opt);
}

t_all	*create_lst(char *path)
{
	t_dirent	*dirp;
	t_all		*new;
	DIR 		*dir;
	char 		*str;

	if (path[ft_strlen(path) - 1] != '/')
		path = ft_strjoin(path, "/");
	if (!(dir = opendir(path)))
		ft_printf("opendir error\n");
	new = (t_all *)malloc(sizeof(t_all));
	new = NULL;
	while ((dirp = readdir(dir)) != NULL)
	{
		str = ft_strjoin(path, dirp->d_name);
		lst_add_elem_back(&new, lst_create_elem(add_statfile(str,
		 dirp->d_name, dirp)));
		ft_strdel(&str);
	}
	if ((closedir(dir)) == -1)
		ft_printf("error closedir\n");
	return (new);
}
