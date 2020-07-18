/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 01:10:21 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 01:11:30 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void		free_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

int			is_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int			check_len(char **aux, int num)
{
	int i;

	i = 0;
	while (aux[i] != NULL)
	{
		i++;
	}
	if (i != num)
	{
		throw_error("Error: Incorrect number of arguments");
	}
	return (i);
}

char		*pad_right(char padding, int len)
{
	int		i;
	char	*str;

	i = 0;
	if (!len)
		return (ft_strdup(""));
	str = (char*)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		str[i++] = padding;
	}
	str[i] = '\0';
	return (str);
}

char		**copy_matrix(int n_row, char **map)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = (char**)malloc((n_row + 1) * sizeof(char*));
	while (i < n_row)
	{
		matrix[i] = ft_strdup(map[i]);
		i++;
	}
	matrix[i] = '\0';
	return (matrix);
}
