/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:15:10 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/23 15:33:41 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap(t_list **list, char c)
{
	t_list *third;
	t_list *first;
	t_list *second;
	
	if (ft_lstsize(*list) < 2)
		return (0);
	first = *list;
	second = first->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*list = second;
	write(1, "s", 1);
	write(1, &c, 1);
	write (1, "\n", 1);
	return (1);
}

int	ss(t_stack *stack)
{
	swap(&stack->stack_a, 'a');
	swap(&stack->stack_b, 'b');
	return (1);
}

int	push_a(t_stack *stack)
{
	t_list *first_b;

	if (!stack->stack_b)
		return (0);
	first_b = stack->stack_b;
	stack->stack_b = first_b->next;
	ft_lstadd_front(&stack->stack_a, first_b);
	write(1, "pa\n", 3);
	return (1);
}

int	push_b(t_stack *stack)
{
	t_list *first_a;

	if (!stack->stack_a)
		return (0);
	first_a = stack->stack_a;
	stack->stack_a = first_a->next;
	ft_lstadd_front(&stack->stack_b, first_a);
	write(1, "pb\n", 3);
	return (1);
}

int	rotate(t_list **list, char c)
{
	t_list *first;

	if (!list)
		return (0);
	first = *list;
	*list = first->next;
	first->next = NULL;
	ft_lstadd_back(list, first);
	write(1, "r", 1);
	write(1, &c, 1);
	write (1, "\n", 1);
	return (1);
}
