/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:01:11 by phan              #+#    #+#             */
/*   Updated: 2023/03/18 20:14:26 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*_s;

	i = 0;
	_s = (unsigned char *)s;
	while (i < n && _s[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (0);
	return ((void *)(_s + i));
}
