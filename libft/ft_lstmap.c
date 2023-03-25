/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:18:43 by phan              #+#    #+#             */
/*   Updated: 2023/03/26 01:26:00 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	while (lst)
	{
		tmp->content = f(lst->content);
		if(!tmp->content)
		{
			del(tmp->content);
			del(lst->content);
		}
		lst = lst->next;
	}
}
