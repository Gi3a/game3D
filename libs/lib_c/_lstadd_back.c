

#include "lib.h"

void	_lstadd_back(t_list **lst, t_list *new)
{
	t_list *buf;

	if (lst)
	{
		if (*lst)
		{
			buf = _lstlast(*lst);
			buf->next = new;
		}
		else
			*lst = new;
	}
}
