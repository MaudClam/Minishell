/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitset_lc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:06:09 by mclam             #+#    #+#             */
/*   Updated: 2021/10/06 14:06:35 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns an array of strings obtained by
** splitting the 's' using the characters from the set 'set' as delimiters.
** The array must be terminated with a NULL pointer. Memory leaks monitored
** by the lc() function.
** Parameter1: The string to be split.
** Parameter2: Separator character set.
** Return value: The array of new strings resulting from the split. NULL if
** the allocation fails.
*/
static size_t	word_counter(char const *s, char const *set)
{
	size_t	word_cnt;
	char	flag;
	size_t	i;

	word_cnt = 0;
	flag = 0;
	i = 0;
	while (s && s[i])
	{
		if (ft_isinset(s[i], set))
			flag = 0;
		else
		{
			if (flag == 0)
			{
				flag = 1;
				word_cnt++;
			}
		}
		i++;
	}
	return (word_cnt);
}

static void	splitter(char **split, char *str, char const *set, size_t word_cnt)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < word_cnt)
	{
		while (str[i] && ft_isinset(str[i], set))
			str[i++] = '\0';
		split[j++] = &str[i];
		while (str[i] && !ft_isinset(str[i], set))
			i++;
		while (str[i] && ft_isinset(str[i], set))
			str[i++] = '\0';
	}
	split[word_cnt] = NULL;
}

char	**ft_splitset_lc(char const *s, char const *set)
{
	size_t	word_cnt;
	char	*str;
	char	**split;

	word_cnt = word_counter(s, set);
	str = ft_strdup_lc(s);
	if (!str)
		return (NULL);
	split = lc(malloc(sizeof(char *) * (word_cnt + 1)));
	if (!split)
	{
		ft_error_msg("lbft: malloc() error in ft_splitset_lc()", ENOMEM);
		errno = ENOMEM;
		return (NULL);
	}
	splitter(split, str, set, word_cnt);
	return (split);
}
