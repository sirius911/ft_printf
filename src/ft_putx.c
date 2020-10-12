/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:16:59 by clorin            #+#    #+#             */
/*   Updated: 2020/10/08 15:17:01 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_putx(t_flags *flags, va_list param, char *base)
{
	int				i;
	unsigned int	nbr;
	int				len;
	int				len_hex;

	i = 0;
	len = 0;
	nbr = (unsigned int)va_arg(param, unsigned int);
	len_hex = ft_len_nbr_base(nbr, base);
	len = (flags->precision > len_hex) ? flags->precision : len_hex;
	if (flags->precision == 0 && nbr == 0)
		return (i += ft_putnchar(' ', flags->width));
	if (flags->left == 0 && (flags->zero == 0 || flags->precision != -1))
		i += ft_putnchar(' ', flags->width - len);
	if (flags->zero == 1 && flags->precision == -1)
		i += ft_putnchar('0', flags->width - len);
	if (flags->precision > len_hex)
		i += ft_putnchar('0', flags->precision - len_hex);
	i += ft_print_nbr_base(nbr, base);
	if (flags->left == 1)
		i += ft_putnchar(' ', flags->width - len);
	return (i);
}
