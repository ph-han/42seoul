/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:29:19 by phan              #+#    #+#             */
/*   Updated: 2023/04/27 17:14:44 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	gnl_find(char *s, char c)
{
	int	idx;

	idx = 0;
	while (s[idx] && s[idx] != c)
		idx++;
	return (idx);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (0);
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

char	*gnl_clear(char *f_str1, char **back)
{
	free(f_str1);
	f_str1 = 0;
	*back = 0;
	return (0);
}
