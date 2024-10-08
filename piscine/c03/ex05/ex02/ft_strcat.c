/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:52:16 by phan              #+#    #+#             */
/*   Updated: 2023/01/24 16:31:11 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src);

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	src_len;

	dest_len = 0;
	src_len = 0;
	while (*dest)
	{
		dest++;
		dest_len++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
		src_len++;
	}
	*dest = '\0';
	return (dest - dest_len - src_len);
}
