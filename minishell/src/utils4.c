/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:22:20 by phan              #+#    #+#             */
/*   Updated: 2023/08/10 11:53:17 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_token(char *input, t_list **token_list, int token_size)
{
	char	*token;
	t_list	*new_token;

	token = ft_substr(input, 0, token_size);
	new_token = ft_lstnew(token);
	if (new_token == NULL)
		exit(1);
	ft_lstadd_back(token_list, new_token);
}

int	ft_atouc(char *str, unsigned char *num)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (check_num(str) == 0)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*(str++) - '0');
		if (check_over_max(sign, result, str))
			return (0);
		if (check_under_min(sign, result, str))
			return (0);
	}
	*num = (unsigned char)(result * sign);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (us1[i] || us2[i])
	{
		if (us1[i] - us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}

char	*ft_getenv(t_list **environ, char *word)
{
	char	*ret;
	char	*str;
	int		is_match;
	size_t	wd_len;
	t_list	*iter;

	iter = *environ;
	wd_len = ft_strlen(word);
	is_match = 1;
	ret = NULL;
	str = ft_strjoin(word, "=");
	while (iter)
	{
		is_match = ft_strncmp(iter->content, str, wd_len + 1);
		if (!is_match)
			break ;
		iter = iter->next;
	}
	free(str);
	if (!is_match)
		ret = ft_substr(iter->content, wd_len + 1, ft_strlen(iter->content));
	return (ret);
}

char	*ft_lst_strjoin(t_list **lst)
{
	t_list	*iter;
	char	*res;
	char	*tmp;

	res = ft_strdup((char *)(*lst)->content);
	iter = (*lst)->next;
	tmp = 0;
	while (iter)
	{
		tmp = res;
		res = ft_strjoin(res, iter->content);
		free(tmp);
		iter = iter->next;
	}
	return (res);
}
