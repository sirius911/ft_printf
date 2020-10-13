/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 14:17:19 by clorin            #+#    #+#             */
/*   Updated: 2020/10/06 14:17:21 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putc(t_flags *flags, va_list param, char c)
{
	int		i;

	i = 1;
	if (c != '%')
		c = (char)va_arg(param, int);
	if (flags->left == 1)
	{
		write(1, &c, 1);
		i += ft_putnchar(' ', flags->width - 1);
	}
	else if (flags->left == 0)
	{
		if (flags->zero == 1)
			i += ft_putnchar('0', flags->width - 1);
		else
			i += ft_putnchar(' ', flags->width - 1);
		write(1, &c, 1);
	}
	return (i);
}
