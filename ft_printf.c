/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:03:21 by adelaloy          #+#    #+#             */
/*   Updated: 2023/10/30 14:29:34 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_len(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_len(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
	return (i);
}

int	ft_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar_len((char)va_arg(args, int));
	else if (format == 's')
		len += ft_putstr_len(va_arg(args, char *));
	else if (format == 'p')
		len += ft_putptr_len(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr_len(va_arg(args, int));
	else if (format == 'u')
		len += ft_putnbr_u_len(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_puthex_len(va_arg(args, int), format);
	else if (format == '%')
		len += ft_putchar_len('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_format(args, str[i]);
		}
		else
			count += ft_putchar_len(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

/*
#include <stdio.h>

int	main(void)
{
	int				x;
	unsigned int	y;
	unsigned int	z;
	unsigned int	w;
	char			c;
	char			str[20] = "Hello World!";
	int				count;

	//cspdiuxX%
	x = -501;
	y = 25689;
	z = 28;
	w = 28;
	c = 'a';
	count = 0;
	count = printf("The value of x is %d, y is %u, z is %X, w is %x, \
		c is %c, str is %s, p is %p", x, y, z, w, c, (char *)NULL, (void*)str);
	printf("\ncount real = %d\n", count);
	count = 0;
	count = ft_printf("The value of x is %d, y is %u, z is %X, w is %x, \
		c is %c, str is %s, p is %p", x, y, z, w, c, (char *)NULL, (void*)str);
	printf("\ncount mine = %d\n", count);
	count = 0;
	count = printf("%+4s\n", "test");
	printf("\ncount real = %d\n", count);
	count = 0;
	count = ft_printf("\001\002\007\v\010\f\r\n");
	printf("\ncount mine = %d\n", count);
	return (0);
}*/