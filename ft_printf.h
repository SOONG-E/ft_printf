/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:05:48 by yujelee           #+#    #+#             */
/*   Updated: 2022/07/24 20:05:54 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putunsignednbr(unsigned int num);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *s);

#endif