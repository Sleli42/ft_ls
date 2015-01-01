/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 16:12:50 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/27 17:28:59 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		define_max_len_octets(t_stat *lst)
{
	t_stat		*tmp;
	t_statfile	buff;
	int		len;
	static int	len_max;
	char	*c_size;

	tmp = lst;
	if (tmp)
	{
		while (tmp)
		{
			if ((lstat(tmp->name, &buff)) != -1)
			{
				c_size = ft_itoa(buff.st_size);
				len = ft_strlen(c_size);
				len_max = compare(len, len_max);
			}
			tmp = tmp->next;
		}
	}
	return (len_max);
}

int		define_max_len_link(t_stat *lst)
{
	t_stat		*tmp;
	t_statfile	buff;
	int		len;
	static int	len_max;
	char	*c_link;

	tmp = lst;
	if (tmp)
	{
		while (tmp)
		{
			if ((lstat(tmp->name, &buff)) != -1)
			{
				c_link = ft_strdup(ft_itoa(buff.st_nlink));
				len = ft_strlen(c_link);
				len_max = compare(len, len_max);
			}
			tmp = tmp->next;
		}
	}
	return (len_max);
}

int		compare(int len, int len_max)
{
	if (len > len_max)
	{
		len_max = len;
		return (len_max);
	}
	return (len_max);
}
