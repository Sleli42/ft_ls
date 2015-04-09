/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 03:58:30 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/09 03:05:02 by lubaujar         ###   ########.fr       */
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
	return (0);
}

int 	get_type2(unsigned char c)
{
	int 	ret;

	ret = 0;
	if (c == DT_DIR)
		ret = 1;
	return (ret);
}

int		is_parent_or_current(char *name)
{
	if  (ft_strcmp(name, ".") == 0 || ft_strcmp(name, "..") == 0)
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
	s[i] = '\0';
	return (s);
}

char	*get_rights(mode_t mode)
{
	char	*s;
	int		i;

	s = (char *)malloc(sizeof(char) * 11);
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
