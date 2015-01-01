/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 19:11:55 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/27 17:28:53 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	display_opt(t_opt *opt, t_stat *lst)
{
	t_stat *tmp;

	tmp = lst;
	if (opt->t == 1)
		sort_t_opt(tmp);
	return ;
	if (opt->r == 1)
		lst_print_reverse(tmp, opt);
	else
		lst_print(tmp, opt);
}

void	opt_l_display(t_stat *lst, t_opt *opt)
{
	t_stat	*tmp;

	tmp = lst;
	if (opt->a == 1)
	{
		while (tmp)
		{
			display_infos(tmp);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp->name[0] == '.')
			tmp = tmp->next;
		while (tmp)
		{
			display_infos(tmp);
			tmp = tmp->next;
		}
	}
}

void	opt_l_reverse_display(t_stat *lst, t_opt *opt)
{
	t_stat	*tmp;

	tmp = lst;
	if (opt->a == 1)
	{
		while (tmp->next)
			tmp = tmp->next;
		if (tmp)
		{
			while (tmp)
			{
				display_infos(tmp);
				tmp = tmp->prev;
			}
		}
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (tmp)
		{
			while (tmp->name[0] != '.')
			{
				display_infos(tmp);
				tmp = tmp->prev;
			}
		}
	}
}

void	basic_display_reverse(t_stat *lst, t_opt *opt)
{
	t_stat	*tmp;

	tmp = lst;
	if (opt->a == 1)
	{
		while (tmp->next)
			tmp = tmp->next;
		if (tmp)
		{
			while (tmp)
			{
				ft_putendl(tmp->name);
				tmp = tmp->prev;
			}
		}
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (tmp)
		{
			while (tmp->name[0] != '.')
			{
				ft_putendl(tmp->name);
				tmp = tmp->prev;
			}
		}
	}
}

void	display_infos(t_stat *lst)
{
	t_stat	*tmp;

	tmp = lst;
	ft_putstr(tmp->rights);
	ft_putstr(tmp->link);
	ft_putchar(' ');
	ft_putstr(tmp->user);
	ft_putstr("  ");
	ft_putstr(tmp->grp);
	ft_putstr("  ");
	ft_putstr(tmp->size);
	ft_putchar(' ');
	ft_putstr(tmp->date);
	ft_putchar(' ');
	ft_putstr(tmp->name);
	ft_putchar('\n');	
}
