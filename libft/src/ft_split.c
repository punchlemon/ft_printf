/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 07:23:39 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/23 10:20:34 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freemem(char ***p, int last_index)
{
	int	i;

	i = 0;
	while (i < last_index)
	{
		free((*p)[i]);
		(*p)[i] = NULL;
		i++;
	}
	free(*p);
	*p = NULL;
	return (NULL);
}

static int	ft_countword(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_storeword(char const **s, char c)
{
	char	*temp;
	int		len;

	len = 0;
	while (**s != '\0' && **s != c)
	{
		len++;
		(*s)++;
	}
	temp = malloc((len + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	ft_strlcpy(temp, *s - len, len + 1);
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	char	**buff;
	int		wordcount;
	int		i;

	if (s == NULL)
		return (NULL);
	wordcount = ft_countword(s, c);
	buff = malloc((wordcount + 1) * sizeof(char *));
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			buff[i] = ft_storeword(&s, c);
			if (buff[i] == NULL)
				return (ft_freemem(&buff, i));
			i++;
		}
	}
	buff[i] = NULL;
	return (buff);
}
