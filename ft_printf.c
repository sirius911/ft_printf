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

#include "includes/ft_printf.h"

int     ft_printf(const char *format, ...)
{
    va_list     param;
    size_t      written_char;
    
    va_start(param, format);
    written_char = 0;
    while (*format)
    {
        if (*format != '%')
        {
            ft_putchar(*format);
            written_char++;
        }
        format++;
    }
    va_end(param);
    return (written_char);
}