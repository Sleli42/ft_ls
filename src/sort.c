/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 00:17:23 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/19 14:56:44 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	sort_lists(t_all **list, t_opt *opt)
{
	sort_name(list);
	if (opt->t)
		sort_time(list);
	else if (opt->big_s)
		sort_size(list);
	else
		sort_name(list);
}

void	sort_size(t_all **alst)
{
	t_all	*tmp;
	int		i;
	int		size;
	int		size2;

	tmp = *alst;
	i = 0;
	if (tmp)
	{
		while (i++ < len_lst(tmp))
		{
			while (tmp->next)
			{
				size = ft_atoi(tmp->content->size);
				size2 = ft_atoi(tmp->next->content->size);
				if (size < size2)
					swap_elem(&tmp, &tmp->next);
				tmp = tmp->next;
			}
			tmp = *alst;
		}
	}
}

void	sort_args(t_all **alst)
{
	t_all	*tmp;
	int		i;

	tmp = *alst;
	i = 0;
	if (tmp)
	{
		while (i++ < len_lst(tmp))
		{
			while (tmp->next)
			{
				if (tmp->content->is_dir && !tmp->next->content->is_dir)
					swap_elem(&tmp, &tmp->next);
				tmp = tmp->next;
			}
			tmp = *alst;
		}
	}
}

void	sort_name(t_all **alst)
{
	t_all	*tmp;
	int		i;

	tmp = *alst;
	i = 0;
	if (tmp)
	{
		while (i++ < len_lst(tmp))
		{
			while (tmp->next)
			{
				if (ft_strcmp(tmp->content->name, tmp->next->content->name) > 0)
					swap_elem(&tmp, &tmp->next);
				tmp = tmp->next;
			}
			tmp = *alst;
		}
	}
}

void	sort_time(t_all **alst)
{
	t_all	*tmp;
	int		i;

	tmp = *alst;
	i = 0;
	if (tmp)
	{
		while (i++ < len_lst(tmp))
		{
			while (tmp->next)
			{
				if (tmp->content->timesec < tmp->next->content->timesec)
					swap_elem(&tmp, &tmp->next);
				tmp = tmp->next;
			}
			tmp = *alst;
		}
	}
}
