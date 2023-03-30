/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:31:06 by phan              #+#    #+#             */
/*   Updated: 2023/03/30 16:46:41 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (s[len] && len < maxlen)
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	p_idx;
	unsigned int	s_idx;

	dst_len = ft_strnlen(dst, dstsize);
	src_len = ft_strlen(src);
	s_idx = 0;
	p_idx = dst_len;
	if (dst_len == dstsize)
		return (src_len + dstsize);
	while (src[s_idx] && (s_idx + dst_len + 1) < dstsize)
		dst[p_idx++] = src[s_idx++];
	dst[p_idx] = '\0';
	return (src_len + dst_len);
}
