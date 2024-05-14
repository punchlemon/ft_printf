/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:29:32 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/23 08:11:44 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;

	ch = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
