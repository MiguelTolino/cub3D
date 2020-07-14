/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:59:56 by mmateo-t          #+#    #+#             */
/*   Updated: 2019/11/22 18:29:24 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	if (!(ptr = (char*)malloc(count * size)))
		return (0);
	i = 0;
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void*)ptr);
}
