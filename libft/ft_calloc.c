/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:02:33 by phan              #+#    #+#             */
/*   Updated: 2023/03/19 15:45:38 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;
	int		len;

	temp = (char *)malloc(count * size);
	if (!temp)
		return (0);
	len = count * size;
	temp += len;
	while (len--)
		*(--temp) = 0;
	return ((void *)temp);
}
