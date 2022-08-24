/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:03:02 by sdavos            #+#    #+#             */
/*   Updated: 2021/12/14 16:03:05 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_write(t_flag	*flag, char type, unsigned int n)
{
	if (flag->type == 'x')
		type = 'x';
	else
		type = 'X';
	if (n == 0)
		flag->zero_is_number = 1;
	else
		flag->zero_is_number = 0;
	return (type);
}

void	print_x_help2(t_flag *flag, int *len, unsigned int n, char type)
{
	while (flag->zeros-- > 0)
	{
		write(1, "0", 1);
		(*len)++;
		flag->width--;
	}
	if (flag->option_of_precision == 2 && flag->precision == 0 && n == 0)
		print_x_help(flag, len);
	else
		ft_puthexa(flag, n, &type, len);
}

int	ft_print_unsint_help(unsigned int n, t_flag *flag, int len)
{
	if (flag->precision == 0 && n == 0
		&& flag->option_of_precision && flag->padding_zeros)
	{
		len = 0;
		flag->write = flag->width;
		flag->fl = flag->write;
	}
	return (len);
}

int	ft_print_x(va_list ap, t_flag flag)
{
	unsigned int	n;
	int				len;
	char			type;

	len = 0;
	type = '\0';
	n = va_arg(ap, unsigned int);
	type = ft_write(&flag, type, n);
	flag.write = ft_puthexa_len(&flag, n);
	len += flag.write;
	conversion_helper0(&flag, type, &len);
	print_x_help2(&flag, &len, n, type);
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
