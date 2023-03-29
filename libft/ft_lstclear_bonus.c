/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:57:29 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/17 15:10:27 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*tmp;

	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = tmp->next;
		ft_lstdelone(tmp, (*del));
	}
	lst = NULL;
}
