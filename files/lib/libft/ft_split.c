/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:59:33 by mmateo-t          #+#    #+#             */
/*   Updated: 2019/11/28 14:30:21 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_size(const char *s, char c)
{
	char	*tmp;
	char	**tab;
	int		i;

	i = 0;
	tmp = (char *)s;
	while (*tmp)
	{
		while (*tmp == c)
			tmp++;
		if (*tmp != '\0')
			i++;
		while (*tmp != c && *tmp)
			tmp++;
	}
	tab = (char**)malloc(sizeof(char*) * (i + 1));
	if (tab == NULL)
		return (NULL);
	tab[i] = NULL;
	return (tab);
}

static char		**ft_fill_tab(const char *s, char c)
{
	size_t	len;
	char	**tab;
	int		i;

	i = 0;
	len = 0;
	tab = ft_size(s, c);
	if (tab == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			while (s[len] != c && s[len])
				len++;
			tab[i++] = ft_substr(s, 0, len);
			s = s + len;
		}
		len = 0;
	}
	tab[i] = NULL;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = ft_fill_tab(s, c);
	return (tab);
}
