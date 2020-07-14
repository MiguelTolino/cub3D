/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:33:22 by mmateo-t          #+#    #+#             */
/*   Updated: 2019/11/21 20:22:49 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	i = 0;
	ptr = (unsigned char*)src;
	ptr2 = (unsigned char*)dst;
	while (i < n)
	{
		*ptr2 = *ptr;
		if (*ptr == (unsigned char)c)
		{
			dst += i + 1;
			return (dst);
		}
		i++;
		ptr++;
		ptr2++;
	}
	dst = NULL;
	return (dst);
}
