/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:09:37 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/25 03:05:43 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include "libft.h"
# include <string.h>

typedef struct	dirent	t_dirent;
typedef struct	stat	t_stat;

typedef struct	s_opt
{
	int				a;
	int				l;
	int				t;
	int				r;
	int				R;
	int				no_opt;
}				t_opt;

typedef struct	s_infos
{
	char			*path;
	char			*name;
	char			*user;
	char			*grp;
	char			*rights;
	char			*date;
	char			*link;
	char			*size;
	struct s_infos	*next;
	struct s_infos	*prev;
}				t_infos;

typedef struct	s_all
{
	t_infos			infos;
	t_opt			opt;
}				t_all;

/* lst.c */
void	lst_add_elem(t_infos *elem);
t_infos	*lst_create_elem(t_infos *elem);

/* main.c */
int		main(int ac, char **av);
void	read_directory(t_all *all);

/* check.c */
int		check_options(t_all *all, char **argv);

/* init.c */
void	init_options(t_all *all);
void	init_infos(t_all *all);
char	*create_path_directory(char *arg);

/* recurse.c */
void	recurse_directory(t_all *all, char *path, DIR *dir);
char	get_types(mode_t mode);

int		ft_printf(char const *rfmt, ...);
void	display_name(t_all *all, t_dirent *dirp, DIR *dir);

#endif
