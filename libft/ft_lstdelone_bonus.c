
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*current;

	if (!lst || !del)
		return ;
	del(lst->content);
	current = lst;
	lst = current->next;
	free(current);
	lst = 0;
}
