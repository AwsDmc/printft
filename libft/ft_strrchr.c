/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaoni <abaoni@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:04:51 by abaoni            #+#    #+#             */
/*   Updated: 2025/12/09 20:47:05 by abaoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			len;

	ptr = (unsigned char *) s;
	ch = (unsigned char) c;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (ptr[len] == ch)
			return ((char *)&ptr[len]);
		len--;
	}
	if (ptr[len] == ch)
		return ((char *)&ptr[len]);
	return (NULL);
}
