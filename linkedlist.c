#include <stdlib.h>
#include <string.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = malloc(content_size);
		if (!(new->content))
		{
			free(new);
			return (NULL);
		}
		new->content = ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		if (*alst)
		{
			(*del)((void *)(*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = NULL;
		}
	}
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*current;

	if (alst)
	{
		current = *alst;
		while (current)
		{
			next = current->next;
			(*del)(current->content, current->content_size);
			free(current);
			current = next;
		}
		*alst = NULL;
	}
}

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (alst)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst)
	{
		(*f)(lst);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	
}