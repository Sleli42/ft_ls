/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 17:53:45 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/08 18:53:10 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

#include <stdio.h>

void 	modif_link(t_all **lst, int max)
{
	t_all 	*tmp;
	char 	*s;

	tmp = *lst;
	if (*lst)
	{
		while (tmp)
		{
			if ((int)ft_strlen(tmp->content->link) < max)
			{
				//ft_printf("lnk: %s\n", tmp->content->link);
				s = create_str(tmp->content->link, max);
				tmp->content->link = ft_strdup(s);
				ft_strdel(&s);
				// ft_printf("lnk: %s\n", tmp->content->link);
			}
			tmp = tmp->next;
		}
	}
}

void 	modif_size(t_all **lst, int max)
{
	t_all 	*tmp;
	char 	*s;

	tmp = *lst;
	if (*lst)
	{
		while (tmp)
		{
			if ((int)ft_strlen(tmp->content->size) < max)
			{
				// ft_printf("lnk: %s\n", tmp->content->size);
				s = create_str(tmp->content->size, max);
				tmp->content->size = ft_strdup(s);
				ft_strdel(&s);
				// ft_printf("lnk: %s\n", tmp->content->size);
			}
			tmp = tmp->next;
		}
	}
}

void 	modif_uid(t_all **lst, int max)
{
	t_all 	*tmp;
	char 	*s;

	tmp = *lst;
	if (*lst)
	{
		while (tmp)
		{
			if ((int)ft_strlen(tmp->content->s_uid) < max)
			{
				// ft_printf("lnk: %s\n", tmp->content->size);
				s = create_str_uidgid(tmp->content->s_uid, max);
				tmp->content->s_uid = ft_strdup(s);
				ft_strdel(&s);
				// ft_printf("lnk: %s\n", tmp->content->size);
			}
			tmp = tmp->next;
		}
	}
}

void 	modif_gid(t_all **lst, int max)
{
	t_all 	*tmp;
	char 	*s;

	tmp = *lst;
	if (*lst)
	{
		while (tmp)
		{
			if ((int)ft_strlen(tmp->content->s_gid) < max)
			{
				// ft_printf("lnk: %s\n", tmp->content->size);
				s = create_str_uidgid(tmp->content->s_gid, max);
				tmp->content->s_gid = ft_strdup(s);
				ft_strdel(&s);
				// ft_printf("lnk: %s\n", tmp->content->size);
			}
			tmp = tmp->next;
		}
	}
}
