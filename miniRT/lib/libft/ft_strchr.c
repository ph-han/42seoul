/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:55:03 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 13:14:24 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *string, int c)
{
	char	v_c;

	v_c = (char)c;
	while (*string != v_c)
	{
		if (*string == '\0')
			return (0);
		string++;
	}
	return ((char *)string);
}