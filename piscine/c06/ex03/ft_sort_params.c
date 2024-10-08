/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:30:45 by phan              #+#    #+#             */
/*   Updated: 2023/01/29 15:36:49 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	my_strcmp(char *str1, char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

void	print(char *argv[])
{
	int	param_len;
	int	idx;

	idx = 1;
	while (*(argv + idx))
	{
		param_len = 0;
		while (*(argv[idx] + param_len))
			param_len++;
		write(1, argv[idx], param_len);
		write(1, "\n", 1);
		idx++;
	}
}

void	sort(char *argv[], int params)
{
	char	*temp;
	int		i;
	int		j;

	i = 1;
	while (i < params)
	{
		j = i + 1;
		while (j < params)
		{
			if (my_strcmp(argv[i], argv[j]) > 0)
			{
				temp = argv[j];
				argv[j] = argv[i];
				argv[i] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		params;

	params = 1;
	if (argc == 1)
		return (0);
	while (*(argv + params))
		params++;
	sort(argv, params);
	print(argv);
}
