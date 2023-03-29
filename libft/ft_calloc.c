/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:02:33 by phan              #+#    #+#             */
/*   Updated: 2023/03/29 20:43:43 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;
	size_t	i;

	temp = (char *)malloc(count * size);
	if (!temp)
		return (0);
	i = 0;
	while (i < count * size)
		temp[i++] = 0;
	return ((void *)temp);
}
