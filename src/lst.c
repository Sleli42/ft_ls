/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 01:00:29 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/25 03:05:42 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	lst_add_elem(t_infos *elem, char *filename)
{
	t_infos	*tmp;

	tmp = lst_create_elem(elem, filename);
}

t_infos		*lst_create_elem(t_infos *elem, char *filename)
{
	if (!(elem = (t_infos *)malloc(sizeof(t_infos))))
		ft_printf("error malloc\n");
	/* init all infos */
	return (elem);
}
