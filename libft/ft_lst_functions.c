/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 03:09:55 by mclam             #+#    #+#             */
/*   Updated: 2021/09/19 03:09:55 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds the element ’new’ at the end of the list.
** Parameter1: The address of a pointer to the first link of a list.
** Parameter2: The address of a pointer to the element to be added to the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	if (*lst)
	{
		l = *lst;
		while (l->next)
			l = l->next;
		l->next = new;
	}
	else
		*lst = new;
}

/*
** Adds the element ’new’ at the beginning of the list.
** Parametr1: The address of a pointer to the first link of a list.
** Parametr2: The address of a pointer to the element to be added to the list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
** Deletes and frees the given element and every successor of that element,
** using the function ’del’ and free(3).
** Finally, the pointer to the list must be set to NULL.
** Parameter1: The adress of a pointer to an element.
** Parameter2. The adress of the function used to delete
** the content of the element.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if ((*lst)->next)
		ft_lstclear(&(*lst)->next, del);
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}

/*
** Takes as a parameter an element and frees the memory of the element’s
** content using the function ’del’ given as a parameter and free the element.
** The memory of ’next’ must not be freed.
** Parameter1: The element to free.
** Parameter2: The address of the function used to delete the content.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del && lst)
	{
		del(lst->content);
		free(lst);
	}
}

t_list	*ft_lstcopy(t_list *lst, void *(*cmp)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new;

	if (!lst || !del || !cmp)
		return (NULL);
	new_head = ft_lstnew(lst->content);
	if (!new_head)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		new = ft_lstnew(cmp(lst->content));
		if (!new)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_head, new);
	}
	return (new_head);
}
