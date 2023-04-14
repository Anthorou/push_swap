/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:54:58 by aroussea          #+#    #+#             */
/*   Updated: 2023/04/13 17:15:11 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	i = 0;
	if (argc > 1)
	{
		stack = args_parsing(argc, argv);
		if (!stack)
		{
			stack = ft_free_stack(stack);
			write(2, "Error\n", 6);
			return (1);
		}
		stack->stack_b = NULL;
		push_swap(stack);
		stack = ft_free_stack(stack);
		return (0);
	}
	return (1);
}
