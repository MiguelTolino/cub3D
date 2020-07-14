/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:14:24 by mmateo-t          #+#    #+#             */
/*   Updated: 2019/11/21 20:21:41 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	unsigned const char		*ptr;
	unsigned const char		*ptr2;

	i = 0;
	ptr = (unsigned const char*)s1;
	ptr2 = (unsigned const char*)s2;
	while (i < n)
	{
		if (*ptr != *ptr2)
		{
			return ((int)(*ptr - *ptr2));
		}
		ptr++;
		ptr2++;
		i++;
	}
	return (0);
}
