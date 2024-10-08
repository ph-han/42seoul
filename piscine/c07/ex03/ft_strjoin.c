/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:26:35 by phan              #+#    #+#             */
/*   Updated: 2023/01/31 12:49:18 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *str);
int		tot_strs_len(int size, char **strs);

char	*ft_strcat(char *dest, char *src)
{
	int	dest_idx;

	dest_idx = 0;
	while (*(dest + dest_idx))
		dest_idx++;
	while (*src)
	{
		*(dest + dest_idx) = *src;
		dest_idx++;
		src++;
	}
	*(dest + dest_idx) = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
		idx++;
	return (idx);
}

int	tot_strs_len(int size, char **strs)
{
	int	tot;
	int	idx;

	tot = 0;
	idx = 0;
	while (idx < size)
	{
		tot += ft_strlen(strs[idx]);
		idx++;
	}
	return (tot);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		result_len;
	int		idx;
	char	*result;

	if (size < 0)
		return (0);
	if (size == 0)
		result_len = 0;
	else
		result_len = tot_strs_len(size, strs) + (size - 1) * ft_strlen(sep);
	result = (char *)malloc(result_len + 1);
	result[0] = '\0';
	if (size == 0)
		return (result);
	idx = 0;
	while (idx < size - 1)
	{
		result = ft_strcat(result, strs[idx]);
		result = ft_strcat(result, sep);
		idx++;
	}
	result = ft_strcat(result, strs[idx]);
	return (result);
}
