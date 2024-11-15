/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:19:31 by clu               #+#    #+#             */
/*   Updated: 2024/11/15 17:20:37 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Prototypes //
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_format_check(char specifier, va_list args);

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
			count += ft_putchar_fd(str[i], 1);
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
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (specifier == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (specifier == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	return (0);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	count;
	
	if (!s)
		s = "(null)";
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
		count++;
	}
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	int		count;
	
	count = 0;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_fd(n / 10, fd);
	count += ft_putchar_fd(n % 10 + '0', fd);
	return (count);
}

int	ft_puthex_fd(unsigned long long num, int fd)
{
	int count;
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	count = 0;

	if (num >= 16)
		count += ft_puthex_fd(num / 16, fd);
	count += ft_putchar_fd(hex_digits[num % 16], fd);
	return (count);
}


