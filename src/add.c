/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 02:36:49 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/14 03:30:44 by lubaujar         ###   ########.fr       */
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
	if (dirp->d_type == DT_DIR)
		infos->is_dir = 1;
	return (infos);
}
