/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:03:14 by clu               #+#    #+#             */
/*   Updated: 2024/11/15 17:13:24 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_format_check(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (specifier == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (specifier == 'p')
		return (ft_putptr_fd(va_arg(args, void *), 1));
	else if (specifier == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	return (0);
}
