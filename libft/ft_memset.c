/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:25:21 by phan              #+#    #+#             */
/*   Updated: 2023/03/18 20:15:32 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*_b;

	_b = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		_b[i] = (unsigned char)c;
		i++;
	}
	return ((void *)_b);
}
