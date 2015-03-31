/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:09:37 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/01 00:46:13 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
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
	t_stat			stat;
	struct s_infos	*next;
}				t_infos;

/* sort.c */
t_infos	*sort_maj(t_infos *lst);

/* lst.c */
void	lst_add_elem_back(t_infos **alst, t_infos *elem);
t_infos	*lst_create_elem(char *path, char *filename);
void	display_lst(t_infos *lst);
int 	len_lst(t_infos *lst);
void	del_lst(t_infos **alst);

/* main.c */
int		main(int ac, char **av);
void	read_directory(t_opt *opt, t_infos *infos);

/* check.c */
int		check_options(t_opt *opt, char **av);

/* init.c */
void	init_all(t_opt *opt, t_infos *infos);
char	*create_path_directory(char *arg);

/* recurse.c */
void	recurse_directory(t_infos *lst, char *path);
void	recurse_zis_dir(char *dir_name, char *path, t_dirent *dirp);
char	get_types(mode_t mode);

/* utils.c */
char	*get_rights(mode_t mode);
char	*cut_date(char *long_date);
int		ft_printf(char const *rfmt, ...);
void	display_name(t_infos *infos, t_dirent *dirp, DIR *dir);
void	test_statfile(t_infos **lst);

int		find_max_link(t_infos *lst);

#endif
