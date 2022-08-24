/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:02:52 by sdavos            #+#    #+#             */
/*   Updated: 2021/12/14 16:02:36 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_parse_flag(const char *format, size_t *i, va_list ap, t_flag flag)
{
	while (format[*i] == '0' || format[*i] == '*' || format[*i] == '-')
	{
		if (format[*i] == '*')
		{
			flag.width = va_arg(ap, int);
			(*i)++;
			if (flag.width < 0)
			{
				flag.width *= -1;
				flag.left_shift = 1;
			}
		}
		if (format[*i] == '0')
		{
			flag.padding_zeros = 1;
			(*i)++;
		}
		else if (format[*i] == '-')
		{
			flag.left_shift = 1;
			(*i)++;
		}
	}
	return (flag);
}

int	ft_type_check(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	print_type(const char *format, size_t *i, va_list ap, t_flag flag)
{
	int	count;

	count = 0;
	count = type_is_0(format[*i], ap, flag, count);
	(*i)++;
	return (count);
}

int	ft_parser(const char *format, size_t *i, va_list ap)
{
	t_flag	flag;

	flag = (t_flag){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	flag = ft_parse_flag(format, i, ap, flag);
	flag = width_prec1(format, i, ap, flag);
	return (print_type(format, i, ap, flag));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	size_t	i;

	len = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
			len++;
		}
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += ft_parser(format, &i, ap);
		}
		else if (format[i + 1] == '\0')
			i++;
	}
	va_end(ap);
	return (len);
}
