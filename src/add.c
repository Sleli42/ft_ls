/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 02:36:49 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/08 18:52:12 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_infos 	*add_statfile(char *path, char *filename)
{
	t_infos *infos;
	struct passwd	*uid;
 	struct group 	*gid;

	if (path == NULL || filename == NULL)
		ft_error("add_statfile 1", 3);
	infos = (t_infos*)malloc(sizeof(t_infos));
	infos->path = ft_strdup(path);
	infos->name = ft_strdup(filename);
	if (lstat(infos->path, &infos->stat) == -1)
		ft_error("add_statfile 2", 3);
	if (get_type(infos->stat.st_mode) == 'd')
		infos->is_dir = 1;
	uid = getpwuid(infos->stat.st_uid);
	gid = getgrgid(infos->stat.st_gid);
	infos->s_uid = ft_strdup(uid->pw_name);
	infos->s_gid = ft_strdup(gid->gr_name);
	infos->rights = ft_strdup(get_rights(infos->stat.st_mode));
	infos->date = ft_strdup(cut_date(ctime(&(infos->stat.st_mtime))));
	infos->link = ft_strdup(ft_itoa(infos->stat.st_nlink));
	if (get_type(infos->stat.st_mode) == 'b'
		|| get_type(infos->stat.st_mode) == 'c')
		infos->size = ft_strdup(major_minor_to_str(&infos->stat));
	else
		infos->size = ft_strdup(ft_itoa(infos->stat.st_size));
	infos->blksize = infos->stat.st_blocks;
	return (infos);
}
