/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:17:20 by phan              #+#    #+#             */
/*   Updated: 2023/02/02 13:47:00 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	int	idx;
	int	size;

	if (min >= max)
		return (0);
	size = max - min;
	*range = (int *)malloc(sizeof(int) * size);
	if (range == 0)
		return (-1);
	idx = 0;
	while (idx < size)
	{
		range[0][idx] = min + idx;
		idx++;
	}
	return (size);
}
