/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaloei <tchaloei@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:47:43 by tchaloei          #+#    #+#             */
/*   Updated: 2024/03/07 17:09:53 by tchaloei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}

int	print_str(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		count += print_str("(null)");
		return (count);
	}
	while (*s)
	{
		print_char((char)*s);
		++count;
		++s;
	}
	return (count);
}

int	print_num(long n, int base, int form)
{
	int		count;
	char	*hexa;
	char	*hex;

	count = 0;
	hexa = "0123456789abcdef";
	hex = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_num(-n, base, form) + 1);
	}
	else if (n < base)
	{
		if (form == 0)
			return (print_char(hexa[n]));
		else
			return (print_char(hex[n]));
	}
	else
	{
		count = print_num(n / base, base, form);
		return (count + print_num(n % base, base, form));
	}
	return (count);
}

int	print_address(void *p)
{
	int	count;

	count = 0;
	if (p == 0)
		return (print_str("(nil)"));
	count += print_str("0x");
	count += print_num((unsigned long)p, 16, 0);
	return (count);
}
