/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:21:30 by aalami            #+#    #+#             */
/*   Updated: 2023/01/08 14:59:43 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(char c, va_list arg)
{
	int	chr_nbr;

	chr_nbr = 0;
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int), &chr_nbr));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'p')
		return (ft_putstr("0x") + covert_hex(va_arg(arg, unsigned long), 0));
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			return (covert_hex(va_arg(arg, unsigned int ), 0));
		return (covert_hex(va_arg(arg, unsigned int ), 1));
	}
	else
		return (ft_putnbr(va_arg(arg, unsigned int), &chr_nbr));
}

int	get_specifier(char c, va_list arg)
{
	char	*specifier;
	int		chr;

	chr = 0;
	specifier = "cspdiuxX";
	if (!ft_strchr_p(specifier, c))
		chr += ft_putchar(c);
	else
		chr += ft_format(c, arg);
	return (chr);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		chr;

	chr = 0;
	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i] != '\0')
			chr += ft_putchar(format[i++]);
		if (format[i] == '%' && format[i + 1] == '%')
		{
			chr += ft_putchar(format[i]);
			i += 2;
			continue ;
		}
		if (!format[i] || !format[i + 1])
			break ;
		i++;
		chr += get_specifier(format[i], arg);
		i++;
	}
	va_end (arg);
	return (chr);
}
