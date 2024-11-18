/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:24:58 by clu               #+#    #+#             */
/*   Updated: 2024/11/18 11:28:47 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

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
	