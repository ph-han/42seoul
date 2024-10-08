/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:56:32 by phan              #+#    #+#             */
/*   Updated: 2023/01/19 19:20:48 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (*(src + idx) != '\0')
	{
		*(dest + idx) = *(src + idx);
		idx++;
	}
	*(dest + idx) = '\0';
	return (dest);
}
