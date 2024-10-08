/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunminjo <hyunminjo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:46:43 by phan              #+#    #+#             */
/*   Updated: 2023/08/08 13:19:34 by hyunminjo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	s_len;

	s_len = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * s_len + 1);
	if (!temp)
		exit(1);
	while (*s1)
		*temp++ = *s1++;
	*temp = '\0';
	return (temp - s_len);
}
