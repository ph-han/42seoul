/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:59:46 by phan              #+#    #+#             */
/*   Updated: 2023/01/29 15:31:58 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	param_len;
	int	idx;

	if (argc == 1)
		return (0);
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
