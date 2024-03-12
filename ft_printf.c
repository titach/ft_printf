/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaloei <tchaloei@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:44:45 by tchaloei          #+#    #+#             */
/*   Updated: 2024/03/07 16:57:50 by tchaloei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char Specifier, va_list ap)
{
	int	count;

	count = 0;
	if (Specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (Specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (Specifier == 'd' || Specifier == 'i')
		count += print_num((long)(va_arg(ap, int)), 10, 0);
	else if (Specifier == 'u')
		count += print_num((long)(va_arg(ap, unsigned int)), 10, 0);
	else if (Specifier == 'x')
		count += print_num((long)(va_arg(ap, unsigned int)), 16, 0);
	else if (Specifier == 'X')
		count += print_num((long)(va_arg(ap, unsigned int)), 16, 1);
	else if (Specifier == 'p')
		count += print_address(va_arg(ap, void *));
	else
	{
		count += print_char('%');
		count += write(1, &Specifier, 1);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (*format == '%')
				count += write (1, format, 1);
			else
				count += print_format(*format, ap);
		}
		else
			count += write (1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
