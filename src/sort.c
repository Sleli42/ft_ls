/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 17:14:33 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/14 20:06:20 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ls.h"

void 	swap_elem(t_all **a, t_all **b)
{
	t_infos *temp;

	temp = (*a)->content;
	(*a)->content = (*b)->content;
	(*b)->content = temp;
}

void 	sort_name(t_all **alst)
{
	t_all 	*tmp;
	int 	i;

	tmp = *alst;
	i = 0;
	if (tmp)
	{
		while (i++ < len_lst(*alst))
		{
			while (tmp->next)
			{
				if (ft_strcmp(tmp->content->name, tmp->next->content->name) > 0)
				{
					ft_printf("->%s\n", tmp->content->name);
					swap_elem(&tmp, &tmp->next);
					ft_printf("->%s\n", tmp->content->name);
				}
				tmp = tmp->next;
			}
			tmp = *alst;
			//ft_printf("i: |%d|\n", i);
		}
	}
	//ft_putstr("segfault\n");
}
