/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:10:30 by mclam             #+#    #+#             */
/*   Updated: 2021/09/29 17:10:30 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function void *lc(void *ptr) takes a pointer created with malloc(3),
** writes it to the pointer table, and frees that memory when needed.
** Returned value: the received pointer. NULL if the parameter are NULL,
** (void *)1, (void *)-1, or if the memory allocation for an element
** of the pointer table is denied.
** Parameter: pointer or NULL or (void *)1 or (void *)-1.
** Function actions:
** 1.If the parameter is a pointer, it is written to the pointer table.
** 2.If the parameter is NULL, all memory pointed to by pointers from
**   the table is freed along with the memory occupied by the table.
** 3.If the parameter is (void *)-1, a flag is set in the table of pointers
**   opposite the last pointer.
** 4.If the parameter is (void *)1, the memory will be freed
**   only up to the nearest pointer with a flag in the reverse order
**   of pointers entering the table.
** 5.If memory allocation for the next element of the table of pointers
**   is prohibited, all the memory pointed to by the pointers from the table
**   is freed along with the memory occupied by the table, the function
**   will return NULL, issue an error message "malloc() error in lc()
**   function" with the value errno and errno is set to ENOMEM.
**   In this case, the memory pointed to by the pointer passed as a parameter
**   will also be freed.
*/
static int	lc_freeone(t_lc *lc, int mode)
{
	t_lc	*l;

	l = lc;
	while (l->next && l->next->next)
		l = l->next;
	if (l == lc && !l->next)
	{
		free(l->ptr);
		l->ptr = NULL;
		return (0);
	}
	free(l->next->ptr);
	free(l->next);
	l->next = NULL;
	return (!(l->flag && mode));
}

static void	lc_freemem(t_lc *lc, int mode)
{
	int	freeone_result;

	freeone_result = 1;
	while (freeone_result)
		freeone_result = lc_freeone(lc, mode);
}

static void	*lc_newptr(t_lc *lc, void *ptr)
{
	t_lc	*l;

	l = lc;
	if (l->ptr)
	{
		while (l->next)
			l = l->next;
		l->next = malloc(sizeof(t_lc));
		if (l->next)
		{
			ft_bzero(l->next, sizeof(t_lc));
			l->next->ptr = ptr;
		}
		else
		{
			ft_error_msg("malloc() error in lc() function", ENOMEM);
			lc_freemem(lc, (uintptr_t)FREE_ALL);
			free(ptr);
			ptr = NULL;
			errno = ENOMEM;
		}
	}
	else
		l->ptr = ptr;
	return (ptr);
}

static void	lc_fixptr(t_lc *lc)
{
	t_lc	*l;

	l = lc;
	while (l->next)
		l = l->next;
	l->flag = 1;
}

void	*lc(void *ptr)
{
	static t_lc	lc;

	if (ptr == FREE_ALL)
		lc_freemem(&lc, (uintptr_t)FREE_ALL);
	else if (ptr == FREE_TO_FIX)
		lc_freemem(&lc, (uintptr_t)FREE_TO_FIX);
	else if (ptr == FIX_POINTER)
		lc_fixptr(&lc);
	else
		return (lc_newptr(&lc, ptr));
	return (NULL);
}
