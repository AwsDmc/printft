/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaoni <awos.baoni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:36:41 by abaoni            #+#    #+#             */
/*   Updated: 2026/02/19 14:06:39 by abaoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_evaluator(va_list *args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_print_char(va_arg(*args, int));
	else if (format == 's')
		print_length += ft_print_str(va_arg(*args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(*args, void *));
	else if (format == 'd' || format == 'i')
		print_length += ft_print_nbr(va_arg(*args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(*args, unsigned int), format);
	else if (format == '%')
		print_length += ft_print_percent();
	return (print_length);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		print_length;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	print_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			print_length += ft_format_evaluator(&args, format[i + 1]);
			i++;
		}
		else
			print_length += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
