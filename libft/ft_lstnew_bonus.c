/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:46:08 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/17 15:03:37 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*rep;

	rep = (t_list *)malloc(sizeof(t_list));
	if (!rep)
		return (NULL);
	rep->content = content;
	rep->next = NULL;
	return (rep);
}
