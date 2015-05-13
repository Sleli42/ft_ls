/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 19:17:19 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/11 19:53:26 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void 	error_opt(char bad_opt)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(bad_opt);
	ft_putstr("\nusage: ls [-Ralrt] [file ...]\n");
}
