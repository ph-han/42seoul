/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:06:04 by phan              #+#    #+#             */
/*   Updated: 2023/03/19 14:57:46 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*_dst;
	unsigned char	*_src;
	unsigned int	i;

	_dst = (unsigned char *)dst;
	_src = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		_dst[i] = _src[i];
		i++;
	}
	return ((void *)_dst);
}