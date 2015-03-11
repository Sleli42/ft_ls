/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 14:42:32 by lubaujar          #+#    #+#             */
/*   Updated: 2014/11/13 15:00:46 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	ret;
	int		in_word;

	ret = 0;
	i = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] == c && in_word)
			in_word = !in_word;
		else if (s[i] != c && !in_word)
		{
			ret++;
			in_word = !in_word;
		}
		i++;
	}
	return (ret);
}

static char		**ft_alloc_tab(size_t nb_words)
{
	char	**to_return;

	to_return = (char **)ft_memalloc(sizeof(char *) * (nb_words + 1));
	if (to_return == NULL)
		return (NULL);
	to_return[0] = NULL;
	return (to_return);
}

static size_t	ft_lenght_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i] != c)
	{
		i++;
	}
	return (i);
}

static void		ft_split(char **to_return, char const *s, char c)
{
	size_t	tab;
	size_t	len_word;
	char	*word;

	tab = 0;
	while (*s)
	{
		len_word = ft_lenght_word(s, c);
		if (len_word != 0)
		{
			word = ft_strsub(s, 0, len_word);
			to_return[tab] = word;
			tab++;
		}
		s = s + len_word;
		while (*s == c)
			s++;
	}
	to_return[tab] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**to_return;
	size_t	nb_words;

	if (s == NULL)
		return (NULL);
	nb_words = ft_count_words(s, c);
	to_return = ft_alloc_tab(nb_words);
	if (to_return == NULL)
		return (NULL);
	ft_split(to_return, s, c);
	return (to_return);
}
