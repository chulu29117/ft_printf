/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_low.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:23:41 by clu               #+#    #+#             */
/*   Updated: 2024/11/18 14:00:04 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print hexadecimal number in lowercase //
int	ft_puthex_low(unsigned int n)
{
	int		count;
	char	*hex_digits;	// array of hexadecimal digits

	hex_digits = "0123456789abcdef";
	count = 0;
	// if number is greater than 16, divide by 16 and call function recursively
	if (n >= 16)
		count += ft_puthex_low(n / 16);			// Use recursive to print the number
	count += ft_putchar(hex_digits[n % 16]);	// Print the hexadecimal digit
	return (count);
}
