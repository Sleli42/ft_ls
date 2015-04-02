/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 14:23:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/02 02:20:56 by lubaujar         ###   ########.fr       */
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

void	recurse_dir(t_infos *lst)
{
	t_infos	*tmp;
	t_infos	*jok;

	tmp = lst;
	jok = NULL;
	while (tmp != NULL)
	{
		if (lstat(tmp->path, &tmp->stat) == -1)
			ft_printf("error lstat\n");
		if (get_types(tmp->stat.st_mode) == 'd'
			&& !is_parent_or_current(tmp->name))
		{
			ft_printf("dir: %s\n", tmp->name);
			check_another_dir(tmp->path);
		}
		tmp = tmp->next;
	}
}

void 	check_another_dir(char *path)
{
	t_dirent	*dirp;
	t_stat		stat;
	DIR 		*dir;
	static int 	i = -1;
	int 		ret;

	i++;
	ret = 0;
	path = ft_strjoin(path, "/");
	ft_printf("%s\n", path);
	if (!(dir = opendir(path)))
		ft_printf("error opendir\n");
	while ((dirp = readdir(dir)) != NULL)
	{
		if (lstat(ft_strjoin(path, dirp->d_name), &stat))
			ft_printf("error lstat\n");
		if (get_types(stat.st_mode) == 'd'
			&& !is_parent_or_current(dirp->d_name))
		{
			// ret = 1;
			ft_printf("\toth dir: %s\n", dirp->d_name);
			check_another_dir(ft_strjoin(path, dirp->d_name));
		}
	}
	closedir(dir);
	// if (ret == 1)
	// 	check_another_dir(ft_strjoin(path, dirp->d_name));
}

t_infos	*create_lst(char *path)
{
	t_dirent	*dirp;
	t_infos		*new;
	DIR 		*dir;

	if (!(dir = opendir(ft_strjoin(path, "/"))))
		ft_printf("opendir error\n");
	new = NULL;
	while ((dirp = readdir(dir)) != NULL)
	{
		lst_add_elem_back(&new, lst_create_elem(
			ft_strjoin(path, dirp->d_name), dirp->d_name));
	}
	closedir(dir);
	return (new);
}

// int 	check_if_another_dir(t_infos *lst)
// {
// 	t_infos	*tmp;

// 	tmp = lst;
// 	while (tmp)
// 	{
// 		if (lstat(tmp->path, &tmp->stat) == -1)
// 			ft_printf("error lstat\n");
// 		if (get_types(tmp->stat.st_mode) == 'd'
// 			&& !is_parent_or_current(tmp->name))
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

// void	recurse_me(t_infos *lst)
// {
// 	t_infos	*tmp;
// 	t_infos	*joker;
// 	t_infos	*recurse;

// 	tmp = lst;
// 	recurse = NULL;
// 	while (tmp != NULL)
// 	{
// 		if (lstat(tmp->path, &tmp->stat) == -1)
// 			ft_printf("error lstat\n");
// 		if (get_types(tmp->stat.st_mode) == 'd'
// 			&& !is_parent_or_current(tmp->name))
// 		{
// 			ft_printf("\ndir: %s\n", tmp->name);
// 			recurse = create_lst(tmp->path);
// 			display_lst(recurse);
// 			if (check_if_another_dir(recurse) == 1)
// 			{
// 				joker = recurse;
// 				del_lst(&recurse);
// 				recurse_me(joker);
// 			}
// 		}
// 		tmp = tmp->next;
// 	}
// }

// void	recurse_zis_dir(char *dir_name, char *path, t_dirent *dirp)
// {
// 	t_infos	*new_lst;
// 	DIR 	*dir;

// 	ft_printf("\n%s:\n", dir_name);
// 	path = ft_strjoin(path, "/");
// 	if (!(dir = opendir(path)))
// 		ft_printf("error opendir\n");
// 	//ft_printf("path: %s\n", path);
// 	new_lst = NULL;
// 	while ((dirp = readdir(dir)) != NULL)
// 	{
// 		lst_add_elem_back(&new_lst, lst_create_elem(
// 			ft_strjoin(path, dirp->d_name), dirp->d_name));
// 		// ft_printf("name: %s\n", new_lst->name);
// 	}
// 	closedir(dir);
// 	new_lst = sort_maj(new_lst);
// 	//ft_printf("curr: %s\nnext: %s\nprev: %s\n", new_lst->name,
// 	// new_lst->next->name, new_lst->prev->name);
// 	display_lst(new_lst);
// 	// check_another_dir(new_lst);
// 	while (new_lst)
// 	{
// 		if (lstat(new_lst->path, &new_lst->stat) == -1)
// 			ft_printf("error lstat\n");
// 		if (get_types(new_lst->stat.st_mode) == 'd'
// 			&& ft_strncmp(new_lst->name, ".", 1) != 0)
// 		{
// 			ft_printf("name other dir: %s\n", new_lst->name);
// 			new_lst->name = ft_strjoin("/", new_lst->name);
// 			recurse_zis_dir(new_lst->name, new_lst->path, dirp);
// 		}
// 		new_lst = new_lst->next;
// 	}
// 	del_lst(&new_lst);
// }

// void	recurse_directory(t_infos *lst, char *path)
// {
// 	char		*tmp_path;
// 	t_dirent	*dirp;
// 	t_infos		*tmp;

// 	tmp = lst;
// 	dirp = NULL;
// 	ft_printf("\n\n");
// 	if (path[ft_strlen(path) - 1] != '/')
// 		path = ft_strjoin(path, "/");
// 	// ft_printf("path: %s\n", path);
// 	while (tmp != NULL)
// 	{
// 		tmp_path = ft_strjoin(path, tmp->name);
// 		// tmp_path = ft_strjoin(tmp_path, "/");
// 		if (lstat(tmp_path, &tmp->stat) == -1)
// 			ft_printf("error lstat\n");
// 		if (get_types(tmp->stat.st_mode) == 'd' && ft_strncmp(tmp->name, ".", 1) != 0)
// 		{
// 			recurse_zis_dir(ft_strjoin(".//", tmp->name), tmp_path, dirp);
// 		}
// 		tmp = tmp->next;
// 	}
// }

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
