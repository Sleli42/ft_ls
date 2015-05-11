/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 14:23:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/11 02:43:02 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	create_and_del_recurse(t_all *all, t_opt *opt)
{
	t_all 	*recurse;
	t_all 	*tmp;

	tmp = all;
	recurse = create_lst(tmp->content->path);
	if ((tmp->content->stat.st_mode & S_IROTH) == 0)
		display_recurse(tmp->content->path, recurse, opt, 1);
	else
		display_recurse(tmp->content->path, recurse, opt, 0);
	if (recurse)
	{
		test_recurse(recurse = (opt->r) ?
			goto_last_elem(recurse) : recurse, opt);
		del_lst(recurse);
	}
}

void	test_recurse(t_all *lst, t_opt *opt)
{
	t_all	*tmp;
	t_all	*recurse;

	recurse = NULL;
	tmp = lst;
	if (!tmp)
		return ;
	if (lstat(tmp->content->path, &tmp->content->stat) == -1)
		return ;
	if (tmp->content->is_dir == 1
		&& get_type(tmp->content->stat.st_mode) == 'd'
		&& is_parent_or_current(tmp->content->name) == 0)
	{
		if (opt->a != 1)
		{
			if (tmp->content->name[0] != '.')
			{
				create_and_del_recurse(tmp, opt);
			}
			else
				test_recurse((opt->r) ? tmp->prev : tmp->next, opt);
		}
		else
			create_and_del_recurse(tmp, opt);
	}
	test_recurse((opt->r) ? tmp->prev : tmp->next, opt);
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
		return (NULL);
	new = NULL;
	while ((dirp = readdir(dir)) != NULL)
	{
		str = ft_strjoin(path, dirp->d_name);
		lst_add_elem_back(&new, lst_create_elem(add_statfile(str,
		 dirp->d_name)));
	}
	ft_strdel(&str);
	if ((closedir(dir)) == -1)
		return (NULL);
	return (new);
}
