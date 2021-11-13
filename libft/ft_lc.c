/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:10:30 by mclam             #+#    #+#             */
/*   Updated: 2021/11/07 02:37:07 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lc	*lc_newcell_add(t_lc **lc);
void	lc_mark_ptr(t_lc *lc, unsigned int mark);
void	lc_mv_fromark_tobegin(t_lc **lc);

/*
** Function void *lc(void *ptr) takes a pointer created with malloc(3),
** writes it to the pointer table, and frees that memory when needed.
** Returned value: the received pointer. NULL if the parameter are NULL,
** (void *)1, (void *)-1, or if the memory allocation for an element
** of the pointer table is denied.
** Parameter: pointer or NULL or (void *)1 or (void *)2.
** Function actions:
** 1.If the parameter is a pointer, it is written to the pointer table.
** 2.If the parameter is NULL, all memory pointed to by pointers from
**   the table is freed along with the memory occupied by the table.
** 3.If the parameter is (void *)2, a flag is set in the table of pointers
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
static int	lc_free_firstptr(t_lc **lc, unsigned int mode)
{
	if (!(mode && (*lc)->flag))
	{
		free((*lc)->ptr);
		(*lc)->ptr = NULL;
		free(*lc);
		*lc = NULL;
	}
	return (FALSE);
}

static int	lc_freeone(t_lc **lc, unsigned int mode)
{
	int		status;
	t_lc	*tmp;

	status = FALSE;
	if (*lc != NULL && (*lc)->next == NULL)
		return (lc_free_firstptr(lc, mode));
	if (*lc != NULL && (*lc)->next != NULL)
	{
		tmp = *lc;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		if (!(mode && tmp->next->flag))
		{
			free(tmp->next->ptr);
			tmp->next->ptr = NULL;
			free(tmp->next);
			tmp->next = NULL;
		}
		if (!(mode && (tmp->flag || (tmp->next && tmp->next->flag))))
			status = TRUE;
		if (tmp->flag != (uintptr_t)PUT_HARDBARRIER)
			tmp->flag = 0;
	}
	return (status);
}

static void	lc_freemem(t_lc **lc, unsigned int mode)
{
	int	freeone_result;

	freeone_result = 1;
	while (freeone_result == TRUE)
		freeone_result = lc_freeone(lc, mode);
}

static void	*lc_newptr(t_lc **lc, void *ptr)
{
	t_lc	*tmp;

	tmp = lc_newcell_add(lc);
	if (tmp != NULL)
		tmp->ptr = ptr;
	else
	{
		ft_error_msg("lbft: malloc() error in lc() function", ENOMEM);
		lc_freemem(lc, (uintptr_t)FREE_ALL);
		free(ptr);
		ptr = NULL;
		errno = ENOMEM;
	}
	return (ptr);
}

void	*lc(void *ptr)
{
	static t_lc	*lc;

	if (ptr == FREE_ALL)
		lc_freemem(&lc, (uintptr_t)FREE_ALL);
	else if (ptr == FREE_TO_BARRIER)
		lc_freemem(&lc, (uintptr_t)FREE_TO_BARRIER);
	else if (ptr == PUT_BARRIER)
		lc_mark_ptr(lc, (uintptr_t)PUT_BARRIER);
	else if (ptr == PUT_HARDBARRIER)
		lc_mark_ptr(lc, (uintptr_t)PUT_HARDBARRIER);
	else if (ptr == MOVE_PTRS_TO_BEGIN)
		lc_mv_fromark_tobegin(&lc);
	else
		return (lc_newptr(&lc, ptr));
	return (NULL);
}
