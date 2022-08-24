/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:02:01 by sdavos            #+#    #+#             */
/*   Updated: 2021/12/14 16:02:04 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_integer2(int n, int len, t_flag *flag)
{
	if (n < 0 && flag->padding_zeros == 0)
	{
		write(1, "-", 1);
		flag->width--;
	}
	while (flag->zeros-- > 0)
	{
		if (flag->minus == 1 && flag->padding_zeros == 1
			&& flag->one_argument == 0)
		{
			write(1, "-", 1);
			flag->width--;
			flag->one_argument = 1;
		}
		write(1, "0", 1);
		len++;
		flag->width--;
	}
	return (len);
}

int	ft_print_integer4(int len, t_flag *flag)
{
	if (flag->width > 0)
	{
		while (flag->width-- > 0)
		{
			write(1, " ", 1);
			len++;
		}
		len--;
	}
	else
	{
		write(1, NULL, 1);
		return (len - 1);
	}
	return (len);
}

int	ft_print_integer3(int n, int len, t_flag *flag)
{
	if (flag->option_of_precision == 2 && flag->precision == 0 && n == 0)
		len = ft_print_integer4(len, flag);
	else
	{
		if (flag->minus == 1 && flag->padding_zeros == 1
			&& flag->one_argument == 0)
		{
			write(1, "-", 1);
			flag->width--;
		}
		ft_putnbr(flag, n);
	}
	return (len);
}

int	ft_print_integer(va_list list, t_flag flag)
{
	int	n;
	int	len;

	len = 0;
	n = va_arg(list, int);
	len = ft_pr_int_flags(n, len, &flag);
	len = ft_print_integer1(len, &flag);
	len = ft_print_integer2(n, len, &flag);
	len = ft_print_integer3(n, len, &flag);
	if (flag.left_shift)
	{
		while (flag.width > 0)
		{
			write(1, " ", 1);
			len++;
			flag.width--;
		}
	}
	return (len);
}
