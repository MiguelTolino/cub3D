/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:47:44 by mmateo-t          #+#    #+#             */
/*   Updated: 2019/11/21 20:33:08 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	i = 0;
	ptr = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	while (i < n && *ptr && *ptr2)
	{
		if (*ptr != *ptr2)
		{
			return ((int)(*ptr - *ptr2));
		}
		ptr++;
		ptr2++;
		i++;
	}
	if (*ptr != *ptr2 && i != n)
		return (*ptr - *ptr2);
	return (0);
}
