/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:30:36 by clorin            #+#    #+#             */
/*   Updated: 2020/09/22 13:57:18 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t		min;
	size_t		max;

	if (!s)
		return (NULL);
	min = 0;
	while (s[min] && (s[min] == ' ' || s[min] == '\n' || s[min] == '\t'))
		min++;
	max = ft_strlen(s);
	while (min < max && (s[max - 1] == ' ' || s[max - 1] == '\n' ||
		s[max - 1] == '\t'))
		max--;
	if (min == max)
		return (ft_strnew(1));
	return (ft_substr(s, min, (max - min)));
}
