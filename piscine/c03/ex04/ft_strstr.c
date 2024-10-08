/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:31:54 by phan              #+#    #+#             */
/*   Updated: 2023/01/26 15:08:13 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find);
int		is_find(char *str, char *to_find);

int	is_find(char *str, char *to_find)
{
	while (*str && *to_find)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	if (*to_find != '\0')
		return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (*str == '\0' && *to_find == '\0')
		return str;
	while (*(str + i))
	{
		if (is_find(str + i, to_find))
		{
			return (str + i);
		}
		i++;
	}
	return (0);
}
