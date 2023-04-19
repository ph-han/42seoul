/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:29:19 by phan              #+#    #+#             */
/*   Updated: 2023/04/18 20:23:51 by phan             ###   ########.fr       */
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

char	*gnl_str_join_dup(char *s1, char *s2)
{
	char	*temp;
	int		s1_len;
	int		s2_len;

	if (!s1)
		s1 = "";
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	temp = (char *)malloc(s1_len + s2_len + 1);
	if (!temp)
		return (0);
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (temp - s1_len - s2_len);
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
		s = "";
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
	int				j;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (dst == src)
		return (dst);
	j = 0;
	while (j <= n)
	{
		p_dst[j] = p_src[j];
		j++;
	}
	return (dst);
}
