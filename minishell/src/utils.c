/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:20:49 by phan              #+#    #+#             */
/*   Updated: 2023/08/11 17:01:12 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_token_new(int type, void *content)
{
	t_token	*tmp;

	tmp = (t_token *)malloc(sizeof(t_token));
	if (!tmp)
		exit(1);
	tmp->type = type;
	tmp->content = content;
	tmp->temp = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	ft_tokenadd_back(t_token **lst, t_token *new)
{
	t_token	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->prev = NULL;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_tokendelone(t_token *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_tokendel_mid(t_token **lst, t_token *node)
{
	t_token	*prev;
	t_token	*next;

	prev = node->prev;
	next = node->next;
	if (prev)
		prev->next = next;
	else
		*lst = next;
	if (next)
		next->prev = prev;
	ft_tokendelone(node, free);
}

void	ft_tokenclear(t_token **lst, void (*del)(void *))
{
	t_token	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = *lst;
		del((*lst)->content);
		del((*lst)->temp);
		*lst = tmp->next;
		free(tmp);
	}
	lst = NULL;
}
