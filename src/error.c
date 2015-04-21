/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 16:03:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/04/21 16:06:00 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void 	error(int error)
{
	if (error == 0) /* illegal option */
		ft_printf("ls: illegal option -- ,\nusage: ls [-Ralrt] [file ...]\n");
}
