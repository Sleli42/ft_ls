/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 03:43:15 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/27 17:28:51 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	readdirectory(t_opt *opt, t_stat *lst, char *directory)
{
	t_dirent	*entry;
	DIR			*dir;

	lst = NULL;
	if (!(dir = opendir(directory)))
		return ;
	while ((entry = readdir(dir)))
	{
		lst_add_stat(&lst, entry, entry->d_name);
	}
	closedir(dir);
	display_opt(opt, lst);
}
/*
char	*current_path(char *args)
{
	int		i;
	int		find;
	int		n;
	char	*path;

	printf("current_path = %s\n", args);
	i = -1;
	n = -1;
	find = 0;
	while (args[++i])
	{
		if (args[i] == '/')
		{
			find = i;
			printf("find=%d", find);
		}
	}
	printf("i=%d", i);
	if (find == 0)
		return (NULL);
	path = (char *)ft_memalloc(i + 1);
	while (++n != find + 1)
		path[n] = args[n];
	printf("current_path fin de fct = %s\n", path);
	i = -1;
	n--;
	while (args[++n])
		args[++i] = args[n];
	while (args[++i])
		args[i] = 0;
	printf("current_path fin de fct = %s\n", path);
	return (path);
}
*/

int		main(int argc, char **argv)
{
	t_opt	opt;
	t_stat	*lst;

	init_opt(&opt);
	if (argc > 1)
	{
		if (check_opt(&opt, argv) == 1)
			readdirectory(&opt, lst, argv[2]);
		//else if check_opt == 0
		//		fct no_option;
	}
	return (0);
}
