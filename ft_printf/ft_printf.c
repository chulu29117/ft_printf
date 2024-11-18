/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:19:31 by clu               #+#    #+#             */
/*   Updated: 2024/11/18 10:47:05 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Prototypes //
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_format_check(char specifier, va_list args);
int	ft_puthex(unsigned long long num);
int	ft_putptr(void *ptr);

// ft_printf() //
int ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			count += ft_format_check(str[i], args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// Test for ft_printf() ///////////////////////////////////////////////////////////////////////
# include <stdio.h>

void	ft_printf_test(void)
{
	ft_printf("ft_printf(), print a character: %c\n", 'A');
	printf("printf(), print a character: %c\n\n", 'A');

	ft_printf("ft_printf(), print a string: %s\n", "Hello, world!");
	printf("printf(), print a string: %s\n\n", "Hello, world!");

	ft_printf("ft_printf(), print a pointer: %p\n", &ft_putptr);
	printf("printf(), print a pointer: %p\n\n", &ft_putptr);

	ft_printf("ft_printf(), print a pointer: %p\n", NULL);
	printf("printf(), print a pointer: %p\n\n", NULL);

	ft_printf("ft_printf(), print a number: %d\n", 25);
	printf("printf(), print a number: %d\n", 25);
}

int	main(void)
{
	ft_printf_test();
	return (0);
}

// Helper functions ///////////////////////////////////////////////////////////////////////
int	ft_format_check(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (specifier == 'd')
		return (ft_putnbr(va_arg(args, int)));
	return (0);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;
	
	if (!s)
		s = "(null)";
	count = 0;
	while (*s)
	{
		count += ft_putchar(*s);
		s++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int		count;
	
	count = 0;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_puthex(unsigned long long num)
{
	int 	count;
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	count = 0;

	if (num >= 16)
		count += ft_puthex(num / 16);
	count += ft_putchar(hex_digits[num % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;
	int res;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	count = 0;
	res = ft_putstr("0x");
	if (res < 0)
		return (-1);
	count += res;
	res = ft_puthex((unsigned long long)ptr);
	if (res < 0)
		return (-1);
	return (count);
}
