/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 00:49:55 by dbatista          #+#    #+#             */
/*   Updated: 2024/10/16 20:39:33 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_len(int num)
{
	int	c;

	c = 0;
	if (num < 0)
		c++;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 10;
		c++;
	}
	return (c);
}
int	ft_putnbr(int n)
{

	char	c;
	char	count;

	count = ft_len(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, '-', 1);
		n *= -1;
	}
	else
	{
		ft_putnbr(n / 10);
	}
	c = (n % 10 + '0');
	write(1, &c, 1);
	return (count);
}