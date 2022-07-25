/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:50:41 by yujelee           #+#    #+#             */
/*   Updated: 2022/07/25 17:01:47 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_hex(unsigned long long num, char *hex, int count)
{
	if (num >= 16)
	{
		count = printf_hex(num / 16, hex, ++count);
		num = num % 16;
	}
	ft_putchar(hex[num]);
	return (count);
}

int	pprocessor(void *addr, char *hex)
{
	ft_putstr("0x");
	return (printf_hex((long long)addr, hex, 1) + 2);
}

int	xprocessor(unsigned int num, char form)
{
	if (form == 'x')
		return (printf_hex(num, "0123456789abcdef", 1));
	else
		return (printf_hex(num, "0123456789ABCDEF", 1));
}

int	parsing(char form, va_list av)
{
	int	count;

	if (form == 'c')
		count = ft_putchar(va_arg(av, int));
	else if (form == 's')
		count = ft_putstr(va_arg(av, char *));
	else if (form == 'p')
		count = pprocessor(va_arg(av, void *), "0123456789abcdef");
	else if (form == 'd' || form == 'i')
		count = ft_putnbr(va_arg(av, int));
	else if (form == 'u')
		count = ft_putunsignednbr(va_arg(av, int));
	else if (form == 'x' || form == 'X')
		count = xprocessor(va_arg(av, unsigned int), form);
	else if (form == '%')
		count = ft_putchar('%');
	else
		count = -1;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	av;
	int		idx;
	int		count;
	int		temp;

	idx = -1;
	va_start(av, str);
	count = 0;
	while (str[++idx])
	{
		if (str[idx] == '%')
		{
			temp = parsing(str[++idx], av);
			if (temp < 0)
				return (0);
			count += temp;
		}
		else
		{
			ft_putchar(str[idx]);
			++count;
		}
	}
	va_end(av);
	return (count);
}
