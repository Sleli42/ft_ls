/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 03:04:17 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/27 03:04:19 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	test_statfile(t_infos *lst)
{
	t_infos	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (lstat(tmp->path, &tmp->stat) == -1)
			ft_printf("error stat\n");
		ft_printf("name:%s  link:%d  size:%d\n", tmp->name, tmp->stat.st_nlink,
		 tmp->stat.st_size);
		tmp = tmp->next;
	}
}