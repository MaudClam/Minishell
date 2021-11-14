/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 04:38:03 by mclam             #+#    #+#             */
/*   Updated: 2021/09/19 04:38:03 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates the list ’lst’ and applies the function ’f’ to the content
** of each element.
** Parameter1. The adress of a pointer to an element.
** Parameter2. The adress of the function used to iterate on the list.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!lst || !f)
		return ;
	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}

/*
** Iterates the list ’lst’ and applies the function ’f’ to the content
** of each element. Creates a new list resulting of the successive
** applications of the function ’f’. The ’del’ function is used to delete
** the content of an element if needed.
** Return value: The new list. NULL if the allocation fails.
** Parameter1: The adress of a pointer to an element.
** Parameter2: The adress of the function used to iterate on the list.
** Parameter3: The adress of the function used to delete the content
** of an element if needed.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*elem;

	if (!lst)
		return (NULL);
	result = NULL;
	while (lst)
	{
		elem = ft_lstnew((*f)(lst->content));
		if (!elem)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, elem);
		lst = lst->next;
	}
	return (result);
}

/*
** Allocates (with malloc(3)) and returns a new element.
** The variable ’content’ is initialized with the value of the parameter
** ’content’. The variable ’next’ is initialized to NULL.
** Return value: The new element.
** Parametr: The content to create the new element with.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem)
	{
		elem->content = content;
		elem->next = NULL;
	}
	return (elem);
}

/*
** Counts the number of elements in a list.
** Return value: Length of the list.
** Parameter: The beginning of the list.
*/
int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/*
** Allocates (with malloc(3)) and returns a new element.
** The variable ’content’ is initialized with the value of the parameter
** ’content’. The variable ’next’ is initialized to NULL.
** Memory leaks monitored by the lc() function.
** Return value: The new element.
** Parametr: The content to create the new element with.
*/
t_list	*ft_lstnew_lc(void *content)
{
	t_list	*elem;

	elem = lc(malloc(sizeof(t_list)));
	if (elem)
	{
		elem->content = content;
		elem->next = NULL;
	}
	else
		ft_error_exit("libft: Cannot allocate memory ft_lstnew_lc()", ENOMEM);
	return (elem);
}
