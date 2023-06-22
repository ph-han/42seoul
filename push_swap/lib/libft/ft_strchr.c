/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:55:03 by phan              #+#    #+#             */
/*   Updated: 2023/04/01 14:54:57 by phan             ###   ########.fr       */
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
