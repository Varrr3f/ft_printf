/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_help_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:02:33 by sdavos            #+#    #+#             */
/*   Updated: 2021/12/14 16:02:36 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!str)
		return (NULL);
	else
	{
		i = 0;
		while (src[i])
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
}

int	ft_print_strint3(char *str, int ret_len, int i, t_flag *flag)
{
	while (flag->width > flag->write)
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
	while (flag->write-- > 0)
	{
		write(1, &str[i], 1);
		i++;
		flag->width--;
	}
	return (ret_len);
}

int	ft_print_strint2(char *str, int ret_len, int len, t_flag *flag)
{
	if (flag->precision == 0)
	{
		flag->write = ft_strlen(str);
		if (flag->option_of_precision == 2)
		{
			flag->write = 0;
			ret_len = 0;
		}
	}
	else if (flag->precision < 0)
		flag->write = len;
	else
	{
		if (len < flag->precision)
		{
			flag->write = len;
			ret_len = flag->write;
		}
		else
		{
			flag->write = flag->precision;
			ret_len = flag->write;
		}
	}
	return (ret_len);
}
