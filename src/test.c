/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 03:04:17 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/30 00:16:31 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	test_statfile(t_infos *lst)
{
	t_infos	*tmp;
	char	*date;

	tmp = lst;
	while (tmp)
	{
		if (lstat(tmp->path, &tmp->stat) == -1)
			ft_printf("error stat\n");
		date = cut_date(ctime(&(tmp->stat.st_mtime)));
		ft_printf("name:%s  link:%d  size:%d  date:%s\n", tmp->name, tmp->stat.st_nlink,
		 tmp->stat.st_size, date);
		/* fct afficher les droits */
		/* fct getpwuid */
		/* fct getpwgrp */
		/* trouver le + gd nb deliens pour decalage */
		/* // octets */
		tmp = tmp->next;
	}
}
