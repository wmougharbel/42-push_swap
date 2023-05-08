/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:47:37 by wmoughar          #+#    #+#             */
/*   Updated: 2023/04/12 13:47:37 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//if stack A is not empty
//the top element of stack b is now the same as the top of stack a
//index 0 is the top element of the stack
//remove the pushed element from stack a

void	ft_pb(t_stack *stack, int print)
{
	int	i;

	if (stack->size_a)
	{
		stack->size_b++;
		i = stack->size_b;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = stack->a[0];
		i = -1;
		stack->size_a--;
		while (++i < stack->size_a)
			stack->a[i] = stack->a[i + 1];
		if (print == USED)
			ft_printf("pb\n");
	}
	else
	{
		if (print == UNUSED)
			ft_printf("Nothing done. Stack A is empty.\n");
		return ;
	}
}

void	ft_pa(t_stack *stack, int print)
{
	int	i;

	if (stack->size_b)
	{
		stack->size_a++;
		i = stack->size_a;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = stack->b[0];
		i = -1;
		stack->size_b--;
		while (++i < stack->size_b)
			stack->b[i] = stack->b[i + 1];
		if (print == USED)
			ft_printf("pa\n");
	}
	else
	{
		if (print == UNUSED)
			ft_printf("Nothing done. Stack B is empty.\n");
		return ;
	}
}
