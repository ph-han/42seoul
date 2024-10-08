/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:01:31 by phan              #+#    #+#             */
/*   Updated: 2023/01/24 17:55:58 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str);
void	ft_print_char_to_hex(unsigned char c);

void	ft_print_char_to_hex(unsigned char c)
{
	unsigned char	hex[2];
	unsigned char	mod;
	int				i;

	write(1, "\\", 1);
	i = 1;
	while (i >= 0)
	{
		mod = c % 16;
		if (mod < 10)
			hex[i] = mod + 48;
		else
			hex[i] = mod + 87;
		c /= 16;
		i--;
	}
	write(1, hex, 2);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < ' ' || *str > '~')
		{
			ft_print_char_to_hex((unsigned char)*str);
		}
		else
			write(1, str, 1);
		str++;
	}
}
