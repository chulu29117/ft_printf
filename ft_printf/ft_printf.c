/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:19:31 by clu               #+#    #+#             */
/*   Updated: 2024/11/15 11:37:22 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	ft_printf("This is a test for ft_printf(), let's print a number: %d", 25);
	return (0);
}