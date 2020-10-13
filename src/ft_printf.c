/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:45:05 by clorin            #+#    #+#             */
/*   Updated: 2020/10/04 15:45:12 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		param;
	size_t		written_char;
	int			i;
	t_flags		*flags;

	va_start(param, format);
	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (-1);
	written_char = 0;
	i = 0;
	while (format[i])
	{

		if (format[i] != '%' && (written_char += 1))
			ft_putchar(format[i]);
		else
		{
			if (format[i + 1] == '%')
			{
				ft_putchar('%');
				i++;
				written_char++;
			}
			else
			{
				i += ft_set_flags(flags, &(format[i]), param);
				written_char += ft_print_arg(&(format[i]), flags, param);
			}
		}
		if (format[i])
			i++;
	}
	free(flags);
	va_end(param);
	return (written_char);
}
