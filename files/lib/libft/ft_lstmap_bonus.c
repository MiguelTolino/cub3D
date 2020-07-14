/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:05:59 by mmateo-t          #+#    #+#             */
/*   Updated: 2019/11/28 14:25:11 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new;
	t_list	*aux;

	if (lst)
	{
		new = ft_lstnew(f(lst->content));
		aux = new;
		while (lst->next)
		{
			lst = lst->next;
			if (!(new->next = ft_lstnew(f(lst->content))))
			{
				del(new->next);
				free(new->next);
				return (NULL);
			}
			new = new->next;
		}
		return (aux);
	}
	return (NULL);
}
