/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:38:16 by clorin            #+#    #+#             */
/*   Updated: 2020/10/12 10:38:18 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_len_nbr_base(long nbr, char *base)
{
	int		i;
	int		len_base;

	i = 0;
	if (nbr == 0)
		return (1);
	if(nbr < 0)
		nbr = -nbr;
	len_base = ft_strlen(base);
	if (len_base == 0)
		return (0);
	while (nbr > 0)
	{
		i++;
		nbr /= len_base;
	}
	return (i);
}

int			ft_print_nbr_base(long nbr, char *base)
{
	int		i;
	int		len_base;

	i = 0;
	len_base = ft_strlen(base);
	if (nbr >= len_base)
	{
		ft_print_nbr_base(nbr / len_base, base);
		ft_print_nbr_base(nbr % len_base, base);
	}
	else
		ft_putchar(base[nbr % len_base]);
	return (ft_len_nbr_base(nbr, base));
}
