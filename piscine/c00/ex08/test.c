/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:05:20 by phan              #+#    #+#             */
/*   Updated: 2023/01/22 11:32:03 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	recursive(char nb[], int idx, int n, int curr_num);
void	ft_print(char nb[], int n);

void	recursive(char nb[], int idx, int n, int curr_num)
{
	if (idx == n)
	{
		ft_print(nb, n);
		return ;
	}

	while (curr_num <= 9)
	{
		nb[idx] = curr_num + '0';
		recursive(nb, idx + 1, n, curr_num + 1);
		curr_num++;
	}
}

void    ft_print_combn(int n)
{
    char nb[10];
	
	recursive(nb, 0, n, 0);
}

void	ft_print(char nb[], int n)
{

	write(1, nb, n);
	if (10 - n + '0' != nb[0])
		write(1, ", ", 2);
}
