/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:52:40 by ihashimo          #+#    #+#             */
/*   Updated: 2022/12/16 13:21:09 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

ssize_t	ft_utoa(unsigned long nbr, unsigned long n, char *asc)
{
	ssize_t		count;

	count = 0;
	if (nbr >= n)
		count += ft_utoa(nbr / n, n, asc);
	count += ft_putchar_std(asc[nbr % n]);
	return (count);
}

ssize_t	ft_putvoid_std(void *s)
{
	unsigned long	ucs;
	ssize_t			count;

	ucs = (unsigned long)s;
	count = ft_putstr_std("0x");
	if (count == -1)
		return (-1);
	return (count + ft_utoa(ucs, 16, "0123456789abcdef"));
}
