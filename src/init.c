/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:19:54 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/06 21:13:15 by lubaujar         ###   ########.fr       */
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
	all->content->path = NULL;
	all->content->name = NULL;
	all->content->date = NULL;
	all->content->rights = NULL;
	all->content->s_uid = NULL;
	all->content->s_gid = NULL;
	all->content->is_dir = 0;
	all->content->link = 0;
	all->content->size = 0;
	all->content->blksize = 0;
}
