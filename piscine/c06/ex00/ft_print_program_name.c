/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:55:02 by phan              #+#    #+#             */
/*   Updated: 2023/01/28 19:59:08 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	program_name_len;

	program_name_len = 0;
	while (*(argv[0] + program_name_len))
		program_name_len++;
	if (argc != 0)
	{
		write(1, argv[0], program_name_len);
		write(1, "\n", 1);
	}
	return (0);
}
