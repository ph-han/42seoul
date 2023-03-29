/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:32:19 by phan              #+#    #+#             */
/*   Updated: 2023/03/29 21:02:11 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	idx;
	unsigned int	s_len;
	
	if (!s || !f)
		return (0);
	s_len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!result)
		return (0);
	idx = 0;
	while (s[idx])
	{
		result[idx] = f(idx, s[idx]);
		idx++;
	}
	result[s_len] = '\0';
	return (result);
}
