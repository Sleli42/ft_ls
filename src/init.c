/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:19:54 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/06 01:42:29 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	init_all(t_opt *opt, t_infos *infos)
{
	opt->a = 0;
	opt->l = 0;
	opt->t = 0;
	opt->r = 0;
	opt->R = 0;
	opt->no_opt = 0;
	infos->name = NULL;
	infos->path = NULL;
}
