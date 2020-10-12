/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:12:11 by clorin            #+#    #+#             */
/*   Updated: 2020/10/06 12:12:13 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_arg(const char *format, t_flags *flags, va_list param)
{
	int			i;

	i = 0;
	if (*format == '%' && (i = 1))
		ft_putchar('%');
	else if (*format == 'c')
		i += ft_putc(flags, param);
	else if (*format == 's')
		i += ft_puts(flags, param);
    else if (*format == 'd' || *format == 'i')
        i += ft_putdi(flags, param);
    else if (*format == 'u')
    	i += ft_putu(flags, param);
    else if (*format == 'x')
    	i += ft_putx(flags, param, "0123456789abcdef");
    else if (*format == 'X')
    	i += ft_putx(flags, param, "0123456789ABCDEF");
    else if (*format == 'b')
    	i += ft_putx(flags, param, "01");
	return (i);
}
