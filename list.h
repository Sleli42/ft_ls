/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 19:35:57 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/06 04:39:42 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

// lib opendir/readdir/closedir
#include <dirent.h>
// lib stat & co
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/xattr.h>	// listxattr
#include <pwd.h>		// getpwuid
#include <grp.h>		// getgrgid*
#include <uuid/uuid.h>	// getgrgid*
#include <time.h>		// time/ctime
#include <stdlib.h>

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

typedef struct	s_option
{
	char	l;
	char	a;
	char	t;
	char	r;
	char	no_option;
}				t_option;

void	readdirectory(char *dir, t_option *opt);
void	init_options(t_option *opt);
int		checkoptions(char *str, t_option *opt);
void	checkfile(char *file, t_option *opt, struct stat *buff, int stop);
void	enable_options(char *str, t_option *opt);
void	ls_l_option(char *file, struct stat *buff, int stop);
void	ls_no_option(char *file);
void	error(int code_error);
//void	ft_chmod(char *file, struct stat *buff);
//static void	ft_chmod(mode_t perm);
void	ft_chmod(char *file, struct stat *buff);
char	*ft_hours(char *time);
//static char	ft_types(mode_t perm);

#endif
