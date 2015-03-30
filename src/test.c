/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 03:04:17 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/30 17:33:02 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		find_max_link(t_infos *lst)
{
	// int		max;
	// char	*s;
	t_infos	*tmp;

	tmp = lst;
	/* ... */
	return (0);
}

void	test_statfile(t_infos **lst)
{
	t_infos	*tmp;
	char	*date;
	char	*rights;
	//int		max_octets;
	//int		max_links;
	struct passwd	*uid;
	struct group 	*gid;

	tmp = *lst;
	//max_links = find_max_link(lst);
	//ft_printf("max_link: %d\n", max_links);
	while (tmp)
	{
		if (lstat(tmp->path, &tmp->stat) == -1)
			ft_printf("error stat\n");
		date = cut_date(ctime(&(tmp->stat.st_mtime)));
		rights = get_rights(tmp->stat.st_mode);
		uid = getpwuid(tmp->stat.st_uid);
		gid = getgrgid(tmp->stat.st_gid);
		// ft_printf("uid: %s\n", uid->pw_name);
		// ft_printf("gid: %s\n", gid->gr_name);
		// ft_printf("%s  %d  %s %s %d %s %s\n", rights, tmp->stat.st_nlink,
		//  uid->pw_name, gid->gr_name, tmp->stat.st_size, date, tmp->name);
		// ft_printf("name:%s  link:%d  size:%d  date:%s\n", tmp->name, tmp->stat.st_nlink,
		 //tmp->stat.st_size, date);
		tmp = tmp->next;
	}
}
