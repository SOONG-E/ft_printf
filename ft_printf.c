/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:50:41 by yujelee           #+#    #+#             */
/*   Updated: 2022/07/24 19:16:32 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	printf_hex(long long num, char *hex, int count)
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
	int count;

	count = 0;
	if (form == 'c')
		count += ft_putchar(va_arg(av, int));
	else if (form == 's')
		count += ft_putstr(va_arg(av, char *));
	else if (form == 'p')
		count += pprocessor(va_arg(av, void *), "0123456789abcdef");
	else if (form == 'd' || form == 'i')
		count += ft_putnbr(va_arg(av, int));
	else if (form == 'u')
		count += ft_putunsignednbr(va_arg(av, int));
	else if (form == 'x' || form == 'X')
		count += xprocessor(va_arg(av, unsigned int), form);
	else if (form == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(char *str, ...)
{
	va_list	av;
	int		idx;
	int		count;

	idx = -1;
	va_start(av, str);
	count = 0;
	while (str[++idx])
	{
		if (str[idx] == '%')
			count += parsing(str[++idx], av);
		else if (!str[idx])
			break ;
		else
		{
			ft_putchar(str[idx]);
			++count;
		}
	}
	return (count);
}

/*
int main()
{

	char *e = "QWEQWEQWEQWEweqweqweqwe";
	//int a = -34234;
	//char d = '4';
	int b;
	int c;
	b = ft_printf("wqeqweqwe%swww  %sew\n", e, e);
	c = printf("wqeqweqwe%swww  %sew\n", e, e);
	printf("****%d %d\n", b, c);
}
*/