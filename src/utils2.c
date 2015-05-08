/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 18:47:38 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/07 17:22:04 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char 	*create_str(char *s, int max)
{
	char 	*ret;
	int 	i;

	ret = (char *)malloc(sizeof(char) * max + 1);
	i = 0;
	while (i < max - ((int)ft_strlen(s)))
		ret[i++] = ' ';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char 	*create_str_uidgid(char *s, int max)
{
	char 	*ret;
	int 	i;

	ret = (char *)malloc(sizeof(char) * max + 1);
	i = 0;
	while (*s)
		ret[i++] = *s++;
	while (i < max)
		ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}
