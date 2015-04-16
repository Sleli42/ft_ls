/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 20:01:43 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/16 06:10:51 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ls.h"

void 	displays(t_all *all, t_opt *opt)
{
	if (opt->l == 1)
	{
		display_statfile(all, opt);
	}
	else
		display_lst(all, opt);
}

void	display_recurse(char *path, t_all *recurse, t_opt *opt)
{
	write(1, "\n", 1);
	ft_printf("%s:\n", path);
	displays(recurse, opt);
}

void 	display_lst(t_all *all, t_opt *opt)
{
	t_all *tmp;

	tmp = all;
	tmp = (opt->r) ? goto_last_elem(all) : all;
	if (tmp)
	{
		while (tmp)
		{
			if (opt->a == 1)
				ft_printf("%s\n", tmp->content->name);
			else
				if (tmp->content->name[0] != '.')
					ft_printf("%s\n", tmp->content->name);
			tmp = (opt->r) ? tmp->prev : tmp->next;
		}
	}
}

void 	display_infos(t_infos *curr)
{
	ft_putstr(curr->rights);
	write(1, " ", 1);
	ft_putstr(curr->link);
	write(1, " ", 1);
	ft_putstr(curr->uid->pw_name);
	write(1, "  ", 2);
	ft_putstr(curr->gid->gr_name);
	write(1, "  ", 2);
	ft_putstr(curr->size);
	write(1, " ", 1);
	ft_putstr(curr->date);
	write(1, " ", 1);
	ft_putstr(curr->name);
	write (1, "\n", 1);
}

void 	display_statfile(t_all *all, t_opt *opt)
{
	t_all 			*tmp;

	define_maxlen(&all);
	all->content->blksize = define_blksize(&all);
	tmp = (opt->r) ? goto_last_elem(all) : all;
	if (all->content->blksize != 0)
		ft_printf("total %d\n", tmp->content->blksize);
	if (all)
	{
		while (tmp)
		{
			if (opt->a == 1)
				display_infos(tmp->content);
			else
				if (tmp->content->name[0] != '.')
					display_infos(tmp->content);
			tmp = (opt->r) ? tmp->prev : tmp->next;
		}
	}
}
