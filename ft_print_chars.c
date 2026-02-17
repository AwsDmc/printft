/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaoni <awos.baoni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:10:01 by abaoni            #+#    #+#             */
/*   Updated: 2026/02/17 17:10:03 by abaoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_char(int c)
{
    ft_putchar_fd(c, 1);
    return (1);
}

int ft_print_str(char *str)
{
    if (!str)
    {
        ft_putstr_fd("(null)",1);
        return (6);
    }
    ft_putstr_fd(str, 1);
    return (ft_strlen(str));
}

int ft_print_percent(void)
{
    ft_putchar_fd('%', 1);
    return (1);
}
