/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prec_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:02:33 by sdavos            #+#    #+#             */
/*   Updated: 2021/12/14 16:02:36 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	width_prec2(const char *format, size_t *i, va_list ap, t_flag flag)
{
	(*i)++;
	if (format[*i] == '*')
	{
		flag.option_of_precision = 1;
		flag.precision = va_arg(ap, int);
		(*i)++;
	}
	if (((ft_type_check(format[*i])
				|| format[*i] == '0') && flag.option_of_precision == 0)
		|| (ft_type_check(format[*i]) || format[*i] == '0'))
		flag.option_of_precision = 2;
	else
		flag.option_of_precision = 1;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		flag.precision = flag.precision * 10 + format[*i] - '0';
		(*i)++;
	}
	return (flag);
}

t_flag	width_prec1(const char *format, size_t *i, va_list ap, t_flag flag)
{
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		flag.width = flag.width * 10 + format[*i] - '0';
		(*i)++;
	}
	if (format[*i] == '.')
		flag = width_prec2(format, i, ap, flag);
	return (flag);
}

int	type_is_2(int type, va_list ap, t_flag flag, int count)
{
	if (type == 'p')
	{
		flag.type = 'p';
		count += ft_print_address(ap, flag);
	}
	else if (type == '%')
	{
		flag.type = '%';
		count += ft_print_precent(flag);
	}
	else if (type == 'c')
	{	
		flag.type = 'c';
		count += ft_print_char(ap, flag);
	}
	else if (type == 's')
	{	
		flag.type = 's';
		count += ft_print_string(ap, flag);
	}
	return (count);
}

int	type_is_1(int type, va_list ap, t_flag flag, int count)
{
	if (type == 'u')
	{
		flag.type = 'u';
		count += ft_print_unsint(ap, flag);
	}
	else if (type == 'x')
	{
		flag.type = 'x';
		count += ft_print_x(ap, flag);
	}
	else if (type == 'X')
	{
		flag.type = 'X';
		count += ft_print_x(ap, flag);
	}
	else
		count = type_is_2(type, ap, flag, count);
	return (count);
}

int	type_is_0(int type, va_list ap, t_flag flag, int count)
{
	if (type == 'd' || type == 'i')
	{
		flag.type = 'd';
		count += ft_print_integer(ap, flag);
	}
	else
		count = type_is_1(type, ap, flag, count);
	return (count);
}
