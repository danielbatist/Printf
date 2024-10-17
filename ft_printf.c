/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:23:13 by dbatista          #+#    #+#             */
/*   Updated: 2024/10/16 21:09:05 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		res;

	va_start (args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				return (ft_char_print('%'));
			else if (format[i] == 'c')
				return (ft_char_print((char)va_arg(args, int)));
			else if (format[i] == 's')
				return (ft_str_print(va_arg(args, char *)));
			else if (format[i] == 'i' ||  format[i] == 'd')
				return (ft_putnbr(va_arg(args, int)));
			//else if (format[i] == 'p')
			//	ft_putnbr(va_arg(args, void *));
		}
		else
			write (1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	/*char	c1 = 'a';
	char	c2 = 'b';
	char	c3 = 'c';
	char	c4 = 'd';
	printf("%c asfa %c fsds %c apoj %c 1123\n", c1, c2, c3, c4);
	ft_printf("%c asfa %c fsds %c apoj %c 1123\n", c1, c2, c3, c4);
	*/

	/*char	*str = "hello world";
	char	*str1 = "";

	printf("%s\n", str1);
	ft_printf("%s\n", str1);

	printf("%%%%%%\n");
	ft_printf("%%%%%%\n");

	printf("%%s\n");
	ft_printf("%%s\n");

	printf("%s\n", str);
	ft_printf("%s\n", str);*/

	printf("%d decimal %i integer\n", 10, 20);
	ft_printf("%d decimal %i integer\n", 10, 20);
	return (0);
}
