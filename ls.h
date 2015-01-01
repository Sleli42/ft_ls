/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 01:56:58 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/29 17:33:04 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

// lib opendir/readdir/closedir
# include <dirent.h>
// lib stat & co
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>	// listxattr
# include <pwd.h>		// getpwuid
# include <grp.h>		// getgrgid*
# include <uuid/uuid.h>	// getgrgid*
# include <time.h>		// time/ctime
# include <stdlib.h>
# include <stdio.h>

typedef struct dirent	t_dirent;
typedef struct stat		t_statfile;
typedef struct passwd	t_pwd;
typedef struct group	t_grp;

typedef struct	s_opt
{
	int		l;
	int		a;
	int		t;
	int		r;
	int		no_option;
}				t_opt;

typedef struct	s_stat
{
	char	*path;
	char	*name;
	char	*user;
	char	*grp;
	char	*rights;
	char	*date;
	char	*link;
	char	*size;
	struct s_stat *next;
	struct s_stat *prev;
}				t_stat;

//		CHECK OPTIONS
int		check_opt(t_opt *opt, char **argv);
void	enable_opt(t_opt *opt, char c);
void	init_opt(t_opt *opt);

//		READDIR.C + main
void	readdirectory(t_opt *opt, t_stat *lst, char *path);
char	*current_path(char *args);

//		INIT_LST.C
void	lst_add_stat(t_stat **begin, t_dirent *entry, char *path);
void	lst_print(t_stat *lst, t_opt *opt);
void	lst_print_reverse(t_stat *lst, t_opt *opt);
void	del_lst_elem(t_stat **elem);
t_stat	*new_elem(t_dirent *entry, char *path);

//		FCT USES
char	*ft_strdup(char const *s);
void	ft_putendl(char *s);
void	ft_putstr(char *s);
void	*ft_memalloc(size_t size);
char	*ft_strnew(size_t size);
char	*ft_itoa(int size);

// 		FUNC.C
int		define_max_len_octet(t_stat *lst);
int		define_max_len_link(t_stat *lst);
char	*size_cpy(char *c_size, int max_len);
char	*link_cpy(char *c_size, int max_len);

//		FIND_MAX_LEN.C
int		compare(int len, int max_len);
void	define_size(t_stat *lst, int max_len);
void	define_link(t_stat *lst, int max_link);

//		INFOS.c
void	get_infos(t_stat *elem, t_statfile *sb);
char	*ft_chmod(char *file, struct stat *stat);
char	*cut_date(char *time);
t_stat	*sort_t_opt(t_stat *lst);

//		DISPLAY OPTIONS
void	display_opt(t_opt *opt, t_stat *lst);
void	opt_l_display(t_stat *lst, t_opt *opt);
void	opt_l_reverse_display(t_stat *lst, t_opt *opt);
void	display_infos(t_stat *lst);
void	basic_display_reverse(t_stat *lst, t_opt *opt);

#endif
