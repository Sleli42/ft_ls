/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 02:03:14 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/29 17:51:24 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	define_size(t_stat *lst, int max_len)
{
	t_stat		*tmp;
	t_statfile	buff;
	char		*c_size;

	tmp = lst;
	if (tmp)
	{
		while (tmp)
		{
			if ((lstat(tmp->name, &buff)) != -1)
			{
				c_size = ft_itoa(buff.st_size);
				tmp->size = size_cpy(c_size, max_len);
			}
			tmp = tmp->next;
		}
	}
}

char	*size_cpy(char *c_size, int max_len)
{
	int		len;
	int		i;
	int		j;
	char	*ret;

	len = ft_strlen(c_size);
	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * max_len + 1);
	while (i < max_len)
	{
		if (i < max_len - len)
			ret[i] = ' ';
		else
		{
			while (c_size[j])
				ret[i++] = c_size[j++];
		}
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	define_link(t_stat *lst, int max_link)
{
	t_stat		*tmp;
	t_statfile	buff;
	char		*c_link;

	tmp = lst;
	if (tmp)
	{
		while (tmp)
		{
			if ((lstat(tmp->name, &buff)) != -1)
			{
				c_link = ft_itoa(buff.st_nlink);
				tmp->link = link_cpy(c_link, max_link);
			}
			tmp = tmp->next;
		}
	}
}

char	*link_cpy(char *c_link, int max_link)
{
	int		len;
	int		i;
	int		j;
	char	*ret;

	len = ft_strlen(c_link);
	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * max_link + 1);
	while (i < max_link)
	{
		if (i < max_link - len)
			ret[i] = ' ';
		else
		{
			while (c_link[j])
				ret[i++] = c_link[j++];
		}
		i++;
	}
	return (ret);
}

t_stat	*sort_t_opt(t_stat *lst)
{
	t_stat	*tmp;
	t_stat	*ret;
	t_statfile	buff;
	int	time;
	int	prev_time;
	int	i;
	int	value;
	static int	stop;

	tmp = lst;
	ret = lst;
	stop = 0;
	i = 0;
	value = define_min_value(tmp, &buff, 0);
	while (tmp->next)
	{
		value = define_min_value(tmp, &buff, value);
		printf("value: %d\n", value);
		//while ()
		//ret[i]. = tmp->;
		//printf("ret[%d]: \t%s\n", i, ret[i].name);
		//i++;
		tmp = tmp->next;
	}
	return ;
	while (tmp)
	{
		if ((lstat(tmp->name, &buff)) != -1)
		{
			time = buff.st_mtime;
			if (time > value)
			{
				printf("current_value: %d\n", time);		/* A FINIR !!!!!!!!!! */
			}
			/*
			if (stop == 0)
			{
				prev_time = buff.st_mtime;
				stop++;
			}
			time = buff.st_mtime;
			printf("time: %d\n", time);
			printf("prev time: %d\n\n", prev_time);
		//	if (prev_time < )
			prev_time = time;*/
		}
		tmp = tmp->next;
	}
	printf("final min value: %d\n", value);
}

int		define_min_value(t_stat *lst, t_statfile *buff, int prev_value)
{
	t_stat	*tmp;
	int		value_saved;
	int		current_value;

	tmp = lst;
	if ((lstat(tmp->name, buff)) != -1)
		value_saved = buff->st_mtime;
	while (tmp->next && buff->st_mtime != prev_value)
	{
		if ((lstat(tmp->name, buff)) != -1)
			current_value = buff->st_mtime;
		if (current_value < value_saved)
			value_saved = current_value;
		tmp = tmp->next;
	}
	//del_lst_elem(tmp, value_saved);
	return (value_saved);
}

/*void	del_lst_elem(t_stat **elem)
{
	printf("elem name: %s\n", **elem);
}*/
