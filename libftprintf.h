/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:51:03 by yujelee           #+#    #+#             */
/*   Updated: 2022/07/24 19:16:22 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>

int	ft_printf(char *str, ...);
int	ft_putunsignednbr(unsigned int num);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *s);

#endif