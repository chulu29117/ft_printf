/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:24:58 by clu               #+#    #+#             */
/*   Updated: 2024/11/15 17:26:10 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_putptr_fd(char **ptr, int fd)
{
	int	count;

	count = 0;
	ft_putstr_fd("0x", fd);
	count += 2;
	count += ft_puthex_fd((unsigned long long)ptr, fd);
	return (count);
}
	