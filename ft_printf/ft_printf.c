/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:19:31 by clu               #+#    #+#             */
/*   Updated: 2024/11/15 12:24:32 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Prototypes //
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);

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
			if (str[i] == 'c')
				count += (char) ft_putchar_fd(va_arg(args, int), 1);
			else if (str[i] == 's')
				count += ft_putstr_fd(va_arg(args, char *), 1);
			else if (str[i] == 'd')
				count += ft_putnbr_fd(va_arg(args, int), 1);
		}
		else
			count += ft_putchar_fd(str[i], 1);
		i++;
	}	
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf("This is a test for ft_printf(), let's print a character: %c\n", 'A');
	ft_printf("This is a test for ft_printf(), let's print a string: %s\n", "Hello, world!");
	ft_printf("This is a test for ft_printf(), let's print a number: %d\n", 25);
	return (0);
}

// Helper functions ///////////////////////////////////////////////////////////////////////
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
