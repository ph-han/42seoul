/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:53:29 by hcho2             #+#    #+#             */
/*   Updated: 2023/09/26 12:55:18 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	res_int;
	double	res_decimal;
	char	*c;
	int		len;

	c = (char *)str;
	res_int = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res_decimal = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res_decimal /= 10;
	if (res_int >= 0)
		return (res_int + res_decimal);
	else
		return (res_int - res_decimal);
}
