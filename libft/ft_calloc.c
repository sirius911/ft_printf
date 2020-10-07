/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:13:28 by clorin            #+#    #+#             */
/*   Updated: 2020/10/02 11:14:35 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void		*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size <= 0 || count <= 0)
		return ((void *)NULL);
	ptr = ft_memalloc(size * count);
	return (ptr);
}
