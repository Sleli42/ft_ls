/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 03:04:17 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/14 04:42:51 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void 	test_lst(t_all *lst)
{
	t_all *tmp;

	tmp = lst;
	while (tmp->content != NULL)
	{
		write(1, ".\n", 2);
		tmp = tmp->next;
	}
	// ft_printf("%s\n", tmp->prev->content->name);
}

// int		find_max_link(t_all *lst)
// {
// 	// int		max;
// 	// char	*s;
// 	t_all	*tmp;

// 	tmp = lst;
// 	/* ... */
// 	return (0);
// }

// void	test_statfile(t_all **lst)
// {
// 	t_all	*tmp;
// 	char	*date;
// 	char	*rights;
// 	//int		max_octets;
// 	//int		max_links;
// 	struct passwd	*uid;
// 	struct group 	*gid;

// 	tmp = *lst;
// 	//max_links = find_max_link(lst);
// 	//ft_printf("max_link: %d\n", max_links);
// 	while (tmp)
// 	{
// 		if (lstat(tmp->content.path, &tmp->content.stat) == -1)
// 			ft_printf("error stat\n");
// 		date = cut_date(ctime(&(tmp->content.stat.st_mtime)));
// 		rights = get_rights(tmp->content.stat.st_mode);
// 		uid = getpwuid(tmp->content.stat.st_uid);
// 		gid = getgrgid(tmp->content.stat.st_gid);
// 		// ft_printf("uid: %s\n", uid->pw_name);
// 		// ft_printf("gid: %s\n", gid->gr_name);
// 		// ft_printf("%s  %d  %s %s %d %s %s\n", rights, tmp.stat.st_nlink,
// 		//  uid->pw_name, gid->gr_name, tmp.stat.st_size, date, tmp.name);
// 		// ft_printf("name:%s  link:%d  size:%d  date:%s\n", tmp->name, tmp.stat.st_nlink,
// 		 //tmp.stat.st_size, date);
// 		tmp = tmp->next;
// 	}
// }

// void	test_path(t_all *lst)
// {
// 	t_all *tmp;

// 	tmp = lst;
// 	while (tmp)
// 	{
// 		ft_printf("path: %s\n", tmp->content.path);
// 		tmp = tmp->next;
// 	}
// }

// void	test_opt(t_opt *opt)
// {
// 	ft_printf("opt->%c = %d\n", 'a', opt->a);
// 	ft_printf("opt->%c = %d\n", 'l', opt->l);
// 	ft_printf("opt->%c = %d\n", 'r', opt->r);
// 	ft_printf("opt->%c = %d\n", 't', opt->t);
// 	ft_printf("opt->%c = %d\n", 'R', opt->R);
// }

// void	test_dir2(t_all *lst)
// {
// 	t_all	*tmp;

// 	tmp = lst;
// 	while (tmp)
// 	{
// 		if (tmp->content.is_dir == 1)
// 			ft_printf("[T.D]%s\n", tmp->content.name);
// 		 tmp = tmp->next;
// 	}
// }

// void 	test_sort(t_all **alst)
// {
// 	t_all *tmp;

// 	tmp = *alst;
// 	if (tmp)
// 	{
// 		while (tmp->next)
// 		{
// 			ft_printf("n1: %s\nn2: %s\n", tmp->content.name, tmp->next->content.name);
// 			ft_printf("cmp = %d\n", ft_strcmp(tmp->content.name, tmp->next->content.name));
// 			tmp = tmp->next;
// 		}
// 	}
// }

