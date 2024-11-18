/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:24:58 by clu               #+#    #+#             */
/*   Updated: 2024/11/18 13:06:09 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	count;
	int	res;

	count = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	res = ft_putstr("0x");
	if (res < 0)
		return (-1);
	count += res;
	res = ft_puthex((unsigned long long int)ptr);
	if (res < 0)
		return (-1);
	count += res;
	return (count);
}
