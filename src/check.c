/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 22:37:49 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/19 02:54:38 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	list_opts_2(t_opt *opt, char *s, int i)
{
	if (s[i] == 'i')
		opt->i = 1;
	else if (s[i] == 'n')
		opt->n = 1;
	else if (s[i] == 'R')
		opt->big_r = 1;
	else if (s[i] == 'S')
		opt->big_s = 1;
	else
		error_opt(s[i]);
}

void		list_opts(t_opt *opt, char *s)
{
	int i;

	i = 0;
	while (s[++i])
	{
		if (s[i] == 'a')
			opt->a = 1;
		else if (s[i] == 'A')
			opt->big_a = 1;
		else if (s[i] == 'l')
			opt->l = 1;
		else if (s[i] == 'F')
			opt->big_f = 1;
		else if (s[i] == 'r')
			opt->r = 1;
		else if (s[i] == 't')
			opt->t = 1;
		else
			list_opts_2(opt, s, i);
	}
}

void		list_elem(t_all **args, t_opt *opt, char *filename, char *path)
{
	t_infos		*data;

	data = NULL;
	if ((data = data_init(filename, path, opt)) == NULL)
		return ;
	if (!(*args))
		*args = lst_create_elem(data);
	else
		lst_add_elem_back(args, lst_create_elem(data));
}
