/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 02:36:49 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/22 21:59:03 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ls.h"

t_infos 	*add_statfile(char *path, char *filename, t_dirent *dirp)
{
	t_infos *infos;

	if (path == NULL || filename == NULL)
		return (NULL);
	infos = (t_infos*)malloc(sizeof(t_infos));
	infos->path = ft_strdup(path);
	infos->name = ft_strdup(filename);
	if (dirp != NULL)
		if (dirp->d_type == DT_DIR)
			infos->is_dir = 1;
	if (lstat(infos->path, &infos->stat) == -1)
		ft_printf("[-l]error lstat\n");
	infos->uid = getpwuid(infos->stat.st_uid);
	infos->gid = getgrgid(infos->stat.st_gid);
	infos->rights = ft_strdup(get_rights(infos->stat.st_mode));
	infos->date = ft_strdup(cut_date(ctime(&(infos->stat.st_mtime))));
	infos->link = ft_strdup(ft_itoa(infos->stat.st_nlink));
	infos->size = ft_strdup(ft_itoa(infos->stat.st_size));
	infos->blksize = infos->stat.st_blocks;
	return (infos);
}
