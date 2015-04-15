/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 03:58:30 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/15 03:53:36 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int 	search_max_size(t_all *lst)
{
	t_all 	*tmp;
	int 	ret;

	tmp = lst;
	ret = 0;
	if (lst)
	{
		while (tmp)
		{
			if ((int)ft_strlen(tmp->content->size) > ret)
				ret = (int)ft_strlen(tmp->content->size);
			tmp = tmp->next;
		}
	}
	return (ret);
}

int 	search_max_link(t_all *lst)
{
	t_all 	*tmp;
	int 	ret;

	tmp = lst;
	ret = 0;
	if (lst)
	{
		while (tmp)
		{
			if ((int)ft_strlen(tmp->content->link) > ret)
				ret = (int)ft_strlen(tmp->content->link);
			tmp = tmp->next;
		}
	}
	return (ret);
}

char 	*create_str(char *s, int max)
{
	char 	*ret;
	int 	i;

	ret = (char *)malloc(sizeof(char) * max + 1);
	i = 0;
	while (i < max - ((int)ft_strlen(s)))
		ret[i++] = ' ';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

void 	modif_link(t_all **lst, int max)
{
	t_all 	*tmp;
	char 	*s;

	tmp = *lst;
	if (*lst)
	{
		while (tmp)
		{
			if ((int)ft_strlen(tmp->content->link) < max)
			{
				//ft_printf("lnk: %s\n", tmp->content->link);
				s = create_str(tmp->content->link, max);
				tmp->content->link = ft_strdup(s);
				// ft_printf("lnk: %s\n", tmp->content->link);
				ft_strdel(&s);
			}
			tmp = tmp->next;
		}
	}
}

void 	modif_size(t_all **lst, int max)
{
	t_all 	*tmp;
	char 	*s;

	tmp = *lst;
	if (*lst)
	{
		while (tmp)
		{
			if ((int)ft_strlen(tmp->content->size) < max)
			{
				// ft_printf("lnk: %s\n", tmp->content->size);
				s = create_str(tmp->content->size, max);
				tmp->content->size = ft_strdup(s);
				// ft_printf("lnk: %s\n", tmp->content->size);
				ft_strdel(&s);
			}
			tmp = tmp->next;
		}
	}
}

void 	define_maxlen(t_all **alst)
{
	t_all 	*tmp;
	int 	maxlen_link;
	int  	maxlen_size;

	tmp = *alst;
	maxlen_link = search_max_link(tmp);
	maxlen_size = search_max_size(tmp);
	modif_link(alst, maxlen_link);
	modif_size(alst, maxlen_size);
}

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
	s[j] = '\0';
	return (s);
}

char	*get_rights(mode_t mode)			/* void -> putchar all char32 */
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
