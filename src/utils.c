/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 03:58:30 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/30 00:12:33 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*cut_date(char *long_date)
{
	char	*s;
	int		i;
	int		j;

	s = (char *)malloc(sizeof(char) * 12 + 1);
	i = 4;
	j = 0;
	ft_printf("date[c]: |%c|\n", long_date[i]);
	j = 0;
	while (i - 4 < 12)
	{
		s[j++] = long_date[i++];
		// i++;
		// j++;
	}
	s[i] = '\0';
	//ft_printf("date: %s\n", long_date);
	return (s);
}
