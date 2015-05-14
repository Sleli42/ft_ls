/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 01:01:42 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/14 18:25:46 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void 	display_files(t_all *files, t_opt *opt)
{
	t_all 	*tmp;

	tmp = files;
	if (opt->l)
		display_statfile(tmp->content, define_maxlen(files, opt));
	else
	{
		ft_putstr(tmp->content->name);
	}
}

void 	display_lst(t_all *list, t_opt *opt)
{
	t_all *tmp;

	if (opt->l)
		long_display(list, opt);
	else
	{
		tmp = (opt->r) ? goto_last_elem(list) : list;
		while (tmp)
		{
			if (opt->a)
				ft_putendl(tmp->content->name);
			else
			{
				if (tmp->content->name[0] != '.')
					ft_putendl(tmp->content->name);
			}
			tmp = (opt->r) ? tmp->prev : tmp->next;
		}
	}
}


void 	display_statfile(t_infos *curr, t_maxlen *len)
{
	unsigned int 	tmp;

	ft_putstr(curr->rights);
	write(1, " ", 1);
	tmp = len->link;
	if (ft_strlen(curr->rights) == 10)
		tmp = tmp + 1;
	while (ft_strlen(curr->link) < tmp--)
		write(1, " ", 1);
	ft_putstr(curr->link);
	write(1, " ", 1);
	tmp = len->uid;
	ft_putstr(curr->s_uid);
	while (ft_strlen(curr->s_uid) < tmp--)
		write(1, " ", 1);
	write(1, "  ", 2);
	tmp = len->gid;
	ft_putstr(curr->s_gid);
	while (ft_strlen(curr->s_gid) < tmp--)
		write(1, " ", 1);
	write(1, "  ", 2);
	tmp = len->octet;
	while (ft_strlen(curr->size) < tmp--)
		write(1, " ", 1);
	ft_putstr(curr->size);
	write(1, " ", 1);
	ft_putstr(curr->date);
	write(1, " ", 1);
	ft_putstr(curr->name);
	write (1, "\n", 1);
}

void 	long_display(t_all *all, t_opt *opt)
{
	t_all 			*tmp;
	t_maxlen 		*len;

	len = define_maxlen(all, opt);
	all->content->blksize = define_blksize(all, opt);
	tmp = (opt->r) ? goto_last_elem(all) : all;
	if (all->content->blksize > -1 && all->content->is_dir)
	{
		ft_putstr("total "), ft_putnbr(all->content->blksize);
		write(1, "\n", 1);
	}
	if (tmp)
	{
		while (tmp)
		{
			if (opt->a == 1)
				display_statfile(tmp->content, len);
			else
			{
				if (tmp->content->name[0] != '.')
					display_statfile(tmp->content, len);
			}
			tmp = (opt->r) ? tmp->prev : tmp->next;
		}
	}
	free(len);
}
