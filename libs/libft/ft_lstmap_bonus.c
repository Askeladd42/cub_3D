/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:38:02 by plam              #+#    #+#             */
/*   Updated: 2021/01/07 10:31:10 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_list(t_list *n_stock, void (*del)(void *))
{
	t_list	*tmp;

	if (n_stock != NULL && del)
	{
		tmp = n_stock;
		while (tmp)
		{
			del((n_stock)->content);
			tmp = (n_stock)->next;
			free(n_stock);
			n_stock = tmp;
		}
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*n_stock;

	n_stock = NULL;
	if (lst && f)
	{
		while (lst != NULL)
		{
			n_lst = ft_lstnew(f(lst->content));
			if (n_lst == NULL)
			{
				free_list(n_stock, del);
				return (NULL);
			}
			ft_lstadd_back(&n_stock, n_lst);
			lst = lst->next;
		}
	}
	return (n_stock);
}
