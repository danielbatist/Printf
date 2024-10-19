/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:23:13 by dbatista          #+#    #+#             */
/*   Updated: 2024/10/18 21:14:06 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_selector(const char *format, va_list args)
{
	int		c;

	c = 0;
	if (*format == '%')
		c += ft_putchar('%');
	else if (*format == 'c')
		c += ft_putchar((char)va_arg(args, int));
	else if (*format == 's')
		c += ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
		c += ft_putptr(va_arg(args, unsigned long), 0);
	else if (*format == 'd' || *format == 'i')
		c += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		c += ft_putnbr_u(va_arg(args, unsigned int));
	else if (*format == 'x')
		c += ft_putnbr_hex_low(va_arg(args, unsigned int));
	else if (*format == 'X')
		c += ft_putnbr_hex_up(va_arg(args, unsigned int));
	return (c);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start (args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_selector(&format[i], args);
		}
		else
		{
			write (1, &format[i], 1);
			count += 1;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	char	c1 = 'a';
	char	c2 = 'B';
	char	c3 = 'c';
	char	c4 = 'D';
	printf("---------------------\n");
	printf("Teste Char\n");
	printf("%i\n", printf("%c as %c fs %c ap %c 11\n", c1, c2, c3, c4));
	printf("%i\n", ft_printf("%c as %c fs %c ap %c 11\n", c1, c2, c3, c4));
	printf("---------------------\n");
	
	char	*str = "hello world";
	char	*str1 = "NULL";
	
	printf("Teste String\n");
	printf("%i\n", printf("%s\n", str1));
	printf("%i\n", ft_printf("%s\n", str1));

	printf("%i\n", printf("%%%%%%\n"));
	printf("%i\n", ft_printf("%%%%%%\n"));

	printf("%i\n", printf("%%s\n"));
	printf("%i\n", ft_printf("%%s\n"));

	printf("%i\n", printf("%s\n", str));
	printf("%i\n", ft_printf("%s\n", str));
	printf("---------------------\n");
	
	printf("Teste decimal e Inteiro\n");
	printf("%i\n", printf("%d max decimal, %i min int\n", INT_MAX, INT_MIN));
	printf("%i\n", ft_printf("%d max decimal, %i min int\n", INT_MAX, INT_MIN));
	printf("---------------------\n");
	
	printf("Teste Ponteiro\n");
	printf("%i\n", printf("%p\n", str));
	printf("%i\n", ft_printf("%p\n", str1));
	printf("---------------------\n");

	printf("Teste unsigned int\n");
	printf("%i\n", printf("%u\n", UINT_MAX));
	printf("%i\n", ft_printf("%u\n", UINT_MAX));
	printf("---------------------\n");
	
	printf("Teste hexadecimal lower\n");
	printf("%i\n", printf("%x\n", UINT_MAX));
	printf("%i\n", ft_printf("%x\n", UINT_MAX));
	printf("---------------------\n");

	printf("Teste hexadecimal upper\n");
	printf("%i\n", printf("%X\n", UINT_MAX));
	printf("%i\n", ft_printf("%X\n", UINT_MAX));
	printf("---------------------\n");
	return (0);
}*/
