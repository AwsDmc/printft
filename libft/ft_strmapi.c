/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaoni <awos.baoni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:28:27 by abaoni            #+#    #+#             */
/*   Updated: 2025/12/15 18:43:23 by abaoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*applied;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	applied = malloc(len + 1);
	if (!applied)
		return (NULL);
	i = 0;
	while (s[i])
	{
		applied[i] = f(i, s[i]);
		i++;
	}
	applied[i] = '\0';
	return (applied);
}
