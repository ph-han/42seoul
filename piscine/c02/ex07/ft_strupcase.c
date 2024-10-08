/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:32:28 by phan              #+#    #+#             */
/*   Updated: 2023/01/19 19:23:23 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= ('a' - 'A');
		str++;
		count++;
	}
	return (str - count);
}
