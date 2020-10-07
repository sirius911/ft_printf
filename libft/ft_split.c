/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 15:24:16 by clorin            #+#    #+#             */
/*   Updated: 2020/09/22 15:50:15 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_word(char const *str, char c)
{
	size_t		i;
	int			cmpt;

	i = 0;
	cmpt = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			cmpt++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (cmpt);
}

char			**ft_split(char const *s, char c)
{
	char		**dest;
	int			i;
	int			y;
	int			j;

	i = 0;
	y = 0;
	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (nb_word(s, c) + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			dest[y++] = ft_strndup(s + j, i - j);
	}
	dest[y] = NULL;
	return (dest);
}
