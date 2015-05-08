/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 03:58:30 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/08 18:42:11 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void 	define_maxlen(t_all **alst)
{
	t_all 	*tmp;
	int 	maxlen_link;
	int  	maxlen_size;
	int 	maxlen_uid;
	int 	maxlen_gid;

	tmp = *alst;
	maxlen_link = search_max_link(tmp);
	maxlen_size = search_max_size(tmp);
	maxlen_uid = search_max_uid(tmp);
	maxlen_gid = search_max_gid(tmp);
	modif_link(alst, maxlen_link);
	modif_size(alst, maxlen_size);
	modif_uid(alst, maxlen_uid);
	modif_gid(alst, maxlen_gid);
}

char	get_type(mode_t mode)
{
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISFIFO(mode))
		return ('f');
	return (0);
}

int		is_parent_or_current(char *name)
{
	// if  (ft_strcmp(name, ".") == 0 || ft_strcmp(name, "..") == 0)
	// 	return (1);
	if ((name[0] == '.' && ft_strlen(name) == 1)
		|| (name[0] == '.' && name[1] == '.' && ft_strlen(name) == 2))
		return (1);
	return (0);
}

char	*cut_date(char *long_date)
{
	char	*s;
	int		i;
	int		j;

	s = (char *)malloc(sizeof(char) * 12 + 1);
	i = 4;
	j = 0;
	while (i - 4 < 12)
		s[j++] = long_date[i++];
	s[j] = '\0';
	return (s);
}

char	*get_rights(mode_t mode)			/* void -> putchar all char32 */
{
	char	*s;
	int		i;

	s = (char *)malloc(sizeof(char) * 12);
	i = 0;
	s[i++] = get_type(mode);
	s[i++] = (mode & S_IRUSR ? 'r' : '-');
	s[i++] = (mode & S_IWUSR ? 'w' : '-');
	if (mode & S_ISUID)
		s[i++] = (mode & S_IXUSR ? 's' : 'S');
	else
		s[i++] = (mode & S_IXUSR ? 'x' : '-');
	s[i++] = (mode & S_IRGRP ? 'r' : '-');
	s[i++] = (mode & S_IWGRP ? 'w' : '-');
	if (mode & S_ISGID)
		s[i++] = (mode & S_IXGRP ? 's' : 'S');
	else
		s[i++] = (mode & S_IXGRP ? 'x' : '-');
	s[i++] = (mode & S_IROTH ? 'r' : '-');
	s[i++] = (mode & S_IWOTH ? 'w' : '-');
	if (mode & S_ISVTX)
		s[i++] = (mode & S_IXOTH ? 't' : 'T');
	else
		s[i++] = (mode & S_IXOTH ? 'x' : '-');
	s[i] = '\0';
	return (s);
}
