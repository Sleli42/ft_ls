/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 14:23:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/29 23:47:48 by lubaujar         ###   ########.fr       */
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

void	recurse_directory(t_infos *infos, char *path, DIR *dir)
{
	t_dirent	*dirp;
	t_stat		buff;
	char		*str;

	//ft_printf("path recu: %s\n", path);
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_strjoin(path, "/");
	//ft_printf("path: %s\n", path);
	while ((dirp = readdir(dir)) != NULL)
	{
		str = ft_strjoin(path, dirp->d_name);
		//ft_printf("[lstat] pathfile: |%s|\n", str);
		if (lstat(str, &buff) == -1)
			ft_printf("error\n");
		//ft_printf("file: %s\n", dirp->d_name);
		if (get_types(buff.st_mode) == 'd' && ft_strncmp(dirp->d_name, ".", 1) != 0)
		{
			ft_printf("DIR: %s\n", dirp->d_name);
			infos->path = ft_strjoin(path, dirp->d_name);
			infos->path = ft_strjoin(infos->path, "/");
			//ft_printf("path to recurse: %s\n", all->infos.path);
			//display_name(all, dirp, dir);
			if (get_types(buff.st_mode) == 'd' && !ft_strncmp(dirp->d_name, ".", 1))
				return (recurse_directory(infos, infos->path, dir));
			else
				infos->path  = "./";
		}
	}
	closedir(dir);
}
