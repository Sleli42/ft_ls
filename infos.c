/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 19:18:18 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/27 17:28:56 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	get_infos(t_stat *elem, t_statfile *stat)
{
	t_pwd	*uid;
	t_grp	*gid;
	char	*time;

	if ((uid = getpwuid(stat->st_uid)) == NULL
			|| (gid = getgrgid(stat->st_gid)) == NULL)
		return ;
	elem->rights = ft_chmod(elem->name, stat);
	elem->user = ft_strdup(uid->pw_name);
	elem->grp = ft_strdup(gid->gr_name);
	time = ft_strdup(ctime(&(stat->st_mtimespec.tv_sec)));
	elem->date = ft_strdup(cut_date(time));
}

char	*cut_date(char *time)
{
	char	*tmp;
	char	*time_ret;
	size_t	i;
	size_t	j;

	if ((tmp = ft_strnew(ft_strlen(time))) == NULL || time == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(time) + 4)
	{
		if (i >= 4)
			tmp[i - 4] = time[i];
		i++;
	}
	while (tmp[i] != ':')
		i--;
	time_ret = ft_strnew(i);
	j = -1;
	while (++j < i)
		time_ret[j] = tmp[j];
	return (time_ret);
}

char	*ft_chmod(char *file, struct stat *buff)
{
	char	*tmp;

	tmp = ft_strnew(12);	
	((S_ISREG(buff->st_mode) == 1) ? tmp[0] = '-' : 1);
	((S_ISDIR(buff->st_mode) == 1) ? tmp[0] = 'd' : 1);
	((S_ISCHR(buff->st_mode) == 1) ? tmp[0] = 'c' : 1);
	((S_ISLNK(buff->st_mode) == 1) ? tmp[0] = 'l' : 1);
	tmp[1] = buff->st_mode & S_IRUSR ? 'r' : '-';
	tmp[2] = buff->st_mode & S_IWUSR ? 'w' : '-';
	tmp[3] = buff->st_mode & S_IXUSR ? 'x' : '-';
	tmp[4] = buff->st_mode & S_IRGRP ? 'r' : '-';
	tmp[5] = buff->st_mode & S_IWGRP ? 'w' : '-';
	tmp[6] = buff->st_mode & S_IXGRP ? 'x' : '-';
	tmp[7] = buff->st_mode & S_IROTH ? 'r' : '-';
	tmp[8] = buff->st_mode & S_IWOTH ? 'w' : '-';
	tmp[9] = buff->st_mode & S_IXOTH ? 'x' : '-';
	if (listxattr(file, NULL, 5, XATTR_NOFOLLOW) > 0)
		ft_putchar('@');
	tmp[10] = ' ';
	tmp[11] = ' ';
	return (tmp);
}
