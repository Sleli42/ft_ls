/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 14:23:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/01 00:46:17 by lubaujar         ###   ########.fr       */
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

void	display_name(t_infos *infos, t_dirent *dirp, DIR *dir)
{
	ft_printf("parh recu: %s", infos->path);
	if (!(dir = opendir(infos->path)))
		ft_printf("ERROR\n");
	while ((dirp = readdir(dir)) != NULL)
		ft_printf("-> %s\n", dirp->d_name);
	ft_printf("quit\n");
}

void	recurse_zis_dir(char *dir_name, char *path, t_dirent *dirp)
{
	t_infos	*new_lst;
	DIR 	*dir;

	new_lst = NULL;
	ft_printf("%s:\n", dir_name);
	if (!(new_lst = (t_infos *)malloc(sizeof(t_infos))))
		ft_printf("malloc error\n");
	path = ft_strjoin(path, "/");
	if (!(dir = opendir(path)))
		ft_printf("error opendir\n");
	//ft_printf("path: %s\n", path);
	while ((dirp = readdir(dir)) != NULL)
	{
		lst_add_elem_back(&new_lst, lst_create_elem(
			ft_strjoin(path, dirp->d_name), dirp->d_name));
		// ft_printf("name: %s\n", new_lst->name);
	}
	// new_lst = sort_maj(new_lst);
	//ft_printf("curr: %s\nnext: %s\nprev: %s\n", new_lst->name,
	// new_lst->next->name, new_lst->prev->name);
	// ft_printf("%s\n", &new_lst[0].name);
	// ft_printf("%s\n", &new_lst[1].name);
	display_lst(new_lst);
	//del_lst(new_lst);
}

void	recurse_directory(t_infos *lst, char *path)
{
	char		*tmp_path;
	t_dirent	*dirp;
	t_infos		*tmp;

	tmp = lst;
	dirp = NULL;
	ft_printf("\n\n");
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_strjoin(path, "/");
	// ft_printf("path: %s\n", path);
	while (tmp != NULL)
	{
		tmp_path = ft_strjoin(path, tmp->name);
		// tmp_path = ft_strjoin(tmp_path, "/");
		if (lstat(tmp_path, &tmp->stat) == -1)
			ft_printf("error lstat\n");
		if (get_types(tmp->stat.st_mode) == 'd' && ft_strncmp(tmp->name, ".", 1) != 0)
			recurse_zis_dir(tmp->name, tmp_path, dirp);
		tmp = tmp->next;
	}
}

// void	recurse_directory(t_infos *infos, char *path, DIR *dir)
// {
// 	t_dirent	*dirp;
// 	t_stat		buff;
// 	char		*str;

// 	//ft_printf("path recu: %s\n", path);
// 	if (path[ft_strlen(path) - 1] != '/')
// 		path = ft_strjoin(path, "/");
// 	//ft_printf("path: %s\n", path);
// 	while ((dirp = readdir(dir)) != NULL)
// 	{
// 		str = ft_strjoin(path, dirp->d_name);
// 		//ft_printf("[lstat] pathfile: |%s|\n", str);
// 		if (lstat(str, &buff) == -1)
// 			ft_printf("error\n");
// 		//ft_printf("file: %s\n", dirp->d_name);
// 		if (get_types(buff.st_mode) == 'd' && ft_strncmp(dirp->d_name, ".", 1) != 0)
// 		{
// 			ft_printf("DIR: %s\n", dirp->d_name);
// 			infos->path = ft_strjoin(path, dirp->d_name);
// 			infos->path = ft_strjoin(infos->path, "/");
// 			//ft_printf("path to recurse: %s\n", all->infos.path);
// 			//display_name(all, dirp, dir);
// 			if (get_types(buff.st_mode) == 'd' && !ft_strncmp(dirp->d_name, ".", 1))
// 				return (recurse_directory(infos, infos->path, dir));
// 			else
// 				infos->path  = "./";
// 		}
// 	}
// 	closedir(dir);
// }
