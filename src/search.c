/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 17:53:54 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/13 15:09:48 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int 	search_max_size(t_all *lst)
{
	t_all 	*tmp;
	int 	ret;

	tmp = lst;
	ret = 0;
	if (lst)
	{
		while (tmp)
		{
			if ((int)ft_strlen(tmp->content->size) > ret)
				ret = (int)ft_strlen(tmp->content->size);
			tmp = tmp->next;
		}
	}
	return (ret);
}

int 	search_max_link(t_all *lst)
{
	t_all 	*tmp;
	int 	ret;

	tmp = lst;
	ret = 0;
	if (lst)
	{
		while (tmp)
		{
			if ((int)ft_strlen(tmp->content->link) > ret)
				ret = (int)ft_strlen(tmp->content->link);
			tmp = tmp->next;
		}
	}
	return (ret);
}

int 	search_max_uid(t_all *lst)
{
	t_all 	*tmp;
	int 	ret;

	tmp = lst;
	ret = 0;
	if (lst)
	{
		while (tmp)
		{
			if ((int)ft_strlen(tmp->content->s_uid) > ret)
				ret = (int)ft_strlen(tmp->content->s_uid);
			tmp = tmp->next;
		}
	}
	return (ret);
}

int 	search_max_gid(t_all *lst)
{
	t_all 	*tmp;
	int 	ret;

	tmp = lst;
	ret = 0;
	if (lst)
	{
		while (tmp)
		{
			if ((int)ft_strlen(tmp->content->s_gid) > ret)
				ret = (int)ft_strlen(tmp->content->s_gid);
			tmp = tmp->next;
		}
	}
	return (ret);
}
