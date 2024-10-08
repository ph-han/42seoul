/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:42:41 by phan              #+#    #+#             */
/*   Updated: 2023/01/19 19:23:44 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += ('a' - 'A');
		str++;
		count++;
	}
	return (str - count);
}
