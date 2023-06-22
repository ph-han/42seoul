/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:58:51 by phan              #+#    #+#             */
/*   Updated: 2023/04/09 16:03:57 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str_or_char(char type, va_list *ap)
{
	char	*str;
	char	c;
	int		bytes;

	if (type == 'c')
	{
		c = (char)va_arg(*ap, int);
		return (write(1, &c, 1));
	}
	str = va_arg(*ap, char *);
	if (str == 0)
		return (write(1, "(null)", 6));
	bytes = 0;
	while (*str)
	{
		if (write(1, str++, 1) == -1)
			return (-1);
		bytes++;
	}
	return (bytes);
}

static int	print_nbr(long long nbr, char *base_arr, int base)
{
	int		ridx;
	int		bytes;
	char	result[15];

	if (nbr == 0)
		return (write(1, "0", 1));
	bytes = 0;
	if (nbr < 0 && bytes++ == 0)
		if (write(1, "-", 1) == -1)
			return (-1);
	nbr = nbr * ((nbr >= 0) + ((nbr < 0) * -1));
	ridx = 0;
	while (nbr)
	{
		result[ridx++] = base_arr[nbr % base];
		nbr /= base;
	}
	while (--ridx >= 0)
	{
		if (write(1, &result[ridx], 1) == -1)
			return (-1);
		bytes++;
	}
	return (bytes);
}

static int	print_ptr(void *ptr, char *base_arr)
{
	int					bytes;
	int					ridx;
	char				result[16];
	unsigned long long	v_ptr;

	v_ptr = (unsigned long long)ptr;
	if (v_ptr == 0)
		return (write(1, "0x0", 3));
	if (write(1, "0x", 2) == -1)
		return (-1);
	bytes = 2;
	ridx = 0;
	while (v_ptr)
	{
		result[ridx++] = base_arr[v_ptr % 16];
		v_ptr /= 16;
	}
	while (--ridx >= 0)
	{
		if (write(1, &result[ridx], 1) == -1)
			return (-1);
		bytes++;
	}
	return (bytes);
}

static int	print_by_format(char specifier, va_list *ap)
{
	int	bytes;

	bytes = 0;
	if (specifier == 'c' || specifier == 's')
		bytes = print_str_or_char(specifier, ap);
	else if (specifier == 'p')
		bytes = print_ptr(va_arg(*ap, void *), "0123456789abcdef");
	else if (specifier == 'd' || specifier == 'i')
		bytes = print_nbr(va_arg(*ap, int), "0123456789", 10);
	else if (specifier == 'u')
		bytes = print_nbr(va_arg(*ap, unsigned int), "0123456789", 10);
	else if (specifier == 'x')
		bytes = print_nbr(va_arg(*ap, unsigned int), "0123456789abcdef", 16);
	else if (specifier == 'X')
		bytes = print_nbr(va_arg(*ap, unsigned int), "0123456789ABCDEF", 16);
	else if (specifier == '%')
		bytes = write(1, "%", 1);
	return (bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		tot_bytes;
	int		byte;

	va_start(ap, format);
	tot_bytes = 0;
	while (*format)
	{
		if (*format == '%')
			byte = print_by_format(*(++format), &ap);
		else
			byte = write(1, format, 1);
		if (byte == -1)
		{
			va_end(ap);
			return (-1);
		}
		tot_bytes += byte;
		format++;
	}
	va_end(ap);
	return (tot_bytes);
}
