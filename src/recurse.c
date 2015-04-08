/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 14:23:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/08 02:55:49 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	get_types(mode_t mode)
{
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISCHR(mode))
		return ('c');
	return (0);
}

void	test_recurse(t_infos *lst, t_opt *opt, char *originpath)
{
	t_infos	*tmp;
	t_infos	*recurse;
	int i;
	//char	*temp;
	// t_infos	*templist;

	tmp = lst;
	if (!tmp)
		return ;
	if (lstat(tmp->path, &tmp->stat) == -1)
		return ;
	if (!is_parent_or_current(tmp->name) && get_types(tmp->stat.st_mode) == 'd')
	{
		recurse = create_lst(tmp->path);
		if (recurse)
		{
			ft_printf("%s:\n", tmp->path);
			recurse = sort_maj(recurse);
			display_lst(recurse, opt);
			write(1, "\n", 1);
			test_recurse(recurse, opt, originpath);
		}
	}
	test_recurse(tmp->next, opt, originpath);
}

t_infos	*create_lst(char *path)
{
	t_dirent	*dirp;
	t_infos		*new;
	DIR 		*dir;
	char 		*str;

	ft_printf("path: %s\n", path);
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_strjoin(path, "/");
	// ft_printf("path: %s\n", path);
	if (!(dir = opendir(path)))
		ft_printf("opendir error\n");
	new = NULL;
	while ((dirp = readdir(dir)) != NULL)
	{
		str = ft_strjoin(path, dirp->d_name);
		lst_add_elem_back(&new, lst_create_elem(str, dirp->d_name));
	}
	if ((closedir(dir)) == -1)
		ft_printf("error closedir\n");
	return (new);
}

// void	test_recurse(t_infos *lst, t_opt *opt)
// {
// 	t_infos	*tmp;
// 	t_infos	*recurse;

// 	tmp = lst;
// 	//ft_printf("entry: %s\n", tmp->name);
// 	// ft_printf("path : %s\n", tmp->path);
// 	if (tmp == NULL)
// 		return ;
// 	if (lstat(tmp->path, &tmp->stat) == -1)
// 		return ;
// 	// if (tmp->d == 1 && !is_parent_or_current(tmp->name))
// 	if (ft_strcmp(tmp->name, ".") != 0 && ft_strcmp(tmp->name, "..") != 0 && get_types(tmp->stat.st_mode) == 'd')
// 	{
// 		ft_printf("dirname: %s\n", tmp->name);
// 		recurse = create_lst(tmp->path);
// 		if (recurse)
// 		{
// 			display_lst(recurse, opt);
// 			//display_recurse(tmp->path, recurse, opt);
// 			test_recurse(recurse, opt);
// 		}
// 		del_lst(&recurse);
// 	}
// 	test_recurse(tmp->next, opt);
// }

// t_infos	*create_lst(char *path)
// {
// 	t_dirent	*dirp;
// 	t_infos		*new;
// 	DIR 		*dir;
// 	char 		*str;

// 	if (path[ft_strlen(path) - 1] != '/')
// 		path = ft_strjoin(path, "/");
// 	//ft_printf("path: %s\n", path);
// 	if (!(dir = opendir(path)))
// 		ft_printf("opendir error\n");
// 	new = NULL;
// 	while ((dirp = readdir(dir)) != NULL)
// 	{
// 		str = ft_strjoin(path, dirp->d_name);
// 		lst_add_elem_back(&new, lst_create_elem(str, dirp->d_name));
// 	}
// 	if ((closedir(dir)) == -1)
// 		ft_printf("error closedir\n");
// 	// write(1, "YOLO\n", 6);
// 	return (new);
// }
