/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:02:33 by sdavos            #+#    #+#             */
/*   Updated: 2021/12/14 16:02:36 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string1(char *str, int i, t_flag *flag)
{
	if (flag->option_of_precision == 0)
	{
		while (str[i] != '\0')
		{
			write(1, &str[i++], 1);
			flag->width--;
		}
	}
	else
	{
		if (flag->precision < 0)
		{
			while (str[i] != '\0')
			{
				write(1, &str[i++], 1);
				flag->width--;
			}
		}
		while (str[i] != '\0' && flag->precision-- > 0)
		{
			write(1, &str[i++], 1);
			flag->width--;
		}
	}
	return (i);
}

int	ft_pr_str(int ret_len, t_flag *flag)
{
	while (flag->width > 0)
	{
		if (flag->padding_zeros == 1)
		{
			write(1, "0", 1);
			ret_len++;
			flag->width--;
		}
		else
		{
			write(1, " ", 1);
			ret_len++;
			flag->width--;
		}
	}
	return (ret_len);
}

int	print_str(int i, char *str, t_flag *flag)
{
	flag->fl = flag->width;
	i += ft_print_string1(str, i, flag);
	return (i);
}

char	*func_str(va_list list)
{
	char	*str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	return (str);
}

int	ft_print_string(va_list list, t_flag flag)
{
	int		len;
	int		ret_len;
	char	*str;
	int		i;

	str = func_str(list);
	len = ft_strlen(str);
	ret_len = len;
	if (flag.option_of_precision == 2 && flag.precision == 0 && !flag.width)
		return (0);
	str = ft_strdup(str);
	i = 0;
	if (flag.left_shift == 1)
	{
		print_str(i, str, &flag);
		ret_len = ft_pr_str(ret_len, &flag);
		free(str);
		if (flag.width > flag.precision && len > flag.precision)
			return (flag.fl);
		return (ret_len);
	}
	ret_len = ft_print_strint2(str, ret_len, len, &flag);
	ret_len = ft_print_strint3(str, ret_len, i, &flag);
	free(str);
	return (ret_len);
}
