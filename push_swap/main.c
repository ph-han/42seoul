/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:39:13 by phan              #+#    #+#             */
/*   Updated: 2023/05/15 17:00:10 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (0);
	while (*argv)
	{
		if (ft_atoi(*argv) == 0)
		{
			if (*argv[0] == '0')
				continue ;
			ft_printf("Error\n");
			return (0);
		}
		argv++;
	}
	return (0);
}
