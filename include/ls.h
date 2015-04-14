/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:09:37 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/14 05:02:26 by lubaujar         ###   ########.fr       */
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
	int 			is_dir;
	t_stat			stat;
}				t_infos;

typedef struct 	s_all
{
	t_infos 		*content;
	struct s_all	*next;
	struct s_all 	*prev;
}				t_all;

/* test.c */
void	test_opt(t_opt *opt);
void	test_dir2(t_all *lst);
void	test_path(t_all *lst);
void	test_statfile(t_all **lst);
void	test_sort(t_all **lst);
void 	test_lst(t_all *lst);

/* add.c */
t_infos *add_statfile(char *path, char *filename, t_dirent *dirp);

/* sort.c */

/* lst.c */
void	lst_add_elem(t_all **alst, t_all *elem);
void	lst_add_elem_back(t_all **alst, t_all *elem);
t_all	*lst_create_elem(t_infos *infos);
int 	len_lst(t_all *lst);
void	del_lst(t_all *alst);
t_all	*create_lst(char *path);

/* main.c */
int		main(int ac, char **av);
void	read_directory(t_opt *opt, t_all *all);

/* check.c */
void	check_options(t_opt *opt, char **av);

/* init.c */
void	init(t_opt *opt, t_all *all);
void 	init_all(t_all *all);
void 	init_opt(t_opt *opt);

/* recurse.c */
void	test_recurse(t_all *lst, t_opt *opt);

/* utils.c */
char	*get_rights(mode_t mode);
char	*cut_date(char *long_date);
int		ft_printf(char const *rfmt, ...);
int 	is_parent_or_current(char *name);
int 	get_type2(unsigned char c);
char 	get_type(mode_t mode);

int		find_max_link(t_all *lst);

/* display.c */
void	display_recurse(char *path, t_all *recurse, t_opt *opt);
void	display_lst(t_all **lst, t_opt *opt);
void 	display_lst2(t_all *all, t_opt *opt);
#endif
