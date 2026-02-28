/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaoni <awos.baoni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:36:41 by abaoni            #+#    #+#             */
/*   Updated: 2026/02/28 11:05:06 by abaoni           ###   ########.fr       */
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
	else
	{
		print_length += ft_print_percent();
		print_length += ft_print_char(format);
	}
	return (print_length);
}

static int	ft_parse_format(const char *format, va_list *args)
{
	int	i;
	int	print_length;

	i = 0;
	print_length = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (print_length + ft_print_percent());
			print_length += ft_format_evaluator(args, format[i + 1]);
			i++;
		}
		else
			print_length += ft_print_char(format[i]);
		i++;
	}
	return (print_length);
}

int	ft_printf(const char *format, ...)
{
	int		print_length;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	print_length = ft_parse_format(format, &args);
	va_end(args);
	return (print_length);
}
