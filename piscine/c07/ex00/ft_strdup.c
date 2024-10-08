/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:08:42 by phan              #+#    #+#             */
/*   Updated: 2023/01/31 12:24:09 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src);

char	*ft_strdup(char *src)
{
	char	*dup;
	int		size;
	int		i;

	size = 0;
	while (*(src + size))
		size++;
	dup = (char *)malloc(size + 1);
	dup[0] = '\0';
	i = 0;
	while (*src)
	{
		*(dup + i) = *src;
		src++;
		i++;
	}
	*(dup + i) = '\0';
	return (dup);
}
