/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_mid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:46:32 by phan              #+#    #+#             */
/*   Updated: 2023/08/10 11:46:33 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_mid(t_list **lst, t_list *node)
{
	t_list	*prev;
	t_list	*next;

	prev = node->prev;
	next = node->next;
	if (prev)
		prev->next = next;
	else
		*lst = next;
	if (next)
		next->prev = prev;
	ft_lstdelone(node, free);
}
