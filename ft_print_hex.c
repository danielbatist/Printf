/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:54:52 by dbatista          #+#    #+#             */
/*   Updated: 2024/10/18 20:51:01 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long nbr, int pre)
{
	int	count;

	count = 0;
	if (nbr == 0)
	{
		return (ft_putstr("(nil)"));
	}
	if (pre == 0)
		count += ft_putstr("0x");
	if (nbr > 15)
		count += ft_putptr((nbr / 16), 1);
	count += ft_putchar("0123456789abcdef"[nbr % 16]);
	return (count);
}

int	ft_putnbr_hex_low(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 15)
		count += ft_putnbr_hex_low(nb / 16);
	count += ft_putchar("0123456789abcdef"[nb % 16]);
	return (count);
}

int	ft_putnbr_hex_up(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 15)
		count += ft_putnbr_hex_up(nb / 16);
	count += ft_putchar("0123456789ABCDEF"[nb % 16]);
	return (count);
}
