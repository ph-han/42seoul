/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:21:42 by phan              #+#    #+#             */
/*   Updated: 2023/03/27 13:44:07 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *string, int c)
{
	int		i;
	char	_c;

	i = 0;
	_c = (char)c;
	while (*(string + i))
		i++;
	while (i >= 0)
	{
		if (*(string + i) == _c)
			return ((char *)(string + i));
		i--;
	}
	return (0);
}
