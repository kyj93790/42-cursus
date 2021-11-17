#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*pCur;

	curr = *lst;
	while (curr)
	{
		pCur = curr;
		curr = curr->next;
		ft_lstdelone(pCur, del);
	}
	*lst = NULL;
}
