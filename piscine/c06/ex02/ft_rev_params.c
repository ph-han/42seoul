/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:25:08 by phan              #+#    #+#             */
/*   Updated: 2023/01/30 15:26:36 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	param_len;
	int	idx;

	if (argc == 1)
		return (0);
	idx = 0;
	while (*(argv + idx))
		idx++;
	idx--;
	while (idx > 0)
	{
		param_len = 0;
		while (*(argv[idx] + param_len))
			param_len++;
		write(1, argv[idx], param_len);
		write(1, "\n", 1);
		idx--;
	}
}
