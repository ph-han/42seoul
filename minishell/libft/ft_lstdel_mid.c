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
