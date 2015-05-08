/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:09:37 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/08 18:51:08 by lubaujar         ###   ########.fr       */
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
	char 			*date;
	char 			*rights;
	char 			*link;
	char 			*size;
	char 			*s_uid;
	char 			*s_gid;
	int 			is_dir;
	unsigned int	blksize;
	t_stat			stat;
}				t_infos;

typedef struct 	s_all
{
	t_infos 		*content;
	struct s_all	*next;
	struct s_all 	*prev;
}				t_all;

void	ft_error(char *err, int ex); //warning exit()

int 	ft_printf(const char *s, ...);

/* test.c */
void	test_dir2(t_all *lst);
void	test_path(t_all *lst);
void	test_statfile(t_all **lst);
void	test_sort(t_all **lst);
void 	test_lst(t_all *lst);
void 	test_opt(t_opt *opt);
void 	test_value_s(t_all *all);
void 	test_major_minor(t_all *all);

/* add.c */
t_infos *add_statfile(char *path, char *filename, t_dirent *dirp);

/* sort.c */
void 	sort_name(t_all **alst);
void 	sort_time(t_all **alst);
t_all 	*reverse_list(t_all *alst);

/* lst.c */
void	lst_add_elem(t_all **alst, t_all *elem);
void	lst_add_elem_back(t_all **alst, t_all *elem);
t_all	*lst_create_elem(t_infos *infos);
int 	len_lst(t_all **lst);
void	del_lst(t_all *alst);
t_all	*create_lst(char *path);

/* main.c */
int		main(int ac, char **av);
void 	display_alone_file(t_all *all, t_opt *opt, char **av, int ac);
void 	list_file(t_all *all, t_opt *opt, char **av, int ac, int ct);
void 	list_dir(t_all *all, t_opt *opt, char **av, int ac, int ct);
void	read_directory(t_opt *opt, t_all *all);

/* check.c */
int 	check_options(t_opt *opt, char **av, int ac);

/* init.c */
void	init(t_opt *opt, t_all *all);
void 	init_all(t_all *all);
void 	init_opt(t_opt *opt);

/* recurse.c */
void	test_recurse(t_all *lst, t_opt *opt);

/* utils.c */
char	*get_rights(mode_t mode);
char	*cut_date(char *long_date);
int 	is_parent_or_current(char *name);
char 	get_type(mode_t mode);
void	define_maxlen(t_all **alst);

/* utils2.c */
char 	*create_str(char *s, int max);
char 	*create_str_uidgid(char *s, int max);

/* utils3.c */
int 	define_blksize(t_all **all, t_opt *opt);
t_all	*goto_last_elem(t_all *all);
int 	count_dir(int ac, char **av);
char 	*major_minor_to_str(t_stat *stat);

/* display.c */
void 	displays(t_all *all, t_opt *opt);
void	display_recurse(char *path, t_all *recurse, t_opt *opt);
void 	display_lst(t_all *all, t_opt *opt);
void 	display_statfile(t_all *all, t_opt *opt);
void 	display_infos(t_infos *curr);

/* search.c */
int 	search_max_size(t_all *lst);
int 	search_max_link(t_all *lst);
int 	search_max_uid(t_all *lst);
int 	search_max_gid(t_all *lst);

/* modif.c */
void 	modif_size(t_all **lst, int max);
void 	modif_link(t_all **lst, int max);
void 	modif_uid(t_all **lst, int max);
void 	modif_gid(t_all **lst, int max);

/* error.c */
void 	error(int error);

#endif
