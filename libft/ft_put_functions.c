/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:38:57 by mclam             #+#    #+#             */
/*   Updated: 2021/09/29 19:38:57 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}

/*
** Start ft_putnbr_fd() function
*/
static int	spec_cond(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2", 2);
		nb = 147483648;
	}
	else if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -1 * nb;
	}
	return (nb);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		dgts;
	int		nb_;
	char	c;

	dgts = 1;
	n = spec_cond(n, fd);
	nb_ = n;
	while (nb_ > 9)
	{
		nb_ = nb_ / 10;
		dgts = dgts * 10;
	}
	while (dgts != 0)
	{
		c = n / dgts + '0';
		write(fd, &c, 1);
		n = n % dgts;
		dgts = dgts / 10;
	}
}
/*
** End ft_putnbr_fd() function
*/
