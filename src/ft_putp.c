/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:43:10 by clorin            #+#    #+#             */
/*   Updated: 2020/10/12 10:43:13 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_zero(int left, int width)
{
	int			i;

	i = 2;
	if (left)
	{
		ft_putstr("0x");
		i += ft_putnchar(' ', width);
	}
	else
	{
		i += ft_putnchar(' ', width);
		ft_putstr("0x");
	}
	return (i);
}

int		ft_putp(t_flags *flags, va_list param)
{
	int		i;
	long	nbr;
	int		len;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	nbr = (long)va_arg(param, long);
	flags->width -= 2;
	len = flags->precision > ft_len_nbr_base(nbr, base)
			? flags->precision : ft_len_nbr_base(nbr, base);
	if (nbr == 0 && flags->precision == 0)
		return (ft_zero(flags->left, flags->width));
	if (flags->left == 0 && (flags->zero == 0 || flags->precision != -1))
		i += ft_putnchar(' ', flags->width - len);
	ft_putstr("0x");
	i += 2;
	if (flags->zero && flags->precision == -1)
		i += ft_putnchar('0', flags->width - len);
	if (flags->precision > ft_len_nbr_base(nbr, base))
		i += ft_putnchar('0', flags->precision - ft_len_nbr_base(nbr, base));
	i += ft_print_nbr_base(nbr, base);
	if (flags->left)
		i += ft_putnchar(' ', flags->width - len);
	return (i);
}

