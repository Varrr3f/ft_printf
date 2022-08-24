/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer_help_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:02:01 by sdavos            #+#    #+#             */
/*   Updated: 2021/12/14 16:02:04 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(t_flag *flag, long n)
{
	long	g;

	if (n < 0)
		n = -n;
	if (n / 10)
	{
		ft_putnbr(flag, n / 10);
	}
	g = n % 10 + '0';
	write(1, &g, 1);
	flag->width--;
}

int	ft_putnbr_len(t_flag *flag, long n)
{
	if (n < 0)
		n = -n;
	if (n / 10)
	{
		flag->length_n++;
		ft_putnbr_len(flag, n / 10);
	}
	return (flag->length_n + 1);
}

int	ft_pr_int_flags(int n, int len, t_flag *flag)
{
	if (n < 0)
		flag->minus = 1;
	else
		flag->minus = 0;
	if (n == 0)
		flag->zero_is_number = 1;
	else
		flag->zero_is_number = 0;
	flag->write = ft_putnbr_len(flag, n) + flag->minus;
	len += flag->write;
	if (flag->left_shift == 1 && flag->padding_zeros == 1)
		flag->padding_zeros = 0;
	if ((flag->option_of_precision == 1 || flag->option_of_precision == 2)
		&& flag->precision >= flag->write)
		flag->zeros = flag->precision - flag->write + flag->minus;
	else if (flag->option_of_precision == 2 && flag->precision == 0 && n == 0)
		flag->write = 0;
	if (!flag->left_shift)
		flag->width = flag->width - flag->write - flag->zeros;
	return (len);
}

int	ft_int_write_help(int len, t_flag *flag)
{
	while (flag->width-- > 0)
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}

int	ft_print_integer1(int len, t_flag *flag)
{
	if (flag->padding_zeros == 1 && !flag->left_shift
		&& (flag->option_of_precision == 0 || flag->option_of_precision == 2))
	{
		if (flag->minus == 1 && flag->padding_zeros == 1
			&& flag->one_argument == 0)
		{
			write(1, "-", 1);
			flag->one_argument = 1;
		}
		if (!(flag->width > flag->precision && flag->precision == 0
				&& flag->option_of_precision == 2))
		{
			while (flag->width-- > 0)
			{
				write(1, "0", 1);
				len++;
			}
		}
	}
	else if (!flag->left_shift)
		len = ft_int_write_help(len, flag);
	return (len);
}
