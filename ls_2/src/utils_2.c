/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 01:03:47 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/14 18:25:39 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

unsigned int 	update_maxlen(char *s, unsigned int curr_len)
{
	if (ft_strlen(s) > curr_len)
		curr_len = ft_strlen(s);
	return (curr_len);
}

t_maxlen		*define_maxlen(t_all *lst, t_opt *opt)
{
	t_all 		*tmp;
	t_maxlen 	*len;

	tmp = lst;
	len = init_len();
	while (tmp)
	{
		if (opt->a)
		{
			if (tmp->content->link)
				len->link = update_maxlen(tmp->content->link, len->link);
			if (tmp->content->size)
				len->octet = update_maxlen(tmp->content->size, len->octet);
			if (tmp->content->s_uid)
				len->uid = update_maxlen(tmp->content->s_uid, len->uid);
			if (tmp->content->s_gid)
				len->gid = update_maxlen(tmp->content->s_gid, len->gid);
		}
		else
		{
			if (tmp->content->name[0] != '.')
			{
				if (tmp->content->link)
					len->link = update_maxlen(tmp->content->link, len->link);
				if (tmp->content->size)
					len->octet = update_maxlen(tmp->content->size, len->octet);
				if (tmp->content->s_uid)
					len->uid = update_maxlen(tmp->content->s_uid, len->uid);
				if (tmp->content->s_gid)
					len->gid = update_maxlen(tmp->content->s_gid, len->gid);
			}
		}
		tmp = tmp->next;
	}
	return (len);
}

t_all			*goto_last_elem(t_all *all)
{
	t_all *tmp;

	tmp = all;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	return (tmp);
}

int 			define_blksize(t_all *all, t_opt *opt)
{
	t_all *tmp;
	int   ret;

	tmp = all;
	ret = 0;
	if (tmp == NULL)
		return (-1);
	else
	{
		while (tmp)
		{
			if (opt->a)
			{
				if (tmp->content->blksize != 0)
					ret += tmp->content->blksize;
			}
			else
			{
				if (tmp->content->name[0] != '.')
					ret += tmp->content->blksize;
			}
			tmp = tmp->next;
		}
	}
	del_lst(tmp);
	return (ret);
}
