/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 20:01:43 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/14 19:38:46 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ls.h"

void	display_recurse(char *path, t_all *recurse, t_opt *opt)
{
	ft_printf("%s:\n", path);
	//recurse = sort_maj(recurse);
	display_lst2(recurse, opt);
	write(1, "\n", 1);
}

void	display_lst(t_all **lst, t_opt *opt)
{
	t_all *tmp;

	// ft_printf("name: %s\npath: %s\n", lst->content->name, lst->content->path);
	tmp = *lst;
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
	ft_putstr("segfault\n");
}

void 	display_lst2(t_all *all, t_opt *opt)
{
	t_all *tmp;

	// ft_printf("name: %s\npath: %s\n", lst->content->name, lst->content->path);
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
