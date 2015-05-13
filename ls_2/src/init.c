/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 19:08:57 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/13 01:25:40 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	long_data(t_infos *new, t_stat buff)
{
	new->date = cut_date(ctime(&(buff.st_mtime)));
	new->rights = get_rights(buff.st_mode);
	new->link = ft_itoa(buff.st_nlink);
	if (get_type(buff.st_mode) == 'b'
		|| get_type(buff.st_mode) == 'c')
		new->size = major_minor_to_str(&buff);
	else
		new->size = ft_itoa(buff.st_size);
	new->s_uid = ft_strdup(getpwuid(buff.st_uid)->pw_name);
	new->s_gid = ft_strdup(getgrgid(buff.st_gid)->gr_name);
	new->blksize = buff.st_blocks;
}

t_infos 	*init_data_null(void)
{
	t_infos 	*data;

	if (!(data = (t_infos *)malloc(sizeof(t_infos))))
		return (NULL);
	data->path = NULL;
	data->name = NULL;
	data->date = NULL;
	data->timesec = 0;
	data->rights = NULL;
	data->link = NULL;
	data->size = NULL;
	data->s_uid = NULL;
	data->s_gid = NULL;
	data->is_dir = 0;
	data->blksize = 0;
	return (data);
}

t_infos		*data_init(char *filename, char *path, t_opt *opt)
{
	t_infos 	*new;
	t_stat		buff;
	int 		ret;

	new = init_data_null();
	ret = lstat(path, &buff);
	if (ret < 0)
		return (NULL);
	if (new == NULL)
		printf("error [data.init]\n"), exit(1);
	if (path[ft_strlen(path) - 1] != '/')
		new->path = ft_strjoin(path, "/");
	else
		new->path = ft_strdup(path);
	new->name = ft_strdup(filename);
	new->is_dir = S_ISDIR(buff.st_mode);
	new->timesec = buff.st_mtime;
	if (opt->l)
		long_data(new, buff);
	return (new);
}

t_opt 	*init_opt(void)
{
	t_opt 	*opt;

	opt = (t_opt *)malloc(sizeof(t_opt));
	if (opt == NULL)
		return (NULL);
	opt->a = 0;
	opt->l = 0;
	opt->t = 0;
	opt->r = 0;
	opt->R = 0;
	return (opt);
}
