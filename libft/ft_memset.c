/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:25:21 by phan              #+#    #+#             */
/*   Updated: 2023/03/18 18:59:18 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned int	i;
	unsigned char	*_b;

	_b = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		_b[i] = (unsigned char)c;
		i++;
	}
	return ((void *)_b);
}
