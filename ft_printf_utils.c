/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:59:39 by yujelee           #+#    #+#             */
/*   Updated: 2022/07/24 19:16:46 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	ft_put_rec(long c, int count)
{
	if (c >= 10)
	{
		count = ft_put_rec(c / 10, ++count);
		c = c % 10;
	}
	ft_putchar(c + '0');
	return (count);
}

int	ft_putnbr(int n)
{
	long	num;
	int		count;

	num = n;
	count = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		num = num * (-1);
		++count;
	}
	return (ft_put_rec(num, count));
}

int	ft_putunsignednbr(unsigned int num)
{
	return (ft_put_rec(num, 1));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	idx;

	idx = 0;
	if (s)
	{
		while (s[idx])
			write(1, &s[idx++], 1);
	}
	return (idx);
}
