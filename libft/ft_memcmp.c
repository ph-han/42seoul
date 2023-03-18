/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:28:04 by phan              #+#    #+#             */
/*   Updated: 2023/03/18 19:40:02 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned char	*_s1;
	unsigned char	*_s2;
	unsigned int	i;

	_s1 = (unsigned char *)s1;
	_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((_s1[i] == _s2[i]) && i + 1 < n)
		i++;
	return (_s1[i] - _s2[i]);
}
