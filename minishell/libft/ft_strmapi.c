/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunminjo <hyunminjo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:32:19 by phan              #+#    #+#             */
/*   Updated: 2023/08/08 13:19:43 by hyunminjo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	idx;
	size_t	s_len;

	if (!s || !f)
		return (0);
	s_len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!result)
		exit(1);
	idx = 0;
	while (s[idx])
	{
		result[idx] = f(idx, s[idx]);
		idx++;
	}
	result[s_len] = '\0';
	return (result);
}
