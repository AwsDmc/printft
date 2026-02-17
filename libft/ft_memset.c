/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaoni <awos.baoni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:04:22 by abaoni            #+#    #+#             */
/*   Updated: 2025/12/05 18:22:52 by abaoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	size_t			i;
	unsigned char	*helper;
	unsigned char	ch;

	i = 0;
	helper = (unsigned char *)ptr;
	ch = (unsigned char)c;
	while (i < len)
	{
		helper[i] = ch;
		i++;
	}
	return (ptr);
}
