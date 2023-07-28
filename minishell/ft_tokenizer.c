#include "minishell.h"

void	tokenizer(char *input, t_list **token_list)
{
	int		token_size;
	int		flag;

	while (*input)
	{
		token_size = 0;
		flag = 0;
		while (*input == ' ')
			input++;
		while (*input && *input != ' ')
		{
			if (*input == '|')
			{
				if (token_size)
				{
					make_token(input - token_size, token_list, token_size);
					token_size = 0;
				}
				make_token(input++, token_list, 1);
			}
			else if (*input == '<' || *input == '>')
			{
				if (token_size)
				{
					make_token(input - token_size, token_list, token_size);
					token_size = 0;
				}
				if (*(input + 1) == *input)
				{
					make_token(input, token_list, 2);
					input += 2;
				}
				else
					make_token(input++, token_list, 1);
			}
			else if (*input == '\"' || *input == '\'')
			{
				flag = *input;
				while (flag && *input)
				{
					token_size++;
					input++;
					if (*input == flag)
					{
						token_size++;
						input++;
						flag = 0;
					}
				}
				if (flag)
					return ;
			}
			else
			{
				token_size++;
				input++;
			}
		}
		if (token_size)
			make_token(input - token_size, token_list, token_size);
	}
}


void	tokenizer_dquote(char *input, t_list **token_list)
{
	int		token_size;
	int		flag;

	while (*input)
	{
		token_size = 0;
		flag = 0;
		while (*input)
		{
			if (*input == '|')
			{
				if (token_size)
				{
					make_token(input - token_size, token_list, token_size);
					token_size = 0;
				}
				make_token(input++, token_list, 1);
			}
			else if (*input == '<' || *input == '>')
			{
				if (token_size)
				{
					make_token(input - token_size, token_list, token_size);
					token_size = 0;
				}
				if (*(input + 1) == *input)
				{
					make_token(input, token_list, 2);
					input += 2;
				}
				else
					make_token(input++, token_list, 1);
			}
			else if (*input == '\'')
			{
				flag = *input;
				while (flag && *input)
				{
					token_size++;
					input++;
					if (*input == flag)
					{
						token_size++;
						input++;
						flag = 0;
					}
				}
				if (flag)
					return ;
			}
			else if (*input == '$')
			{
				if (token_size)
				{
					make_token(input - token_size, token_list, token_size);
					token_size = 0;
				}
				while (!is_delim_in_dquote(*input) && *input)
				{
					token_size++;
					input++;
				}
			}
			else
			{
				token_size++;
				input++;
			}
		}
		if (token_size)
			make_token(input - token_size, token_list, token_size);
	}
}
