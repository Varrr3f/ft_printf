/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:02:17 by sdavos            #+#    #+#             */
/*   Updated: 2021/12/14 16:02:20 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pr_pre(char *str, int len, t_flag *flag)
{
	if (flag->left_shift)
	{
		write(1, &str[0], 1);
		len++;
		while (--flag->width > 0)
		{
			write(1, " ", 1);
			len++;
		}
	}
	return (len);
}

int	ft_print_precent1(int len, t_flag *flag)
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
			flag->width--;
		}
	}
	return (len);
}

int	ft_print_precent(t_flag flag)
{
	char	*str;
	int		len;

	len = 0;
	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (0);
	str[0] = flag.type;
	if (flag.left_shift)
		len = ft_pr_pre(str, len, &flag);
	else
	{
		len = ft_print_precent1(len, &flag);
		write(1, &str[0], 1);
		len++;
	}
	free(str);
	return (len);
}
