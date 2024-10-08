/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:42:38 by phan              #+#    #+#             */
/*   Updated: 2023/08/10 11:52:19 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_operation_section(char **input, \
	t_list **token_list, int *token_size)
{
	if (*(*input) == '|')
	{
		if (*token_size)
		{
			make_token(*input - *token_size, token_list, *token_size);
			*token_size = 0;
		}
		make_token((*input)++, token_list, 1);
	}
	else if (*(*input) == '<' || *(*input) == '>')
	{
		if (*token_size)
		{
			make_token(*input - *token_size, token_list, *token_size);
			*token_size = 0;
		}
		if (*(*(input) + 1) == *(*input))
		{
			make_token(*input, token_list, 2);
			(*input) += 2;
		}
		else
			make_token((*input)++, token_list, 1);
	}
}

void	process_quote_section(int *flag, char **input, int *token_size)
{
	*flag = *(*input);
	while (*flag && *(*input))
	{
		(*token_size)++;
		(*input)++;
		if (*(*input) == *flag)
		{
			(*token_size)++;
			(*input)++;
			*flag = 0;
		}
	}
}

void	process_other_section(int *token_size, char **input)
{
	(*token_size)++;
	(*input)++;
}

int	tokenizer(char *input, t_list **token_list, int flag)
{
	int		token_size;

	while (*input)
	{
		token_size = 0;
		flag = 0;
		while (ft_is_blank(*input))
			input++;
		while (*input && !ft_is_blank(*input))
		{
			if (*input == '|' || *input == '<' || *input == '>')
				process_operation_section(&input, token_list, &token_size);
			else if (*input == '\"' || *input == '\'')
			{
				process_quote_section(&flag, &input, &token_size);
				if (flag)
					return (1);
			}
			else
				process_other_section(&token_size, &input);
		}
		if (token_size)
			make_token(input - token_size, token_list, token_size);
	}
	return (0);
}
