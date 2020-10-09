/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:03:19 by clorin            #+#    #+#             */
/*   Updated: 2020/10/07 14:03:22 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			print_moins(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		return (1);
	}
	return (0);
}

static int			len_nbr(int nbr)
{
	int				i;
	unsigned int	nb;

	i = 1;
	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static int			ft_print_long(long nbr)
{
	int				i;

	i = 0;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr >= 10)
	{
		ft_print_long(nbr / 10);
		ft_print_long(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
	return (len_nbr(nbr));
}

int					ft_putdi(t_flags *flags, va_list param)
{
	int				i;
	int				nbr;
	int				len;
	int				len_nosign;

	i = 0;
	len = 0;
	nbr = (int)va_arg(param, int);
	len_nosign = len_nbr(nbr);
	if (nbr < 0)
		flags->width--;
	len = (flags->precision > len_nosign) ? flags->precision : len_nosign;
	if (flags->precision == 0 && nbr == 0)
		return (i += ft_putnchar(' ', flags->width));
	if (flags->left == 0 && (flags->zero == 0 || flags->precision != -1))
		i += ft_putnchar(' ', flags->width - len);
	i += print_moins(nbr);
	if (flags->zero == 1 && flags->precision == -1)
		i += ft_putnchar('0', flags->width - len);
	if (flags->precision > len_nosign && flags->precision != -1)
		i += ft_putnchar('0', flags->precision - len_nosign);
	i += ft_print_long(nbr);
	if (flags->left == 1)
		i += ft_putnchar(' ', flags->width - len);
	return (i);
}
