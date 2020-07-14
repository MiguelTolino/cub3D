/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:58:14 by mmateo-t          #+#    #+#             */
/*   Updated: 2019/11/27 18:22:14 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *begin;

	begin = *lst;
	if (begin == NULL)
		*lst = new;
	else
	{
		while (begin->next)
			begin = begin->next;
		begin->next = new;
	}
}
