/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:15:27 by lubaujar          #+#    #+#             */
/*   Updated: 2014/11/13 14:41:17 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	while (*s != (char)c && *s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
