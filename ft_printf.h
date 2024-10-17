/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:28:04 by dbatista          #+#    #+#             */
/*   Updated: 2024/10/16 20:40:24 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_char_print(char c);
int		ft_str_print(char *str);
int		ft_putnbr_u(unsigned int n);
int		ft_puthex(int n);
int		ft_putnbr(int n);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *format, ...);

#endif