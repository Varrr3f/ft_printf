/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:03:26 by sdavos            #+#    #+#             */
/*   Updated: 2021/12/14 16:03:31 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_flag
{
	int			minus;
	int			width;
	int			length_n;
	int			precision;
	int			type;
	int			option_of_precision;
	int			left_shift;
	int			padding_zeros;
	int			zero_is_number;
	int			zeros;
	int			write;
	int			one_argument;
}				t_flag;

int		ft_printf(const char *format, ...);
int		ft_parser(const char *format, size_t *i, va_list ap);
int		print_type(const char *str, size_t *i, va_list ap, t_flag flag);
int		type_is_0(int type, va_list ap, t_flag flag, int count);
int		type_is_1(int type, va_list ap, t_flag flag, int count);
int		type_is_2(int type, va_list ap, t_flag flag, int count);
t_flag	width_prec1(const char *format, size_t *i, va_list ap, t_flag flag);
t_flag	width_prec2(const char *format, size_t *i, va_list ap, t_flag flag);
t_flag	ft_parse_flag(const char *format, size_t *i, va_list ap, t_flag flag);
int		ft_print_char(va_list list, t_flag flag);
int		ft_print_char1(char *str, int len, t_flag *flag);
int		ft_print_char2(char *str, int len, t_flag *flag);
int		ft_type_check(char c);
int		ft_print_string(va_list list, t_flag flag);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
int		ft_print_integer(va_list list, t_flag flag);
int		ft_print_integer1(int len, t_flag *flag);
int		ft_print_integer2(int n, int len, t_flag *flag);
int		ft_print_integer3(int n, int len, t_flag *flag);
int		ft_print_integer4(int len, t_flag *flag);
int		ft_int_write_help(int len, t_flag *flag);
int		ft_pr_int_flags(int n, int len, t_flag *flag);
int		ft_putnbr_len(t_flag *flag, long n);
void	ft_putnbr(t_flag *flag, long n);
char	ft_symbol(int n);
int		ft_print_unsint(va_list list, t_flag flag);
int		ft_print_unsint1(unsigned int n, int len, t_flag flag);
int		ft_print_unsint_help(unsigned int n, t_flag *flag, int len);
void	conversion_helper0(t_flag *flag, char type, int *len);
void	conversion_helper1(t_flag *flag, int *len);
int		*ft_puthexa(t_flag *flag, unsigned long x, char *type, int *len);
void	hexa_p_help(int *len, t_flag *flag);
int		ft_puthexa_len(t_flag *flag, unsigned long x);
int		ft_print_x(va_list list, t_flag flag);
void	print_x_help(t_flag *flag, int *len);
void	print_x_help2(t_flag *flag, int *len, unsigned int n, char type);
char	ft_write(t_flag	*flag, char type, unsigned int n);
int		ft_print_address(va_list list, t_flag flag);
int		ft_print_addr1(unsigned long int n, int len, t_flag *flag);
int		ft_print_addr2(unsigned long int n, int len, char type, t_flag *flag);
int		ft_print_precent(t_flag flag);
int		ft_print_precent1(int len, t_flag *flag);
int		ft_pr_pre(char *str, int len, t_flag *flag);
int		write_help_uint(int len);
int		ft_print_string1(char *str, int i, t_flag *flag);
int		ft_print_strint2(char *str, int ret_len, int len, t_flag *flag);
int		ft_print_strint3(char *str, int ret_len, int i, t_flag *flag);
int		print_str(int i, char *str, t_flag *flag);
int		ft_pr_str(int ret_len, t_flag *flag);
char	*func_str(va_list list);

#endif
