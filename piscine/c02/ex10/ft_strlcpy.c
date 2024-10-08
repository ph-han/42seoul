/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:09:59 by phan              #+#    #+#             */
/*   Updated: 2023/01/25 17:40:59 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	count;

	count = 0;
	while (*src != '\0')
	{
		count++;
		src++;
	}
	src -= count;
	while (size > 1 && *src != '\0')
	{
		size--;
		*dest = *src;
		dest++;
		src++;
	}
	if (size != 0)
		*dest = '\0';
	return (count);
}
