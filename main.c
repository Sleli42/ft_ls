/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 19:35:26 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/08 05:19:40 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "list.h"

char	*ft_hours(char *time)
{
	char	*tmp;
	char	*time_ret;
	unsigned int	i;
	unsigned int	j;

	if (time == NULL)
		return ;
	tmp = ft_strnew(ft_strlen(time));
	i = 0;
	if (tmp == NULL)
		return ;
	while (i < ft_strlen(time) + 4)
	{
		if (i >= 4)
			tmp[i - 4] = time[i];
		i++;
	}
	while (tmp[i] != ':')
		i--;
	time_ret = ft_strnew(i);
	j = 0;
	while (j < i)
	{
		time_ret[j] = tmp[j];
		j++;
	}
	return (time_ret);
}

void	ft_chmod(char *file, struct stat *buff)
{
	((S_ISREG(buff->st_mode) == 1) ? ft_putchar('-') : 1);
	((S_ISDIR(buff->st_mode) == 1) ? ft_putchar('d') : 1);
	((S_ISCHR(buff->st_mode) == 1) ? ft_putchar('c') : 1);
	((S_ISLNK(buff->st_mode) == 1) ? ft_putchar('l') : 1);
	((buff->st_mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-'));
	((buff->st_mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-'));
	((buff->st_mode & S_IXUSR) ? ft_putchar('x') : ft_putchar('-'));
	((buff->st_mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-'));
	((buff->st_mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-'));
	((buff->st_mode & S_IXGRP) ? ft_putchar('x') : ft_putchar('-'));
	((buff->st_mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-'));
	((buff->st_mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-'));
	((buff->st_mode & S_IXOTH) ? ft_putchar('x') : ft_putchar('-'));
	if (listxattr(file, NULL, 5, XATTR_NOFOLLOW) > 0)		// XATTR_NOFOLLOW affiche sans rien avant
		ft_putchar('@');
	ft_putchar(' ');
	ft_putchar(' ');
}

void	ls_no_option(char *file)
{

}

int		cut_size(int size, int stop)
{
	char			*c_size;
	char			*tmp;
	int				i;
	int				j;
	static int		len_max;
	int				white;

	c_size = ft_itoa(size);
	i = 0;
	if (stop == 0)
	{
		tmp = (char *)malloc(sizeof(char *) * ft_strlen(c_size) + 1);
		while (c_size[i])
		{
			tmp[i] = c_size[i];
			i++;
		}
		tmp[i] = '\0';
		ft_putstr(tmp);
		len_max = i;
	}
	else if (stop > 0)
	{
		i = 0;
		j = 0;
		white = ft_strlen(c_size);
		tmp = (char *)malloc(sizeof(char *) * len_max);
		while (i < len_max)
		{
			if (i < len_max - white)
			{
				tmp[i] = ' ';
			}
			else
			{
				while (c_size[j] != '\0')
				{
					tmp[i++] = c_size[j++];
				}
			}
			i++;
		}
		ft_putstr(tmp);
	}
	stop++;
	return (stop);
}

void	ls_l_option(char *file, struct stat *buff, int stop)
{
	struct passwd	*uid;
	struct group	*gid;
	int				i;

	i = 2;
	stat(file, buff);
	uid = getpwuid(buff->st_uid);
	gid = getgrgid(buff->st_gid);
	ft_chmod(file, buff);
	ft_putnbr(buff->st_nlink);
	ft_putchar(' ');
	ft_putstr(uid->pw_name);
	ft_putchar(' ');
	ft_putchar(' ');
	ft_putstr(gid->gr_name);
	ft_putchar(' ');
	ft_putchar(' ');
	stop = cut_size(buff->st_size, stop);
	ft_putchar(' ');
	ft_putstr(ft_hours(ctime(&buff->st_mtime)));
	ft_putchar(' ');
	ft_putstr(file);
	ft_putchar('\n');
	return;
}

void	checkfile(char *file, t_option *opt, struct stat *buff, int stop)
{
	if (opt->no_option == '1')					// ls -1[faux] ls par colonne !!!!!!!!!!!!
		ls_no_option(file);
	if (opt->l == '1')
		ls_l_option(file, buff, stop);						// NE RENTRE PAS DANS LE -l 
	//if (opt->a == '1')
	//ls_a_option();
}

void	readdirectory(char *dir, t_option *opt)
{
	DIR				*ret;
	struct dirent	*lecture;
	struct stat		*buff;
	char			*file[30];
	int				i;
	int				stop;

	i = 0;
	stop = 0;
	if ((ret = opendir(dir)) != NULL)
	{
		while ((lecture = readdir(ret)) != NULL)
		{
			if(!(file[i] = (char *)malloc(sizeof(char *) + 1)))
				error(6);
			if (!(buff = (struct stat *)malloc(sizeof(struct stat))))
				error(6);
			if (lecture->d_name[0] != '.')
			{
				//ft_putstr(lecture->d_name);
				//ft_strcpy(file[i++], lecture->d_name);
				checkfile(lecture->d_name, opt, buff, stop);
				stop++;
			}
		}
		//checkfile(file, opt, buff);
	}
	else
	{
		error(4);
		error(5);
		return ;
	}
}

int		checkoptions(char *str, t_option *opt)
{
	int			i;

	i = 0;
	if (str[i] != '-')
		opt->no_option = '1';
	if (str[i] == '\0')
		error(3);
	if (str[i] == '-' && str[i + 1] == '\0')
	{
		error(2);
		error(5);
		return (0);
	}
	i++;
	if (str[0] == '-')
	{
		while (str[i] != '\0')
		{
			if (str[i] == 'a' || str[i] == 'l' || str[i] == 'R'
					|| str[i] == 't')
			{
				enable_options(str, opt);
			}
			else
			{
				error(1);
				error(2);
				//error(5);
				return (0);
			}
			i++;
		}
	}
	return (1);
}

void	error(int code_error)
{
	if (code_error == 1)
	{
		ft_putstr("Bad option..");
	}
	if (code_error == 2)
	{
		ft_putstr("Add options [-alRt]");
	}
	if (code_error == 3)
	{
		ft_putstr("No options");
	}
	if (code_error == 4)
	{
		ft_putstr("Bad directory");
		//ft_putchar('\n');
	}
	if (code_error == 5)
	{
		ft_putstr("Add directory");
	}
	if (code_error == 6)
	{
		ft_putstr("Error memory allocation");
	}
}

void	enable_options(char *str, t_option *opt)
{
	int		i;

	i = 0;
	if (str[i + 1] == 'a')
		opt->a = '1';
	else if (str[i + 1] == 'l')
		opt->l = '1';
	else if (str[i + 1] == 'R')
		opt->r = '1';
	else if (str[i + 1] == 't')
		opt->t = '1';
}

void	init_options(t_option *opt)
{
	opt->l = '0';
	opt->a = '0';
	opt->r = '0';
	opt->t = '0';
	opt->no_option = '0';
}

int		main(int argc, char **argv)
{
	int			i;
	t_option	opt;

	i = 1;
	init_options(&opt);
	if (argc > 1)
	{
		if (*argv[1] != '-')
		{
			error(3);
			error(2);
			return (0);
		}
		else if ((checkoptions(argv[i], &opt)) == 1)
		{
			readdirectory(argv[++i], &opt);
		}
	}	
	return (0);
}
