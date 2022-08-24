/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:00:23 by sdavos            #+#    #+#             */
/*   Updated: 2021/12/14 16:00:29 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_addr2(unsigned long int n, int len, char type, t_flag *flag)
{
	if (flag->option_of_precision == 2 && flag->precision == 0 && n == 0)
	{
		if (((void *)n == (void *)0) && (flag->option_of_precision != 0))
		{
			write(1, "0", 1);
			len++;
			flag->width--;
			write(1, "x", 1);
			len++;
			flag->width--;
		}
		else
		{
			write(1, NULL, 1);
			len++;
			flag->width--;
		}
	}
	else
		ft_puthexa(flag, n, &type, &len);
	return (len);
}

int	ft_print_addr1(unsigned long int n, int len, t_flag *flag)
{
	if (n == 0)
		flag->zero_is_number = 1;
	else
		flag->zero_is_number = 0;
	flag->write = ft_puthexa_len(flag, n);
	len += flag->write;
	conversion_helper0(flag, 'p', &len);
	while (flag->zeros-- > 0)
	{
		write(1, "0", 1);
		len++;
		flag->width--;
	}
	return (len);
}

int	ft_print_address(va_list list, t_flag flag)
{
	unsigned long int	n;
	int					len;
	char				type;

	type = 'p';
	len = 0;
	n = (unsigned long int)va_arg(list, void *);
	len = ft_print_addr1(n, len, &flag);
	len = ft_print_addr2(n, len, type, &flag);
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
