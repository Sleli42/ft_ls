/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 23:00:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/19 01:58:59 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

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

char	*get_rights(mode_t mode, int i)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * 11);
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

char	*major_minor_to_str(t_stat *stat)
{
	char	*s;
	char	*minor_s;
	char	*major_s;

	s = (char *)malloc(sizeof(char) * 11);
	s = ft_strcpy(s, " ");
	minor_s = ft_itoa(minor(stat->st_rdev));
	major_s = ft_itoa(major(stat->st_rdev));
	if (ft_strlen(major_s) == 1)
		s[1] = ' ';
	s = ft_strcat(s, major_s);
	s = ft_strcat(s, ",");
	s = ft_strncat(s, "    ", (4 - ft_strlen(minor_s)));
	s = ft_strcat(s, minor_s);
	ft_strdel(&major_s);
	ft_strdel(&minor_s);
	return (s);
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

int		is_parent_or_current(char *name, t_opt *opt)
{
	int		i;

	i = ft_strlen(name);
	if (opt->big_f)
	{
		if ((i == 2) && (name[0] == '.') && (name[1] == '/'))
			return (1);
		if ((i == 3) && (name[0] == '.' && name[1] == '.') && (name[2] == '/'))
			return (1);
	}
	else
	{
		if ((i == 1) && (name[0] == '.'))
			return (1);
		if ((i == 2) && (name[0] == '.' && name[1] == '.'))
			return (1);
	}
	return (0);
}
