#include "minishell.h"

void make_token(char *input, t_list **token_list, int token_size)
{
	char *token;
	t_list *new_token;

	token = ft_substr(input, 0, token_size);
	new_token = ft_lstnew(token);
	if (new_token == NULL)
		exit(1);
	ft_lstadd_back(token_list, new_token);
}

char *substitute_env(int before_len, char *after, char *content)
{
	char *env_subs;
	int	i;
	int j;

	env_subs = (char *)malloc(sizeof(char) * (ft_strlen(content) + ft_strlen(after) - before_len));
	if (!env_subs)
		exit(1);
	i = 0;
	while (content[i] && content[i] != '$')
	{
		env_subs[i] = content[i];
		i++;
	}
	j = 0;
	while (after[j])
	{
		env_subs[i + j] = after[j];
		j++;
	}
	while (content[i + before_len + 1])
	{
		env_subs[i + j] = content[i + before_len + 1];
		i++;
	}
	env_subs[i + j] = '\0';
	free(content);
	return (env_subs);
}

void	get_sub(t_list *iter, char *tmp, int *i)
{
	char	*new;
	char	*exp;
	char	*parsed_env;
	int		env_size;

	new = ft_strdup(tmp);
	while (ft_strchr(new, '$') != 0)
	{
		env_size = 0;
		while (ft_strchr("|<> \"\'$", tmp[*i + env_size]) == 0)
			env_size++;
		parsed_env = ft_substr(tmp, *i, env_size);
		if (tmp[*i + env_size] == '$')
		{
			exp = getenv(parsed_env);
			*i += 1;
		}
		else
			exp = getenv(parsed_env);
		if (!exp && env_size)
			exp = "";
		else if (!exp && !env_size)
			exp = "$";
		new = substitute_env(env_size, exp, new);
		if (exp[0] == '$' && !env_size)
			break ;
		free(parsed_env);
		*i += env_size;
	}
	free(iter->content);
	iter->content = new;
}

void	expand_env(t_list **token_list)
{
	t_list	*iter;
	char	*tmp;
	int		flag;
	int		i;

	iter = *token_list;
	while (iter)
	{
		tmp = (char *)iter->content;
		i = 0;
		if (ft_strchr(tmp, '$'))
		{
			while (tmp[i])
			{
				flag = 0;
				if (tmp[i] == '\'' || tmp[i] == '\"')
				{
					flag = tmp[i];
					while (flag == '\'' && tmp[i])
					{
						i++;
						if (tmp[i] == flag)
						{
							flag = 0;
							i++;
						}
					}
					while (tmp[i] && flag == '\"')
					{
						if (tmp[i] != '$')
							i++;
						if (tmp[i] == '$')
						{
							i++;
							get_sub(iter, tmp, &i);
						}
						if (tmp[i] == flag)
						{
							i++;
							flag = 0;
						}
					}
				}
				else
				{
					if (tmp[i++] == '$')
						get_sub(iter, tmp, &i);
				}
			}
		}
		iter = iter->next;
	}
}

void	tokenized(char *input, t_list **token_list)
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
					return;
			}
			else
			{
				token_size++;
				input++;
			}
		}
		// printf("token size: %d\n", tok!en_size);
		if (token_size)
			make_token(input - token_size, token_list, token_size);
	}
}

void	list_print(void *content)
{
	printf("token: %s\n", content);
}

int	main(void)
{
	char	*input;
	t_list	*token_list;

	token_list = NULL;
	while (1)
	{
		input = readline("$ ");
		add_history(input);
		// printf("user input: %s\n", input);
		tokenized(input, &token_list);
		// ft_lstiter(token_list, list_print);
		expand_env(&token_list);
		free(input);
		ft_lstiter(token_list, list_print);
		ft_lstclear(&token_list, free);
	}
}