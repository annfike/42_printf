/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:56:56 by adelaloy          #+#    #+#             */
/*   Updated: 2023/10/30 09:41:37 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar_len(char c);
int	ft_putstr_len(char *str);
int	ft_putnbr_len(int n);
int	ft_putnbr_u_len(unsigned int n);
int	ft_puthex(unsigned long n, char *base);
int	ft_puthex_len(unsigned int n, const char format);
int	ft_putptr_len(unsigned long n);
int	ft_format(va_list args, const char format);
int	ft_printf(const char *str, ...);

#endif