/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:16:25 by phan              #+#    #+#             */
/*   Updated: 2023/03/19 20:52:01 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*temp;
	unsigned int	i;
	
	if (!s || ft_strlen(s) < start)
		return (0);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	i = start;
	while (*(s + i) && i < len + start)
	{
		*(temp + (i - start)) = *(s + i);
		i++;
	}
	*(temp + i) = '\0';
	return (temp);
}
