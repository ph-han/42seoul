/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:36:03 by phan              #+#    #+#             */
/*   Updated: 2023/01/26 17:50:44 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);

void	address_to_hex_and_print(void *address)
{
	unsigned char	addr[16];
	int				addr_idx;
	int				temp;
	long long		t_address;

	addr_idx = 15;
	t_address = (long long)address;
	while (t_address != 0)
	{
		temp = t_address % 16;
		if (temp < 10)
			addr[addr_idx] = temp + 48;
		else
			addr[addr_idx] = temp + 87;
		t_address /= 16;
		addr_idx--;
	}
	while (addr_idx >= 0)
	{
		addr[addr_idx] = '0';
		addr_idx--;
	}
	write(1, addr, 16);
	write(1, ": ", 2);
}

void	data_to_hex_and_print(void *addr, unsigned int size)
{
	char			hex_arr[40];
	char			*temp_addr;
	unsigned char	temp;
	unsigned int	i;
	unsigned int	j;

	temp_addr = (char *)addr;
	j = 0;
	i = 0;
	while (j < size && i < 39)
	{
		temp = *(temp_addr + j);
		hex_arr[i] = "0123456789abcdef"[temp / 16];
		hex_arr[i + 1] = "0123456789abcdef"[temp % 16];
		if (j % 2 == 1)
		{
			hex_arr[i + 2] = ' ';
			i += 1;
		}
		i += 2;
		j++;
	}
	while (i < 40)
		hex_arr[i++] = ' ';
	write(1, hex_arr, 40);
}

void	data_print(void	*addr, unsigned int size)
{
	int		j;
	char	*temp_addr;

	j = 0;
	temp_addr = (char *)addr;
	while (j < size)
	{
		if (*(temp_addr + j) == '\t' || \
				*(temp_addr + j) == '\n' || *(temp_addr + j) == '\0')
			write(1, ".", 1);
		else
			write(1, (temp_addr + j), 1);
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;
	int	j;
	int	mod;

	if (size == 0)
		return (addr);
	i = 0;
	j = 0;
	mod = size % 16;
	while (i < size - mod)
	{	
		if (i % 16 == 0)
		{
			address_to_hex_and_print((addr + i));
			data_to_hex_and_print((addr + i), 16);
			data_print((addr + i), 16);
			write(1, "\n", 1);
		}
		i++;
	}
	if (mod != 0)
	{
		address_to_hex_and_print((addr + i));
		data_to_hex_and_print((addr + i), mod);
		data_print((addr + i), mod);
		write(1, "\n", 1);
	}
	return (addr);
}
