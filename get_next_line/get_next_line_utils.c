/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:29:19 by phan              #+#    #+#             */
/*   Updated: 2023/04/15 19:11:46 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(char *buff)
{
	int	idx;

	idx = 0;
	while (*(buff + idx))
		if (*(buff + idx++) == '\n')
			return (idx - 1);
	return (-1);
}

int	gnl_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*gnl_substr(char *s, int start, int len)
{
	char	*temp;
	int		i;
	int		temp_len;

	if (!s)
		return (0);
	temp_len = gnl_strlen(s);
	if (temp_len < start)
		len = 0;
	temp_len -= start;
	if (temp_len >= len)
		temp_len = len;
	temp = (char *)malloc(sizeof(char) * (temp_len + 1));
	if (!temp)
		return (0);
	i = start;
	while (i < start + len && *(s + i))
	{
		*(temp + (i - start)) = *(s + i);
		i++;
	}
	*(temp + (i - start)) = '\0';
	return (temp);
}

void	*gnl_memcpy(void *dst, const void *src, int n)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;
	int				i;
	int				j;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	while (p_dst[i])
		i++;
	j = 0;
	while (j <= n)
		p_dst[i++] = p_src[j++];
	return (dst);
}
