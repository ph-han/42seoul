/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:23:20 by phan              #+#    #+#             */
/*   Updated: 2023/01/15 14:47:48 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
int		ft_atoi(char *str);

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc != 3)
		write(1, "You can only enter two numbers.\n", 32);
	else
	{
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[2]);
		if (x <= 0 || y <= 0)
			write(1, "Invalid Number\n", 15);
		else
			rush(x, y);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	if (*str == '+')
		str++;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}
