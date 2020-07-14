/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:17:09 by mmateo-t          #+#    #+#             */
/*   Updated: 2019/11/24 17:34:28 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strlength(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static	int		start(char *s1, char *set)
{
	size_t i;
	size_t j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (i);
}

static int		end(char *s1, char *set)
{
	size_t i;
	size_t j;

	i = ft_strlength(s1) - 1;
	while (i > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			break ;
		i--;
	}
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	count1;
	size_t	count2;
	char	*s2;

	if (!s1)
		return (NULL);
	i = 0;
	count1 = start((char*)s1, (char*)set);
	count2 = end((char*)s1, (char*)set);
	if (count1 == ft_strlength((char*)s1))
	{
		s2 = (char*)malloc(sizeof(char) * 1);
		s2[0] = '\0';
		return (s2);
	}
	else
		s2 = (char*)malloc(sizeof(char) * (count2 - count1 + 2));
	if (s2 == NULL)
		return (s2);
	i = 0;
	while (count1 <= count2)
		s2[i++] = s1[count1++];
	s2[i] = '\0';
	return (s2);
}
