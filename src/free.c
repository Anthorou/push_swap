/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:30:12 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/27 18:31:23 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	list = NULL;
	return (list);
}

t_stack	*ft_free_stack(t_stack *stack)
{
	if (stack)
	{
		ft_free_list(stack->stack_a);
		ft_free_list(stack->stack_b);
	}
	free(stack);
	stack = NULL;
	return (stack);
}
