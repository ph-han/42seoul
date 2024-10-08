/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:20:03 by phan              #+#    #+#             */
/*   Updated: 2023/01/25 17:23:59 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = 0;
	src_len = 0;
	while (*dest)
	{
		dest++;
		dest_len++;
	}
	while (*(src + src_len) && src_len < nb)
	{
		*dest = *(src + src_len);
		src_len++;
		dest++;
	}
	*dest = '\0';
	return (dest - dest_len - src_len);
}
