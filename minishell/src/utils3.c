/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:21:11 by phan              #+#    #+#             */
/*   Updated: 2023/08/10 11:53:08 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_delim_in_dquote(char c)
{
	return (c == '<' || c == '>' || c == '\'' \
		|| c == '|' || c == '$' || c == ' ');
}

int	is_delim(char c)
{
	return (c == '$' || c == '\'' || c == '\"');
}

int	ft_is_blank(int c)
{
	return (c == ' ' || c == '\t');
}

char	**free_all(char **w_list)
{
	int	i;

	i = -1;
	while (w_list[++i])
		free(w_list[i]);
	free(w_list);
	w_list = NULL;
	return (0);
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("0123456789", str[i]))
			return (0);
		i++;
	}
	return (1);
}
