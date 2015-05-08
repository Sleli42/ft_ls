/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 14:23:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/08 19:01:12 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

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
	//ft_printf("nb = %d\n", (tmp->content->stat.st_mode & S_IROTH));
	if (tmp->content->is_dir == 1 && is_parent_or_current(tmp->content->name) == 0
		&& get_type(tmp->content->stat.st_mode) == 'd')
		//&& (tmp->content->stat.st_mode & S_IRUSR) != 0
	{
		// if (tmp->content->stat.st_mode & S_ISVTX)
		// 	ft_printf("STICKYBIT\n");
		//if (is_parent_or_current(tmp->content->name) != 1)
		//{
			// if (opt->a != 1 && tmp->content->name[0] == '.')
			// 	tmp = (opt->r) ? tmp->prev : tmp->next;
			// else
			// {
				recurse = create_lst(tmp->content->path);
				display_recurse(tmp->content->path, recurse, opt);
				if (recurse)
				{
					//ft_printf("yolooo\n");
					test_recurse(recurse = (opt->r) ?
						goto_last_elem(recurse) : recurse, opt);
				}
				del_lst(recurse);
			//}
		//}
	}
	test_recurse(tmp = (opt->r) ? tmp->prev : tmp->next, opt);
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
		 dirp->d_name, dirp)));
	}
	ft_strdel(&str);
	if ((closedir(dir)) == -1)
		return (NULL);
	return (new);
}
