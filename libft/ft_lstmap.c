/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:18:43 by phan              #+#    #+#             */
/*   Updated: 2023/03/27 19:49:01 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*n_lst;
	void	*n_cont;

	if (!lst || !f || !del)
		return (0);
	n_lst = 0;
	while (lst)
	{
		n_cont = f(lst->content);
		new = ft_lstnew(n_cont);
		if (!new)
		{
			free(n_cont);
			ft_lstclear(&n_lst, del);
			return (0);
		}
		ft_lstadd_back(&n_lst, new);
		lst = lst->next;
	}
	return (n_lst);
}
