/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 19:08:57 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/19 02:20:43 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_maxlen		*init_len(void)
{
	t_maxlen	*new;

	if ((new = (t_maxlen*)malloc(sizeof(t_maxlen))) == NULL)
		return (NULL);
	new->link = 0;
	new->octet = 0;
	new->uid = 0;
	new->gid = 0;
	return (new);
}

t_infos			*init_data_null(void)
{
	t_infos	*data;

	if (!(data = (t_infos *)malloc(sizeof(t_infos))))
		return (NULL);
	data->path = NULL;
	data->name = NULL;
	data->lnk_name = NULL;
	data->date = NULL;
	data->timesec = 0;
	data->rights = NULL;
	data->link = NULL;
	data->size = NULL;
	data->s_uid = NULL;
	data->i_uid = 0;
	data->s_gid = NULL;
	data->i_gid = 0;
	data->inode = NULL;
	data->is_dir = 0;
	data->blksize = 0;
	data->err = 0;
	return (data);
}

void			long_data(t_infos *new, t_stat buff, t_opt *opt)
{
	if (get_type(buff.st_mode) == 'b'
		|| get_type(buff.st_mode) == 'c')
		new->size = major_minor_to_str(&buff);
	else
		new->size = ft_itoa_long(buff.st_size);
	if (opt->n)
	{
		new->i_uid = (int)buff.st_uid;
		new->i_gid = (int)buff.st_gid;
	}
	else
	{
		if (!(getpwuid(buff.st_uid)))
			new->s_uid = ft_itoa(buff.st_uid);
		else
			new->s_uid = ft_strdup(getpwuid(buff.st_uid)->pw_name);
		if (!(getgrgid(buff.st_gid)))
			new->s_gid = ft_itoa(buff.st_gid);
		else
			new->s_gid = ft_strdup(getgrgid(buff.st_gid)->gr_name);
	}
	if (opt->i)
		new->inode = ft_itoa_long(buff.st_ino);
	new->blksize = buff.st_blocks;
}

t_infos			*data_init(char *filename, char *path, t_opt *opt)
{
	t_infos		*new;
	t_stat		buff;
	char		*buf;

	new = init_data_null();
	if (lstat(path, &buff) < 0)
	{
		put_error_file_dir(filename);
		return (NULL);
	}
	if (path[ft_strlen(path) - 1] != '/')
		new->path = ft_strjoin(path, "/");
	else
		new->path = ft_strdup(path);
	if (opt->big_f)
		new->name = add_char_file(filename, buff);
	else
		new->name = ft_strdup(filename);
	if (get_type(buff.st_mode) == 'l')
	{
		buf = ft_strnew(221);
		new->lnk_name = add_symb_link(path, buf);
	}
	extended_data_init(new, buff, opt);
	return (new);
}

t_opt			*init_opt(void)
{
	t_opt	*opt;

	opt = (t_opt *)malloc(sizeof(t_opt));
	if (opt == NULL)
		return (NULL);
	opt->a = 0;
	opt->big_a = 0;
	opt->l = 0;
	opt->big_f = 0;
	opt->t = 0;
	opt->i = 0;
	opt->n = 0;
	opt->r = 0;
	opt->big_r = 0;
	opt->big_s = 0;
	return (opt);
}
