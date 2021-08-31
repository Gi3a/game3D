
#include "lib.h"

void	_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	if (lst)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
