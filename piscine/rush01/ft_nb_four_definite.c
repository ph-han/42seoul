/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_four_definite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:42:47 by phan              #+#    #+#             */
/*   Updated: 2023/01/21 17:17:55 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_nb_four_definite(int solution[][4], int condition[][4]);

void	ft_nb_four_definite(int solution[][4], int condition[][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (condition[0][i] == 1)
			solution[0][i] = 4;
		if (condition[1][i] == 1)
			solution[3][i] = 4;
		if (condition[2][i] == 1)
			solution[i][0] = 4;
		if (condition[3][i] == 1)
			solution[i][3] = 4;
		if (condition[0][i] == 2 && condition[1][i] == 3)
			solution[1][i] = 4;
		if (condition[0][i] == 3 && condition[1][i] == 2)
			solution[2][i] = 4;
		if (condition[2][i] == 2 && condition[3][i] == 3)
			solution[i][1] = 4;
		if (condition[2][i] == 3 && condition[3][i] == 2)
			solution[i][2] = 4;
		i++;
	}
}
