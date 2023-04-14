/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:34:15 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/30 14:30:52 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rr(t_stack *stack)
{
	rotate(&stack->stack_a, 'a');
	rotate(&stack->stack_b, 'b');
}

void	reverse_rotate(t_list **list, char c)
{
	t_list	*current;
	t_list	*check_last;
	t_list	*last;
	int		check;

	current = *list;
	check = 0;
	if (*list && (*list)->next)
	{
		while (!check)
		{
			if (current->next)
				check_last = current->next;
			if (!check_last->next)
				break ;
			current = current->next;
		}
		last = current->next;
		current->next = NULL;
		write(1, "rr", 2);
		write(1, &c, 1);
		write (1, "\n", 1);
		ft_lstadd_front(list, last);
	}
}

void	rrr(t_stack *stack)
{
	reverse_rotate(&stack->stack_a, 'a');
	reverse_rotate(&stack->stack_b, 'b');
}
