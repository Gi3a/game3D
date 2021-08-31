

#include "lib.h"

t_list		*_lstnew(void *content)
{
	t_list	*lst;

	if ((lst = (t_list*)malloc(sizeof(lst))) == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
