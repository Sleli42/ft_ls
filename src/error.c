/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 19:17:19 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/19 00:55:53 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		err(void)
{
	put_error_dev(10 + 11);
}

void		put_error_file_dir(char *s)
{
	ft_putstr("ls: ");
	ft_putstr(s);
	ft_putstr(": No such file or directory\n");
}

void		put_error_perms(char *dirname)
{
	ft_putstr("ls: ");
	ft_putstr(dirname);
	ft_putstr(": Permission denied\n");
}

void		put_error_dev(int e)
{
	if (e == 21)
		exit(1);
	else
		ft_putstr("ls: 3: Not a directory\nls: 4: directory causes a cycle\n");
	if (e != 21)
		e = 21, put_error_dev(e);
}

void		error_opt(char bad_opt)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(bad_opt);
	ft_putstr("\nusage: ls [-ARSailnrt] [file ...]\n");
	put_error_dev(21);
}
