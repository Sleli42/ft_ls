/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:09:37 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/13 01:40:25 by lubaujar         ###   ########.fr       */
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
# include <stdlib.h>

#include <stdio.h>


typedef struct	dirent	t_dirent;
typedef struct	stat	t_stat;


typedef struct	s_opt
{
	int				a;
	int				l;
	int				t;
	int				r;
	int				R;
}				t_opt;

typedef struct 	s_maxlen
{
	unsigned int 	link;
	unsigned int 	octet;
	unsigned int 	uid;				INIT STRUCT
	unsigned int 	gid;				MALLOC STRUCT
}				t_maxlen;

typedef struct	s_infos
{
	char			*path;
	char			*name;
	char 			*date;
	time_t 			timesec;
	char 			*rights;
	char 			*link;
	char 			*size;
	char 			*s_uid;
	char 			*s_gid;
	int 			is_dir;
	int				blksize;
}				t_infos;

typedef struct 	s_all
{
	t_infos 		*content;
	struct s_all	*next;
	struct s_all 	*prev;
}				t_all;

/*
** main.c **
*/
int 		main(int ac, char **av);
/*
** init.c **
*/
t_opt 		*init_opt(void);
t_infos		*data_init(char *filename, char *path, t_opt *opt);
/*
** lst.c **
*/
t_all		*lst_create_elem(t_infos *infos);
void 		lst_add_elem_back(t_all **alst, t_all *new_elem);
int			len_lst(t_all *tmp);
void		del_lst(t_all *alst);
/*
** displays.c **
*/
void 		display_lst(t_all *list, t_opt *opt);
void 		display_statfile(t_infos *curr);
void 		long_display(t_all *all, t_opt *opt);
/*
** sort.c **
*/
void 		sort_lists(t_all **list, t_opt *opt);
void 		swap_elem(t_all **a, t_all **b);
void 		sort_args(t_all **alst);
void 		sort_name(t_all **alst);
void 		sort_time(t_all **alst);
/*
** recurse.c **
*/
void 		recurse_dir(t_all *dirs, t_opt *opt);
t_all 		*recurse_to_dir(t_opt *opt, char *dir_name);
/*
** reddirectory.c **
*/
void 		read_files(t_all **args, t_opt *opt);
void 		read_dirs(t_all *args_dir, t_opt *opt);
t_all 		*open_directory(t_opt *opt, char *dir_path);
/*
** utils.c **
*/
char		*get_rights(mode_t mode);
char		get_type(mode_t mode);
char 		*major_minor_to_str(t_stat *stat);
char		*cut_date(char *long_date);
int			is_parent_or_current(char *name);
/*
** utils_2.c **
*/
t_all		*goto_last_elem(t_all *all);
int 		define_blksize(t_all *all, t_opt *opt);
/*
** error.c **
*/
void 		error_opt(char bad_opt);
/*
** check.c **
*/
void 		list_opts(t_opt *opt, char *s);
void 		list_elem(t_all **args, t_opt *opt, char *filename, char *path);

#endif
