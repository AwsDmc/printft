/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaoni <awos.baoni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:23:54 by abaoni            #+#    #+#             */
/*   Updated: 2026/02/19 13:39:49 by abaoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, const char format)
{
	int		len;
	char	*base;

	len = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		len += ft_print_hex(n / 16, format);
	len += ft_print_char(base[n % 16]);
	return (len);
}

static int	ft_print_ptr_hex(unsigned long long n)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		len += ft_print_ptr_hex(n / 16);
	len += ft_print_char(base[n % 16]);
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	int					len;
	unsigned long long	addr;

	len = 0;
	if (!ptr)
		return (ft_print_str("(nil)"));
	addr = (unsigned long long)ptr;
	len += ft_print_str("0x");
	len += ft_print_ptr_hex(addr);
	return (len);
}
