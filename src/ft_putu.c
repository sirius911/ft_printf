/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:20:16 by clorin            #+#    #+#             */
/*   Updated: 2020/10/09 12:20:18 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			len_nbr(unsigned int nbr)
{
	int				i;

	i = 1;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static int			ft_print_u(unsigned int  nbr)
{
	if (nbr >= 10)
	{
		ft_print_u(nbr / 10);
		ft_print_u(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
	return (len_nbr(nbr));
}

int					ft_putu(t_flags *flags, va_list param)
{
	int				i;
	unsigned int	nbr;
	int				len;
	int				len_nosign;

	i = 0;
	len = 0;
	nbr = (unsigned int)va_arg(param, unsigned int);
	len_nosign = len_nbr(nbr);
	len = (flags->precision > len_nosign) ? flags->precision : len_nosign;
	if (flags->precision == 0 && nbr == 0)
		return (i += ft_putnchar(' ', flags->width));
	if (flags->left == 0 && (flags->zero == 0 || flags->precision != -1))
		i += ft_putnchar(' ', flags->width - len);
	if (flags->zero == 1 && flags->precision == -1)
		i += ft_putnchar('0', flags->width - len);
	if (flags->precision > len_nosign && flags->precision != -1)
		i += ft_putnchar('0', flags->precision - len_nosign);
	i += ft_print_u(nbr);
	if (flags->left == 1)
		i += ft_putnchar(' ', flags->width - len);
	return (i);
}

