/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 10:59:54 by clorin            #+#    #+#             */
/*   Updated: 2020/10/06 10:59:56 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	flags_init(t_flags *flags)
{
	flags->zero = 0;
	flags->left = 0;
	flags->precision = -1;
	flags->width = 0;
}

static int	padding(t_flags *flags, const char *format, va_list param)
{
	int		i;
	int		arg_width;

	i = 0;
	arg_width = 0;
	if (ft_isdigit(format[i]))
		flags->width = ft_atoi(&format[i]);
	else
	{
		arg_width = (int)va_arg(param, int);
		if (arg_width < 0)
		{
			arg_width = -arg_width;
			flags->left = 1;
			flags->zero = 0;
		}
		flags->width = arg_width;
		return (1);
	}
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

static int	precision(t_flags *flags, const char *format, va_list param)
{
	int		i;
	int		arg_precis;

	i = 1;
	arg_precis = 0;
	if (ft_isdigit(format[i]))
	{
		flags->precision = ft_atoi(&format[i]);
		if (flags->precision < 0)
			flags->precision = -1;
	}
	else if (format[i] == '*')
	{
		arg_precis = (int)va_arg(param, int);
		if (arg_precis < 0)
			flags->precision = -1;
		else
			flags->precision = arg_precis;
		return (i + 1);
	}
	else
		flags->precision = 0;
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

int			ft_set_flags(t_flags *flags, const char *format, va_list param)
{
	int		i;

	i = 1;
	flags_init(flags);
	while (ft_isdigit(format[i]) || ft_strchr("-*.", format[i]))
	{
		if (format[i] == '0' && !flags->left)
		{
			flags->zero = 1;
			i++;
		}
		else if (format[i] == '-')
		{
			flags->zero = 0;
			flags->left = 1;
			i++;
		}
		else if (ft_isdigit(format[i]) || format[i] == '*')
			i += padding(flags, &(format[i]), param);
		else if (format[i] == '.')
			i += precision(flags, &(format[i]), param);
	}
	return (i);
}
