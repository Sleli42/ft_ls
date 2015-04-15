/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 18:47:38 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/16 01:33:37 by lubaujar         ###   ########.fr       */
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

char 	*create_str(char *s, int max)
{
	char 	*ret;
	int 	i;

	ret = (char *)malloc(sizeof(char) * max + 1);
	i = 0;
	while (i < max - ((int)ft_strlen(s)))
		ret[i++] = ' ';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

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
				// ft_printf("lnk: %s\n", tmp->content->link);
				ft_strdel(&s);
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
				// ft_printf("lnk: %s\n", tmp->content->size);
				ft_strdel(&s);
			}
			tmp = tmp->next;
		}
	}
}
