/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:13:59 by phan              #+#    #+#             */
/*   Updated: 2023/03/19 14:53:58 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*_dst;
	unsigned char	*_src;

	_dst = (unsigned char *)dst;
	_src = (unsigned char *)src;
	if (!_dst && !_src)
		return (0);
	if (len < 1)
		return (dst);
	if (_dst > _src)
	{
		_dst += len - 1;
		_src += len - 1;
		while (len--)
			*_dst-- = *_src--;
	}
	else
	{
		while (len--)
			*_dst++ = *_src++;
	}
	return (dst);
}
