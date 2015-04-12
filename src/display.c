/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 20:01:43 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/12 21:34:29 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ls.h"

void	display_recurse(char *path, t_infos *recurse, t_opt *opt)
{
	ft_printf("%s:\n", path);
	//recurse = sort_maj(recurse);
	display_lst(recurse, opt);
	write(1, "\n", 1);
}

void	display_lst(t_infos *lst, t_opt *opt)
{
	t_infos *tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (opt->a == 1)
			ft_printf("%s\n", tmp->name);
		else
		{
			if (tmp->name[0] != '.')
				ft_printf("%s\n", tmp->name);
		}
		tmp = tmp->next;
	}
}
