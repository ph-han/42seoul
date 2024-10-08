/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:53 by phan              #+#    #+#             */
/*   Updated: 2023/01/25 17:24:53 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	i = 0;
	dest_len = 0;
	src_len = 0;
	while (*dest)
	{
		dest_len++;
		dest++;
	}
	while (*(src + src_len))
		src_len++;
	if (dest_len >= size)
		return (src_len + size);
	while (*(src + i) && dest_len + i + 1 < size)
	{
		*dest = *(src + i);
		i++;
		dest++;
	}
	*dest = '\0';
	return (dest_len + src_len);
}
