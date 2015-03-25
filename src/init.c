/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:19:54 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/25 03:05:45 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	init_options(t_all *all)
{
	all->opt.a = 0;
	all->opt.l = 0;
	all->opt.t = 0;
	all->opt.r = 0;
	all->opt.R = 0;
	all->opt.no_opt = 0;
}

void	init_infos(t_all *all)
{
	all->infos.path = NULL;
	all->infos.name = NULL;
	all->infos.user = NULL;
	all->infos.grp = NULL;
	all->infos.rights = NULL;
	all->infos.date = NULL;
	all->infos.link = NULL;
	all->infos.size = NULL;
	all->infos.next = NULL;
	all->infos.prev = NULL;
}
