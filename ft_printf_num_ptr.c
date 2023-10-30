/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:27:48 by adelaloy          #+#    #+#             */
/*   Updated: 2023/10/30 10:28:30 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		len += ft_putchar_len('-');
		n = -n;
	}
	if (n > 9)
		len += ft_putnbr_len(n / 10);
	len += ft_putchar_len(n % 10 + '0');
	return (len);
}

int	ft_putnbr_u_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putnbr_u_len(n / 10);
	len += ft_putchar_len(n % 10 + '0');
	return (len);
}

int	ft_puthex(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += ft_puthex(n / 16, base);
		len += ft_puthex(n % 16, base);
	}
	else
		len += ft_putchar_len(base[n]);
	return (len);
}

int	ft_puthex_len(unsigned int n, char format)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (ft_puthex(n, base));
}

int	ft_putptr_len(unsigned long n)
{
	int		len;
	char	*base;

	base = "0123456789abcdef";
	len = 0;
	len += write(1, "0x", 2);
	len += ft_puthex(n, base);
	return (len);
}
