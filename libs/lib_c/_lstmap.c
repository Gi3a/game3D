

#include "lib.h"

t_list	*_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l_first;
	t_list	*l_new;

	if (!lst || !f)
		return (NULL);
	l_first = NULL;
	while (lst)
	{
		if (!(l_new = _lstnew(f(lst->content))))
		{
			l_new = l_first->next;
			_lstclear(&l_first, del);
			l_first = l_new;
			lst = NULL;
			return (lst);
		}
		_lstadd_front(&l_first, l_new);
		lst = lst->next;
	}
	return (l_first);
}
