/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:01:30 by sdavos            #+#    #+#             */
/*   Updated: 2021/12/14 16:01:40 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char1(char *str, int len, t_flag *flag)
{
	write(1, &str[0], 1);
	flag->width--;
	while (flag->width > 0)
	{
		write(1, " ", 1);
		len++;
		flag->width--;
	}
	return (len);
}

int	ft_print_char2(char *str, int len, t_flag *flag)
{
	while (flag->width > 1)
	{
		if (flag->padding_zeros)
		{
			write(1, "0", 1);
			len++;
			flag->width--;
		}
		else
		{
			write(1, " ", 1);
			len++;
			flag->width--;
		}
	}
	write(1, &str[0], 1);
	return (len);
}

int	ft_print_char(va_list list, t_flag flag)
{
	char		*str;
	int			len;

	len = 1;
	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (0);
	str[0] = (char)va_arg(list, int);
	if (flag.left_shift)
		len = ft_print_char1(str, len, &flag);
	else
		len = ft_print_char2(str, len, &flag);
	free(str);
	return (len);
}
