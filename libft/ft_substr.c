/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:16:25 by phan              #+#    #+#             */
/*   Updated: 2023/03/29 21:03:00 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*temp;
	unsigned int	i;
	unsigned int	temp_len;
	
	if (!s)
		return (0);
	temp_len = ft_strlen(s);
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
