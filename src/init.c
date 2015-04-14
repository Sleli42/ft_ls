/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:19:54 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/14 02:30:52 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	init(t_opt *opt, t_all *all)
{
	init_opt(opt);
	init_all(all);
}

void 	init_opt(t_opt *opt)
{
	opt->a = 0;
	opt->l = 0;
	opt->t = 0;
	opt->r = 0;
	opt->R = 0;
	opt->no_opt = 0;
}

void 	init_all(t_all *all)
{
	all->content->name = NULL;
	all->content->path = NULL;
	all->content->is_dir = 0;
}
