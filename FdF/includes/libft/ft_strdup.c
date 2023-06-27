/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:46:43 by phan              #+#    #+#             */
/*   Updated: 2023/04/01 14:55:20 by phan             ###   ########.fr       */
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
		return (0);
	while (*s1)
		*temp++ = *s1++;
	*temp = '\0';
	return (temp - s_len);
}
