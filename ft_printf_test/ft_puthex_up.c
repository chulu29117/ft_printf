/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:50:11 by clu               #+#    #+#             */
/*   Updated: 2024/11/18 12:53:51 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_up(unsigned int n)
{
	int		count;
	char	*hex_digits;

	hex_digits = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthex_up(n / 16);
	count += ft_putchar(hex_digits[n % 16]);
	return (count);
}
