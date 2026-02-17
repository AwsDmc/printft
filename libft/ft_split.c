/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaoni <awos.baoni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:13:59 by abaoni            #+#    #+#             */
/*   Updated: 2025/12/13 19:09:19 by abaoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	word_counter(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static	char	*word_copy(char const *s, size_t start, char c)
{
	size_t	len;

	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	return (ft_substr(s, start, len));
}

static	void	free_all(char **arr, size_t used)
{
	while (used > 0)
	{
		free(arr[used - 1]);
		used--;
	}
	free(arr);
}

static	int	fill(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j] = word_copy(s, i, c);
			if (!result[j])
				return (j);
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	result[j] = NULL;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		fail;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) *(word_counter(s, c) + 1));
	if (!result)
		return (NULL);
	fail = fill(result, s, c);
	if (fail != -1)
	{
		free_all(result, fail);
		return (NULL);
	}
	return (result);
}
