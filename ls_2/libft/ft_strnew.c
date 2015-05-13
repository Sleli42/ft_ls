/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:56:55 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/15 04:03:05 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(unsigned int size)
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc(sizeof(char *) * size + 1);
	i = 0;
	if (str == NULL)
		return ((char *)NULL);
	else
	{
		while (i++ < size)
		{
			str[i] = 0;
		}
		str[i] = '\0';
	}
	return ((char *)str);
}
