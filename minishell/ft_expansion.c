#include "minishell.h"

int	is_delim(char c)
{
	return (c == '$' || c == '\'' || c == '\"');
}

void	expansion(t_list *node, char *content, int *idx)
{
	t_list	*lst = NULL;
	char	*str;
	char	*env;
	int		key_size;
	int		q_flag;
	int		i;

	(void)node;
	i = 0;
	q_flag = 0;
	// printf("content[i]: %c", content[i]);
	while (content[i])
	{
		key_size = 0;
		if (content[i + key_size] == '$' && q_flag != '\'')
		{
			i++;
			while (content[i + key_size] && !is_delim(content[i + key_size]))
			{
				if (q_flag == '\"' && content[i + key_size] == ' ')
					break ;
				key_size++;
			}
			str = ft_substr(content, i, key_size);
			env = getenv(str);
			free(str);
			if (env == NULL && key_size != 0)
				env = "";
			else if (env == NULL && key_size == 0)
				env = "$";
			// printf("env : %s keysiSERze: %d\n", env, key_size);
			env = ft_strdup(env);
			ft_lstadd_back(&lst, ft_lstnew(env));
			i += key_size;
		}
		else if (content[i + key_size] == '\'')
		{
			if (q_flag == 0)
				q_flag = '\'';
			else if (q_flag == '\'')
				q_flag = 0;
			ft_lstadd_back(&lst, ft_lstnew(ft_strdup("\'")));
			i++;
		}
		else if (content[i + key_size] == '\"')
		{
			if (q_flag == 0)
				q_flag = '\"';
			else if (q_flag == '\"')
				q_flag = 0;
			ft_lstadd_back(&lst, ft_lstnew(ft_strdup("\"")));
			i++;
		}
		else
		{
			while (content[i + key_size]
				&& !ft_strchr("\'\"", content[i + key_size]))
				{
					if (q_flag != '\'' && content[i + key_size] == '$')
						break ;
					key_size++;
				}
			str = ft_substr(content, i, key_size);
			// printf("str: %s q_flag: %c\n", str, q_flag);
			ft_lstadd_back(&lst, ft_lstnew(str));
			i += key_size;
		}
	}
	*idx += i;
	// ft_lstiter(lst, list_print);
	free(node->content);
	node->content = ft_lst_strjoin(&lst);
	ft_lstclear(&lst, free);
}

char	*ft_lst_strjoin(t_list **lst)
{
	t_list	*iter;
	char	*res;
	char	*tmp;

	res = ft_strdup((char *)(*lst)->content);
	iter = (*lst)->next;
	while (iter)
	{
		tmp = res;
		res = ft_strjoin(res, iter->content);
		free(tmp);
		iter = iter->next;
	}
	return (res);
}
