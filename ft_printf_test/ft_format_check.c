/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:03:14 by clu               #+#    #+#             */
/*   Updated: 2024/11/18 13:35:45 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Check the specifier and call the appropriate function //
int	ft_format_check(char specifier, va_list args)
{
	// Specifier 'c' - print character //
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	// Specifier 's' - print string //
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	// Specifier 'p' - void *pointer in hexadecimal format //
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));
	// Specifier 'd' or 'i' - print decimal (base 10) or int number //
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	// Specifier 'x' - print hexadecimal (base 16) lowercase //
	else if (specifier == 'x')
		return (ft_puthex_low(va_arg(args, unsigned int)));
	// Specifier 'X' - print hexadecimal (base 16) uppercase //
	else if (specifier == 'X')
		return (ft_puthex_up(va_arg(args, unsigned int)));
	// Specifier 'u' - print unsigned int //
	else if (specifier == 'u')
		return (ft_putnbr_i(va_arg(args, unsigned int)));
	// Specifier '%' - print percent sign //
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}
