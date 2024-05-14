/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:15:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/23 07:29:05 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (dst <= src)
		ft_memcpy(dst, src, n);
	else
	{
		while (n > 0)
		{
			dst_ptr[n - 1] = src_ptr[n - 1];
			n--;
		}
	}
	return (dst);
}
