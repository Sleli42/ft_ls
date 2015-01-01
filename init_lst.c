/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 04:18:24 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/29 17:18:34 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_stat	*new_elem(t_dirent *entry, char *file)
{
	t_stat		*new;
	t_statfile	stat;

	if ((new = (t_stat *)malloc(sizeof(t_stat))) == NULL
			|| (lstat(file, &stat) == -1))
		return (NULL);
	new->name = ft_strdup(entry->d_name);
	get_infos(new, &stat);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	lst_add_stat(t_stat **begin, t_dirent *entry, char *directory)
{
	t_stat	*new;
	t_stat	*tmp;

	if ((new = new_elem(entry, directory)) == NULL)
		return ;
	if (*begin == NULL)
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

void	lst_print(t_stat *lst, t_opt *opt)
{
	t_stat	*tmp;
	int		max_len;
	int		max_link;

	tmp = lst;
	max_len = define_max_len_octets(tmp);
	max_link = define_max_len_link(tmp);
	define_size(tmp, max_len);
	define_link(tmp, max_link);
	if (opt->l == 1)
		opt_l_display(tmp, opt);
	else
	{
		while (tmp)
		{
			ft_putendl(tmp->name);
			tmp = tmp->next;
		}
	}
}

/*
void	sort_maj_first(t_stat *lst)
{
	t_stat	*tmp;
	t_stat	*lst_sort;

	tmp = lst;
	if (tmp)
	{
		while (tmp != NULL)
		{
			printf("%s\n", tmp->name);
			if (tmp->name[0] >= 65 && tmp->name[0] <= 90)
			{
				printf("une maj, cool\n");
				lst_sort->name = tmp->name;
			}
			tmp = tmp->next;
			printf("\tmaj:%s\n", lst_sort->name);
		}
	}
	printf("\t\tje sors\n");
}
*/
void	lst_print_reverse(t_stat *lst, t_opt *opt)
{
	t_stat	*tmp;
	int		max_len;
	int		max_link;

	tmp = lst;
	max_len = define_max_len_octets(tmp);
	max_link = define_max_len_link(tmp);
	define_size(tmp, max_len);
	define_link(tmp, max_link);
	if (opt->l == 1)
		opt_l_reverse_display(tmp, opt);
	else
		basic_display_reverse(tmp, opt);

}

