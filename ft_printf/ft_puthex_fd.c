/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:13:38 by clu               #+#    #+#             */
/*   Updated: 2024/11/15 17:20:08 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

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
