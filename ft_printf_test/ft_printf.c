/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:19:31 by clu               #+#    #+#             */
/*   Updated: 2024/11/18 12:23:56 by clu              ###   ########.fr       */
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

// Test %c character with ft_printf() and printf() //
void	ft_printf_test_char(void)
{
	printf("This test will print characters\n");
	
	int ret1 = 0;
	int ret2 = 0;

	ret1 = ft_printf("ft_printf(), print 'A': %c\n", 'A');
	ret2 = printf("printf(), print 'A': %c\n", 'A');
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print 65 ('A'): %c\n", 65);
	ret2 = printf("printf(), print 65 ('A'): %c\n", 65);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	printf("----------------------------------------------\n");
}

// Test %s string with ft_printf() and printf() //
void	ft_printf_test_string(void)
{
	printf("This test will print strings\n");
	
	int ret1 = 0;
	int ret2 = 0;

	ret1 = ft_printf("ft_printf(), print ""Hello, world!"": %s\n", "Hello, world!");
	ret2 = printf("printf(), print ""Hello, world!"": %s\n", "Hello, world!");
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print ""(null)"": %s\n", "(null)");
	ret2 = printf("printf(), print ""(null)"": %s\n", "(null)");
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	printf("----------------------------------------------\n");

}

// Test %p void * pointer with ft_printf() and printf() //
void	ft_printf_test_pointer(void)
{
	printf("This test will print the address of a pointer\n");
	
	int ret1 = 0;
	int ret2 = 0;

	ret1 = ft_printf("ft_printf(), print &ft_putptr: %p\n", &ft_putptr);
	ret2 = printf("printf(), print &ft_putptr: %p\n", &ft_putptr);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print &ft_putchar: %p\n", &ft_putchar);
	ret2 = printf("printf(), print &ft_putchar: %p\n", &ft_putchar);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print NULL pointer: %p\n", NULL);
	ret2 = printf("printf(), print NULL pointer: %p\n", NULL);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	printf("----------------------------------------------\n");
}

// Test %d decimal (base 10) with ft_printf() and printf() //
void	ft_printf_test_decimal(void)
{
	printf("This test will print decimal (base 10) numbers\n");
	
	int ret1 = 0;
	int ret2 = 0;

	ret1 = ft_printf("ft_printf(), print 12: %d\n", 12);
	ret2 = printf("printf(), print 12: %d\n", 12);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print INT_MIN: %d\n", INT_MIN);
	ret2 = printf("printf(), print INT_MIN: %d\n", INT_MIN);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	printf("----------------------------------------------\n");
}

// Test %i unsigned decimal (base 10) with ft_printf() and printf() //
void	ft_printf_test_integer(void)
{
	printf("This test will print integer (base 10) numbers\n");

	int ret1 = 0;
	int ret2 = 0;

	ret1 = ft_printf("ft_printf(), print 123456: %i\n", 123456);
	ret2 = printf("printf(), print 123456: %i\n", 123456);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print -123456: %i\n", -123456);
	ret2 = printf("printf(), print -123456: %i\n", -123456);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print 0123456: %i\n", 0123456);
	ret2 = printf("printf(), print 0123456: %i\n", 0123456);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	printf("----------------------------------------------\n");
}

// Test %u with ft_printf() and printf() //
void	ft_printf_test_unsigned(void)
{
	printf("This test will print unsigned decimal (base 10) numbers\n");
	int ret1 = 0;
	int ret2 = 0;

	ret1 = ft_printf("ft_printf(), print 123456: %u\n", 123456);
	ret2 = printf("printf(), print 123456: %u\n", 123456);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print 0: %u\n", 0);
	ret2 = printf("printf(), print 0: %u\n", 0);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	printf("----------------------------------------------\n");
}

// Test %x hexadecimal (base 16) lowercase with ft_printf() and printf() //
void	ft_printf_test_hexlower(void)
{
	printf("This test will print hexadecimal (base 16) lowercase numbers\n");
	int ret1 = 0;
	int ret2 = 0;

	ret1 = ft_printf("ft_printf(), print 255: %x\n", 255);
	ret2 = printf("printf(), print 255: %x\n", 255);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print 0: %x\n", 0);
	ret2 = printf("printf(), print 0: %x\n", 0);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	printf("----------------------------------------------\n");
}
// Test %X hexadecimal (base 16) uppercase with ft_printf() and printf() //
void	ft_printf_test_hex_upper(void)
{
	printf("This test will print hexadecimal (base 16) uppercase numbers\n");
	
	int ret1 = 0;
	int ret2 = 0;

	ret1 = ft_printf("ft_printf(), print 255: %X\n", 255);
	ret2 = printf("printf(), print 255: %X\n", 255);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print 0: %X\n", 0);
	ret2 = printf("printf(), print 0: %X\n", 0);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	printf("----------------------------------------------\n");
}

// Test %% percent sign with ft_printf() and printf() //
void	ft_printf_test_percent(void)
{
	printf("This test will print percent sign\n");
	
	int ret1 = 0;
	int ret2 = 0;

	ret1 = ft_printf("ft_printf(), print '%%': %%\n");
	ret2 = printf("printf(), print '%%': %%\n");
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	printf("----------------------------------------------\n");
}


int	main(void)
{
	ft_printf_test_char();
	ft_printf_test_string();
	ft_printf_test_pointer();
	ft_printf_test_decimal();
	ft_printf_test_integer();
	ft_printf_test_unsigned();
	ft_printf_test_hexlower();
	ft_printf_test_hex_upper();
	ft_printf_test_percent();
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
		return (ft_putptr(va_arg(args, char **)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_puthex(va_arg(args, unsigned long long int)));
	else if (specifier == 'X')
		return (ft_puthex(va_arg(args, unsigned long long int)));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

// print char //
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

// print string //
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

// print int //
int	ft_putnbr(int n)
{
	int		count;
	
	count = 0;
	if (n == INT_MIN)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
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

// print hexidecimal //
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

// print pointer address //
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
	count += res;
	return (count);
}
