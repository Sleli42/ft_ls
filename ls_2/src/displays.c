/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 01:01:42 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/13 01:38:35 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void 	display_lst(t_all *list, t_opt *opt)
{
	t_all *tmp;

	tmp = list;
	if (opt->l)
		long_display(tmp, opt);
	else
	{
		while (tmp)
		{
			if (opt->a)
				ft_putendl(tmp->content->name);
			else
				if (tmp->content->name[0] != '.')
					ft_putendl(tmp->content->name);
			tmp = tmp->next;
		}
	}
}


void 	display_statfile(t_infos *curr)
{
	ft_putstr(curr->rights);
	write(1, "  ", 2);
	ft_putstr(curr->link);
	write(1, " ", 1);
	ft_putstr(curr->s_uid);
	write(1, "  ", 2);
	ft_putstr(curr->s_gid);
	write(1, "  ", 2);
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

	len = define_maxlen();
	all->content->blksize = define_blksize(all, opt);
	tmp = (opt->r) ? goto_last_elem(all) : all;
	if (all->content->blksize > -1)
	{
		ft_putstr("total "), ft_putnbr(all->content->blksize);
		write(1, "\n", 1);
	}
	if (tmp)
	{
		while (tmp)
		{
			if (opt->a == 1)
				display_statfile(tmp->content);
			else
				if (tmp->content->name[0] != '.')
					display_statfile(tmp->content);
			if (tmp->prev || tmp->next)
				tmp = (opt->r) ? tmp->prev : tmp->next;
		}
	}
}
