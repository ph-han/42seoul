/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunminjo <hyunminjo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:49:54 by phan              #+#    #+#             */
/*   Updated: 2023/08/08 13:19:48 by hyunminjo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_instr(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	rlen;
	int		idx;

	while (*s1 && is_instr(*s1, set))
		s1++;
	rlen = ft_strlen(s1);
	idx = rlen - 1;
	while (idx >= 0 && is_instr(s1[idx], set))
		idx--;
	rlen = idx + 1;
	result = (char *)malloc(sizeof(char) * (rlen + 1));
	if (!result)
		exit(1);
	ft_memmove(result, s1, rlen);
	result[rlen] = '\0';
	return (result);
}
