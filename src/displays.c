/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 01:01:42 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/19 03:07:40 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		display_files(t_all *files, t_opt *opt)
{
	t_all	*tmp;

	tmp = files;
	if (opt->l || opt->n)
		display_statfile(tmp->content, define_maxlen(files, opt), opt);
	else
		ft_putstr(tmp->content->name);
}

void		display_lst(t_all *list, t_opt *opt)
{
	t_all	*tmp;

	if (opt->l || opt->n)
		long_display(list, opt);
	else
	{
		tmp = (opt->r) ? goto_last_elem(list) : list;
		while (tmp)
		{
			if (opt->a)
			{
				if (opt->i)
					ft_putstr(tmp->content->inode), write(1, " ", 1);
				ft_putendl(tmp->content->name);
			}
			else
				extended_lst_display(tmp, opt);
			tmp = (opt->r) ? tmp->prev : tmp->next;
		}
	}
}

static void	display_statfile_2(t_infos *curr, t_maxlen *len, t_opt *opt)
{
	unsigned int tmp;

	if (opt->n)
	{
		tmp = len->uid + 2;
		ft_putnbr(curr->i_uid);
		while (ft_strlen(ft_itoa(curr->i_uid)) < tmp--)
			write(1, " ", 1);
		tmp = len->uid + 2;
		ft_putnbr(curr->i_gid);
		while (ft_strlen(ft_itoa(curr->i_uid)) < tmp--)
			write(1, " ", 1);
	}
	else
	{
		tmp = len->uid + 2;
		ft_putstr(curr->s_uid);
		while (ft_strlen(curr->s_uid) < tmp--)
			write(1, " ", 1);
		tmp = len->gid + 2;
		ft_putstr(curr->s_gid);
		while (ft_strlen(curr->s_gid) < tmp--)
			write(1, " ", 1);
	}
}

void		display_statfile(t_infos *curr, t_maxlen *len, t_opt *opt)
{
	unsigned int	tmp;

	if (opt->i)
		ft_putstr(curr->inode), write(1, " ", 1);
	ft_putstr(curr->rights);
	write(1, " ", 1);
	tmp = len->link;
	if (ft_strlen(curr->rights) <= 10)
		tmp = tmp + 1;
	while (ft_strlen(curr->link) < tmp--)
		write(1, " ", 1);
	ft_putstr(curr->link);
	write(1, " ", 1);
	display_statfile_2(curr, len, opt);
	tmp = len->octet;
	while (ft_strlen(curr->size) < tmp--)
		write(1, " ", 1);
	ft_putstr(curr->size);
	write(1, " ", 1);
	ft_putstr(curr->date);
	write(1, " ", 1);
	ft_putstr(curr->name);
	if (curr->lnk_name)
		write(1, " -> ", 4), ft_putstr(curr->lnk_name);
	write (1, "\n", 1);
}

void		long_display(t_all *all, t_opt *opt)
{
	t_all		*tmp;
	t_maxlen	*len;

	len = define_maxlen(all, opt);
	all->content->blksize = define_blksize(all, opt);
	tmp = (opt->r) ? goto_last_elem(all) : all;
	if (all->content->blksize && all->content->is_dir)
		ft_putstr("total "), ft_putnbr(all->content->blksize),
			write(1, "\n", 1);
	while (tmp)
	{
		if (opt->a)
			display_statfile(tmp->content, len, opt);
		else
		{
			if (!opt->big_a && tmp->content->name[0] != '.')
				display_statfile(tmp->content, len, opt);
			else if (opt->big_a
				&& !is_parent_or_current(tmp->content->name, opt))
				display_statfile(tmp->content, len, opt);
		}
		tmp = (opt->r) ? tmp->prev : tmp->next;
	}
	free(len);
}
