/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 20:01:43 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/15 03:53:30 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ls.h"

void 	displays(t_all *all, t_opt *opt)
{
	sort_name(&all);
	if (opt->l == 1)
	{
		display_statfile(all, opt);
	}
	else
		display_lst(all, opt);
}

void	display_recurse(char *path, t_all *recurse, t_opt *opt)
{
	ft_printf("%s:\n", path);
	displays(recurse, opt);
	write(1, "\n", 1);
}

void 	display_lst(t_all *all, t_opt *opt)
{
	t_all *tmp;

	tmp = all;
	if (tmp)
	{
		while (tmp != NULL)
		{
			if (opt->a == 1)
				ft_printf("%s\n", tmp->content->name);
			else
				if (tmp->content->name[0] != '.')
					ft_printf("%s\n", tmp->content->name);
			tmp = tmp->next;
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
	write(1, " ", 1);
	ft_putstr(curr->size);
	write(1, " ", 1);
	ft_putstr(curr->date);
	write(1, " ", 1);
	ft_putstr(curr->name);
	write (1, "\n", 1);
}

int 	define_blksize(t_all *all)
{
	t_all *tmp;
	int   ret;

	tmp = all;
	ret = 0;
	if (all)
	{
		while (tmp)
		{
			if (tmp->content->blksize != 0)
				ret += tmp->content->blksize;
			tmp = tmp->next;
		}
	}
	return (ret);
}

void 	display_statfile(t_all *all, t_opt *opt)
{
	t_all 			*tmp;
	int 			test;

	tmp = all;
	test = 0;
	define_maxlen(&all);
	test = define_blksize(all);
	ft_printf("total %d\n", test);
	// return ;
	if (all)
	{
		//ft_printf("---> %u\n", tmp->content->blksize);
		while (tmp)
		{
			if (opt->a == 1)
			{
				display_infos(tmp->content);
				// ft_printf("%s  %s %s  %s  ", tmp->content->rights,
				// 	tmp->content->link,
				// 	tmp->content->uid->pw_name,
				// 	tmp->content->gid->gr_name);
				// ft_printf("%s %s  %s\n", tmp->content->size,
				// 	tmp->content->date,
				// 	tmp->content->name);
			}
			else
			{
				if (tmp->content->name[0] != '.')
				{
					display_infos(tmp->content);
					// ft_printf("%s  %s %s  %s  ", tmp->content->rights,
					// 	tmp->content->link,
					// 	tmp->content->uid->pw_name,
					// 	tmp->content->gid->gr_name);
					// ft_printf("%s %s  %s\n", tmp->content->size,
					// 	tmp->content->date,
					// 	tmp->content->name);
				}
			}
			tmp = tmp->next;
		}
		//ft_printf("---> %u\n", tmp->content->blksize);
	}
}
