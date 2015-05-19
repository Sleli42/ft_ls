/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 20:25:51 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/19 14:49:45 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*add_char_file(char *s, t_stat buff)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 2);
	i = 0;
	while (*s)
		ret[i++] = *s++;
	if (S_ISDIR(buff.st_mode))
		ret[i++] = '/';
	if (S_ISLNK(buff.st_mode))
		ret[i++] = '@';
	if (S_ISFIFO(buff.st_mode))
		ret[i++] = '|';
	if (S_ISREG(buff.st_mode) && buff.st_mode & S_IXOTH)
		ret[i++] = '*';
	ret[i] = '\0';
	return (ret);
}

char	*add_symb_link(char *s, char *buff)
{
	int		i;
	int		ret;

	i = 0;
	ret = readlink(s, buff, 221);
	if (ret < 0)
		return (NULL);
	while (buff[i] != '\0')
		i++;
	buff[i] = '\0';
	return (buff);
}

void	swap_elem(t_all **a, t_all **b)
{
	t_infos	*temp;

	temp = (*a)->content;
	(*a)->content = (*b)->content;
	(*b)->content = temp;
}

void	extended_data_init(t_infos *new, t_stat buff, t_opt *opt)
{
	new->is_dir = S_ISDIR(buff.st_mode);
	if (opt->t)
		new->timesec = buff.st_mtime;
	if ((buff.st_mode & S_IROTH) == 0)
		new->err = 1;
	else
		new->err = 0;
	if (opt->i)
		new->inode = ft_itoa_long(buff.st_ino);
	if (opt->l || opt->big_s || opt->n)
	{
		new->date = cut_date(ctime(&(buff.st_mtime)));
		new->rights = get_rights(buff.st_mode, 0);
		new->link = ft_itoa(buff.st_nlink);
		long_data(new, buff, opt);
	}
}

void	extended_lst_display(t_all *tmp, t_opt *opt)
{
	if (!opt->big_a && tmp->content->name[0] != '.')
	{
		if (opt->i)
			ft_putstr(tmp->content->inode), write(1, " ", 1);
		ft_putendl(tmp->content->name);
	}
	else if (opt->big_a &&
			!is_parent_or_current(tmp->content->name, opt))
	{
		if (opt->i)
			ft_putstr(tmp->content->inode), write(1, " ", 1);
		ft_putendl(tmp->content->name);
	}
}
