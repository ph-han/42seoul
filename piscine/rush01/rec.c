/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:57:51 by phan              #+#    #+#             */
/*   Updated: 2023/01/22 17:04:28 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int ft_check_solution_up(int solution[4][4], int condition[4][4], int row);
int ft_check_solution_down(int solution[4][4], int condition[4][4], int row);
int ft_check_solution_left(int solution[4][4], int condition[4][4], int col);
int ft_check_solution_right(int solution[4][4], int condition[4][4], int col);
void ft_nb_four_definite(int solution[4][4], int condition[4][4]);

int all_check_solution(int solution[4][4], int condition[4][4])
{
	int index;
	
	index = 0;
	while (index < 4)
	{
		if(!ft_check_solution_up(solution, condition, index))
			return (0);
		if(!ft_check_solution_down(solution, condition, index))
			return (0);
		if(!ft_check_solution_left(solution, condition, index))
			return (0);
		if(!ft_check_solution_right(solution, condition, index))
			return (0);
		index++;
	}
	return (1);
}

void rec(int solution[4][4], int condition[4][4], int current_dep)
{
	int index = 0;
	int c_idx = 0;
	int comb_idx = 0;
	int win = 0;
	int comb[6][3] = {
		{1, 2, 3},
		{1, 3, 2},
		{2, 1, 3},
		{2, 3, 1},
		{3, 1, 2},
		{3, 2, 1}
	};
	if (all_check_solution(solution, condition))
	{
		printf("success\n");
		for (int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				printf("%d ", solution[i][j]);
			}
			printf("\n");
		}
		return ;
	}
	if (current_dep >= 4)
		return ;
	comb_idx = 0;
	while (comb_idx <= 5)
	{
		index = 0;
		c_idx = 0;
		while (index < 4)
		{
			if (solution[current_dep][index] == 4)
				index++;
			else
			{
				solution[current_dep][index] = comb[comb_idx][c_idx];
				index++;
				c_idx++;
			}
		}
		rec(solution, condition, current_dep + 1);
		comb_idx++;
	}
}

int main()
{
	int solution1[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	int solution2[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	int solution3[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	int condition1[4][4] = {{2,1,3,3}, {3,2,1,2}, {2,1,3,3},{3,2,1,2}};
	int condition2[4][4] = {{4,3,2,1}, {1,2,2,2}, {4,3,2,1},{1,2,2,2}};
	int condition3[4][4] = {{2,1,3,2}, {1,3,2,2}, {2,3,3,1},{3,1,2,2}};

	ft_nb_four_definite(solution1, condition1);
	ft_nb_four_definite(solution2, condition2);
	ft_nb_four_definite(solution3, condition3);
	printf("----test1----\n");
	rec(solution1, condition1, 0);
	printf("----test2----\n");
	rec(solution2, condition2, 0);
	printf("----test3----\n");
	rec(solution3, condition3, 0);
}
