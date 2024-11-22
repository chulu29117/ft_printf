/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:19:31 by clu               #+#    #+#             */
/*   Updated: 2024/11/22 16:44:16 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr(const char *s, int c);

// ft_printf() ///////////////////////////////////////////////////////////////////////
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
			// Check if the format specifier is valid.
			if (str[i + 1] == '\0' || !ft_strchr("cspdiuxX%", str[i + 1]))
				return (va_end(args), -1);	// Return -1 if the format specifier is invalid.
			// Check if the format specifier is valid and call the format check function.
			else if (ft_strchr("cspdiuxX%", str[i + 1]))
				count += ft_format_check(str[++i], args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// ft_strchr to find the specifier in the format string //
static char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			return ((char *) & s[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *) & s[i]);
	return (0);
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
	ret2 = printf("   printf(), print 'A': %c\n", 'A');
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print 65 ('A'): %c\n", 65);
	ret2 = printf("   printf(), print 65 ('A'): %c\n", 65);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("ft_printf(), print special characters: %c%c %c\n", '!', '@', '#');
	ret2 = printf("   printf(), print special characters: %c%c %c\n", '!', '@', '#');
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	printf("----------------------------------------------\n");
}

// Test %s string with ft_printf() and printf() //
void	ft_printf_test_string(void)
{
	printf("This test will print strings\n");
	
	int ret1 = 0;
	int ret2 = 0;
	char	*str;

	ret1 = ft_printf("ft_printf(), print ""Hello, world!"": %s\n", "Hello, world!");
	ret2 = printf("   printf(), print ""Hello, world!"": %s\n", "Hello, world!");
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print ""Empty string"": %s\n", "");
	ret2 = printf("   printf(), print ""Empty string"": %s\n", "");
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	
	str = NULL;
	ret1 = ft_printf("ft_printf(), print a NULL string: %s\n", str);
	ret2 = printf("   printf(), print a NULL string: %s\n", str);
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
	ret2 = printf("   printf(), print &ft_putptr: %p\n", &ft_putptr);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print &ft_putchar: %p\n", &ft_putchar);
	ret2 = printf("   printf(), print &ft_putchar: %p\n", &ft_putchar);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print NULL pointer: %p\n", NULL);
	ret2 = printf("   printf(), print NULL pointer: %p\n", NULL);
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
	ret2 = printf("   printf(), print 12: %d\n", 12);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print INT_MIN: %d\n", INT_MIN);
	ret2 = printf("   printf(), print INT_MIN: %d\n", INT_MIN);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print INT_MAX: %d\n", INT_MAX);
	ret2 = printf("   printf(), print INT_MAX: %d\n", INT_MAX);
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
	ret2 = printf("   printf(), print 123456: %i\n", 123456);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print INT_MIN: %i\n", INT_MIN);
	ret2 = printf("   printf(), print INT_MIN: %i\n", INT_MIN);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print INT_MAX: %i\n", INT_MAX);
	ret2 = printf("   printf(), print INT_MAX: %i\n", INT_MAX);
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
	ret2 = printf("   printf(), print 123456: %u\n", 123456);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print 0: %u\n", -12345u);
	ret2 = printf("   printf(), print 0: %u\n", -12345u);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	printf("----------------------------------------------\n");
}

// Test %x hexadecimal (base 16) lowercase with ft_printf() and printf() //
void	ft_printf_test_hex_lower(void)
{
	printf("This test will print hexadecimal (base 16) lowercase numbers\n");
	int ret1 = 0;
	int ret2 = 0;

	ret1 = ft_printf("ft_printf(), print 15: %x\n", 15);
	ret2 = printf("   printf(), print 15: %x\n", 15);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print 0x1234abcdu: %x\n", 0x1234abcdu);
	ret2 = printf("   printf(), print 0x1234abcdu: %x\n", 0x1234abcdu);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print -0x1234abcdu: %x\n", -0x1234abcdu);
	ret2 = printf("   printf(), print -0x1234abcdu: %x\n", -0x1234abcdu);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	printf("----------------------------------------------\n");
}
// Test %X hexadecimal (base 16) uppercase with ft_printf() and printf() //
void	ft_printf_test_hex_upper(void)
{
	printf("This test will print hexadecimal (base 16) uppercase numbers\n");
	int ret1 = 0;
	int ret2 = 0;

	ret1 = ft_printf("ft_printf(), print 15: %X\n", 15);
	ret2 = printf("   printf(), print 15: %X\n", 15);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print 0x1234abcdu: %X\n", 0x1234abcdu);
	ret2 = printf("   printf(), print 0x1234abcdu: %X\n", 0x1234abcdu);
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	ret1 = ft_printf("ft_printf(), print -0x1234abcdu: %X\n", -0x1234abcdu);
	ret2 = printf("   printf(), print -0x1234abcdu: %X\n", -0x1234abcdu);
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
	ret2 = printf("   printf(), print '%%': %%\n");
	printf("Return value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);

	// ret1 = ft_printf("ft_printf(), print %");
	// ret2 = printf("   printf(), print %");
	// printf("\nReturn value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
	
	// ret1 = ft_printf("ft_printf(), print '%%' invalid: %  q");
	// ret2 = printf("   printf(), print '%%' invalid: %  q");
	// printf("\nReturn value: ft_printf() = %d / printf() = %d\n\n", ret1, ret2);
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
	ft_printf_test_hex_lower();
	ft_printf_test_hex_upper();
	ft_printf_test_percent();
	return (0);
}
