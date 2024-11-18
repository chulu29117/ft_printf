/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:13:38 by clu               #+#    #+#             */
/*   Updated: 2024/11/18 12:24:28 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long num)
{
	int		count;
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count += ft_puthex(num / 16);
	count += ft_putchar(hex_digits[num % 16]);
	return (count);
}
