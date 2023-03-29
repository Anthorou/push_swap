/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:34:15 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/23 15:35:17 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rr(t_stack *stack)
{
	if (!rotate(&stack->stack_a, 'a'))
		return (0);
	if (!rotate(&stack->stack_b, 'b'))
		return (0);
	return (1);
}

int	reverse_rotate(t_list **list, char c)
{
	t_list *current;
	t_list *check_last;
	t_list *last;
	int check;

	current = *list;
	check = 0;
	if (*list && (*list)->next)
	{
		while (!check)
		{
			if (current->next)
				check_last = current->next;
			if (!check_last->next)
				break;
			current = current->next;
		}
		last = current->next;
		current->next = NULL;
		write(1, "rr", 2);
		write(1, &c, 1);
		write (1, "\n", 1);
		ft_lstadd_front(list, last);
		return (1);
	}
	return (0);
}

int	rrr(t_stack *stack)
{
	if (!reverse_rotate(&stack->stack_a, 'a'))
		return (0);
	if (!reverse_rotate(&stack->stack_b, 'b'))
		return (0);
	return (1);
}
