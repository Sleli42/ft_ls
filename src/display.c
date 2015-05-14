/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 20:01:43 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/14 14:46:17 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ls.h"

#include <stdio.h>

void 	displays(t_all *all, t_opt *opt)
{
	if (opt->t == 1)
		sort_time(&all);
	else
		sort_name(&all);
	if (opt->l == 1)
		display_statfile(all, opt);
	else
		display_lst(all, opt);
}

void	display_recurse(char *path, t_all *recurse, t_opt *opt, int jok)
{
	write(1, "\n", 1);
	ft_putstr(path);
	write(1, ":\n", 2);
	if (ft_strcmp(path, "/dev/fd/3") == 0)
	{
		ft_putstr("ls: 3: Not a directory\nls: 4: directory causes a cycle\n");
		exit(1);
	}
	if (jok == 1)
	{
		ft_putstr("ls: Users: Permission denied\n");
		return ;
	}
	else
	{
		displays(recurse, opt);
	}
}

void 	display_lst(t_all *all, t_opt *opt)
{
	t_all *tmp;

	tmp = (opt->r) ? goto_last_elem(all) : all;
	if (tmp)
	{
		while (tmp)
		{
			if (opt->a == 1)
			{
				ft_putstr(tmp->content->name);
				write(1, "\n", 1);
			}
			else
			{
				if (tmp->content->name[0] != '.')
				{
					ft_putstr(tmp->content->name);
					write(1, "\n", 1);
				}
			}
			tmp = (opt->r) ? tmp->prev : tmp->next;
		}
	}
}

void 	display_infos(t_infos *curr)
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

void 	display_statfile(t_all *all, t_opt *opt)
{
	t_all 			*tmp;

	define_maxlen(&all);
	all->content->blksize = define_blksize(all, opt);
	tmp = (opt->r) ? goto_last_elem(all) : all;
	if (all->content->blksize > -1)
		ft_printf("total %d\n", all->content->blksize);
	if (tmp)
	{
		while (tmp)
		{
			if (opt->a == 1)
				display_infos(tmp->content);
			else
				if (tmp->content->name[0] != '.')
					display_infos(tmp->content);
			if (tmp->prev || tmp->next)
				tmp = (opt->r) ? tmp->prev : tmp->next;
		}
	}
}

void 	display_alone_file(t_all *all, t_opt *opt, char **av, int ac)
{
	t_infos 	*file;

	if (opt->l == 1)
	{
		file = add_statfile(all->content->path, all->content->path);
		display_infos(file);
	}
	else
		ft_printf("%s\n", av[ac]);
}
