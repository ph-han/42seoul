/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:58:51 by phan              #+#    #+#             */
/*   Updated: 2023/04/08 19:28:10 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str_or_char()
{

}

static int	print_base()
{

}

static int	print_ptr()
{

}

static int	print_by_format(char specifier, va_list argv, size_t v_idx)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		print_str_or_char();
	else if (specifier == 's')
		print_str_or_char();
	else if (specifier == 'p')
		print_ptr();
	else if (specifier == 'd')
		print_base();
	else if (specifier == 'i')
		print_base();
	else if (specifier == 'u')
		print_base();
	else if (specifier == 'x')
		print_base();
	else if (specifier == 'X')
		print_base();
	else if (specifier == '%')
		ft_putchar_fd('%', 0);
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	argv;
	int		len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
			len += ft_print_by_format(*(++format));
		else
		{
			len += 1;
			ft_putchar_fd(*format, 0);
		}
		format++;
	}
}
