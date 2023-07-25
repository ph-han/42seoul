/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:21:42 by phan              #+#    #+#             */
/*   Updated: 2023/04/01 18:49:46 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *string, int c)
{
	int		i;
	char	v_c;

	i = 0;
	v_c = (char)c;
	while (*(string + i))
		i++;
	while (i >= 0)
	{
		if (*(string + i) == v_c)
			return ((char *)(string + i));
		i--;
	}
	return (0);
}
