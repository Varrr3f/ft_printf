/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsint_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:02:52 by sdavos            #+#    #+#             */
/*   Updated: 2021/12/14 16:02:55 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_helper1(t_flag *flag, int *len)
{
	if (flag->padding_zeros && !flag->left_shift
		&& flag->option_of_precision == 0)
	{
		while (flag->width > 0)
		{
			write(1, "0", 1);
			(*len)++;
			flag->width--;
		}
	}
	else if (!flag->left_shift)
	{
		while (flag->width > 0)
		{
			write(1, " ", 1);
			(*len)++;
			flag->width--;
		}
	}
}

void	conversion_helper0(t_flag *flag, char type, int *len)
{
	if (flag->left_shift == 1 && flag->padding_zeros == 1)
		flag->padding_zeros = 0;
	if ((flag->precision < 0) && (flag->precision * (-1) >= flag->width)
		&& !flag->left_shift)
		flag->zeros = flag->width - flag->write;
	if ((flag->option_of_precision == 1 || flag->option_of_precision == 2)
		&& flag->precision >= flag->write)
		flag->zeros = flag->precision - flag->write;
	else if (flag->option_of_precision == 2 && flag->precision == 0
		&& flag->zero_is_number == 1)
		flag->write = 0;
	if (!flag->left_shift && type != 'p')
		flag->width = flag->width - flag->write - flag->zeros;
	if (!flag->left_shift && type == 'p')
		flag->width = flag->width - flag->write - flag->zeros - 2;
	conversion_helper1(flag, len);
}

int	write_help_uint(int len)
{
	write(1, " ", 1);
	len++;
	return (len);
}

int	ft_print_unsint1(unsigned int n, int len, t_flag flag)
{
	if (flag.option_of_precision == 2 && flag.precision == 0 && n == 0)
	{
		if (flag.width != 0)
		{
			len = write_help_uint(len - 1);
			flag.width--;
		}
		else
		{
			write(1, NULL, 1);
			return (flag.fl);
		}
	}
	else
		ft_putnbr(&flag, n);
	if (flag.left_shift)
	{
		while (flag.width-- > 0)
			len = write_help_uint(len);
	}
	return (len);
}

int	ft_print_unsint(va_list list, t_flag flag)
{
	unsigned int	n;
	int				len;

	len = 0;
	n = va_arg(list, unsigned int);
	if (n == 0)
		flag.zero_is_number = 1;
	else
		flag.zero_is_number = 0;
	flag.write = ft_putnbr_len(&flag, n);
	len += flag.write;
	len = ft_print_unsint_help(n, &flag, len);
	conversion_helper0(&flag, 'u', &len);
	while (flag.zeros-- > 0)
	{
		write(1, "0", 1);
		len++;
		flag.width--;
	}
	len = ft_print_unsint1(n, len, flag);
	return (len);
}
