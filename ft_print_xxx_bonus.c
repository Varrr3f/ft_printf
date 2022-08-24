/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xxx_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:03:02 by sdavos            #+#    #+#             */
/*   Updated: 2021/12/14 16:03:05 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_len(t_flag *flag, unsigned long x)
{
	if (x >= 16)
	{
		flag->length_n++;
		ft_puthexa_len(flag, x / 16);
	}
	return (flag->length_n + 1);
}

void	hexa_p_help(int *len, t_flag *flag)
{
	write(1, "0", 1);
	(*len)++;
	flag->width--;
	write(1, "x", 1);
	(*len)++;
	flag->width--;
	flag->one_argument = 1;
}

int	*ft_puthexa(t_flag *flag, unsigned long x, char *type, int *len)
{
	char	*word_1;
	char	*word_2;

	word_1 = "0123456789abcdef";
	word_2 = "0123456789ABCDEF";
	if (x >= 16)
	{
		ft_puthexa(flag, x / 16, type, len);
	}
	if (*type == 'p' && flag->one_argument == 0)
		hexa_p_help(len, flag);
	if (*type == 'x' || *type == 'p')
	{
		write(1, &(word_1[x & 15]), 1);
		flag->width--;
	}
	else
	{
		write(1, &(word_2[x & 15]), 1);
		flag->width--;
	}
	return (len);
}

void	print_x_help(t_flag *flag, int *len)
{
	if (flag->width > 0)
	{
		write(1, " ", 1);
		(*len)++;
		flag->width--;
	}
	else
	{
		write(1, NULL, 1);
	}
	(*len)--;
}
