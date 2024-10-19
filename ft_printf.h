/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:28:04 by dbatista          #+#    #+#             */
/*   Updated: 2024/10/18 20:51:53 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		count_print(int iter);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putptr(unsigned long nbr, int pre);
int		ft_putnbr(int nb);
int		ft_putnbr_u(unsigned int nb);
int		ft_putnbr_hex_low(unsigned int nb);
int		ft_putnbr_hex_up(unsigned int nb);
int		ft_printf(const char *format, ...);

#endif