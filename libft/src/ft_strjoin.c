/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:23:02 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/23 07:52:50 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*p;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1, s1_len);
	ft_memcpy(p + s1_len, s2, s2_len);
	p[s1_len + s2_len] = '\0';
	return (p);
}
