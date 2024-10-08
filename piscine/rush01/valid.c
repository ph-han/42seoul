/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:18:19 by phan              #+#    #+#             */
/*   Updated: 2023/01/22 16:03:00 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check_solution_up(int solution[4][4], int condition[4][4], int row)
{
	int	max;
	int	cnt;
	int	i;
	int is_ten;

	max = 0;
	cnt = 0;
	i = 0;
	is_ten = 0;
	while (i < 4)
	{
		if (max < solution[i][row])
		{
			max = solution[i][row];
			cnt++;
		}
		is_ten += solution[i][row];
		i++;
	}
	return (is_ten == 10) && (cnt == condition[0][row]);
}

int	ft_check_solution_down(int solution[4][4], int condition[4][4], int row)
{
	int	max;
	int	cnt;
	int	i;
	int is_ten;

	max = 0;
	cnt = 0;
	i = 0;
	is_ten = 0;
	while (i < 4)
	{
		if (max < solution[3 - i][row])
		{
			max = solution[3 - i][row];
			cnt++;
		}
		is_ten += solution[3 - i][row];
		i++;
	}
	return (is_ten == 10 && cnt == condition[1][row]);
}

int	ft_check_solution_left(int solution[4][4], int condition[4][4], int col)
{
	int	max;
	int	cnt;
	int	i;
	int is_ten;

	max = 0;
	cnt = 0;
	i = 0;
	is_ten = 0;
	while (i < 4)
	{
		if (max < solution[col][i])
		{
			max = solution[col][i];
			cnt++;
		}
		is_ten += solution[col][i];
		i++;
	}
	return (is_ten == 10 && cnt == condition[2][col]);
}

int	ft_check_solution_right(int solution[4][4], int condition[4][4], int col)
{
	int	max;
	int	cnt;
	int	i;
	int is_ten;

	max = 0;
	cnt = 0;
	i = 0;
	is_ten = 0;
	while (i < 4)
	{
		if (max < solution[col][3 - i])
		{
			max = solution[col][3 - i];
			cnt++;
		}
		is_ten += solution[col][3 - i];
		i++;
	}
	return (is_ten == 10 && cnt == condition[3][col]);
}

/*int main(void)
{
	//int temp[4][4] = {{1,2,3,4},{2,3,4,1},{3,4,1,2},{4,1,2,3}};
	int temp[4][4] = {{3,4,2,1},{4,2,1,3},{2,1,3,4},{1,3,4,2}};
	int condition[4][4] = {{2,1,3,3}, {3,2,1,2}, {2,1,3,3},{3,2,1,2}};
	for(int i = 0; i < 4; i++)
	{
		printf("up : %d \n", ft_check_solution_up(temp, condition, i));
		printf("down : %d \n", ft_check_solution_down(temp, condition, i));
		printf("left : %d \n", ft_check_solution_left(temp, condition, i));
		printf("right : %d \n", ft_check_solution_right(temp, condition, i));
	}
}*/

