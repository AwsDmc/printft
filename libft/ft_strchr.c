/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaoni <abaoni@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:09:50 by abaoni            #+#    #+#             */
/*   Updated: 2025/12/09 20:57:23 by abaoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char) c;
	ptr = (unsigned char *)s;
	while (ptr[i])
	{
		if (ptr[i] == ch)
			return ((char *)&ptr[i]);
		i++;
	}
	if (ptr[i] == ch)
		return ((char *)&ptr[i]);
	return (NULL);
}
