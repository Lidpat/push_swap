/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:28:26 by lpalacio          #+#    #+#             */
/*   Updated: 2022/09/30 17:30:41 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putint_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		n = -n;
	}
	c = '0' + n;
	ft_putchar_fd(c, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	num;

	num = 0;
	if (n < 10 && n > -10)
		ft_putint_fd(n, fd);
	else if (n <= -10)
	{
		num = -(n % 10);
		n = n / 10;
		ft_putnbr_fd(n, fd);
		ft_putint_fd(num, fd);
	}
	else if (n >= 10)
	{
		num = n % 10;
		n = n / 10;
		ft_putnbr_fd(n, fd);
		ft_putint_fd(num, fd);
	}
}
