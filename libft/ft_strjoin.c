/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:19:04 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/05 05:39:47 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	s1 = (s1 == NULL) ? "" : s1;
	s2 = (s2 == NULL) ? "" : s2;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char *) * len + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
