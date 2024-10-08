/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:12:08 by phan              #+#    #+#             */
/*   Updated: 2023/02/02 13:09:18 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int	*range;
	int	idx;
	int	size;

	if (min >= max)
		return (0);
	size = max - min;
	range = (int *)malloc(sizeof(int) * size);
	if (range==0)
		return (0);
	idx = 0;
	while (idx < size)
	{
		range[idx] = (min + idx);
		idx++;
	}
	return (range);
}
