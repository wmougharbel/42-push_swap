/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:07:42 by wmoughar          #+#    #+#             */
/*   Updated: 2023/04/18 14:07:42 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quicksort_three(t_stack *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		ft_sort_three(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			ft_sa(stack, USED);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				ft_sa(stack, USED);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = ft_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				ft_sa(stack, USED);
			else if (len++)
				ft_pa(stack, USED);
		}
	}
}

int	ft_sort_b_s(t_stack *s, int len)
{
	if (len == 1)
		ft_pa(s, USED);
	else if (len == 2)
	{
		if (s->b[0] < s->b[1])
			ft_sb(s, USED);
		while (len--)
			ft_pa(s, USED);
	}
	else if (len == 3)
	{
		while (len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 1 && s->a[0] > s->a[1])
				ft_sa(s, USED);
			else if (len == 1 || (len >= 2 && s->b[0] > s->b[1])
				|| (len == 3 && s->b[0] > s->b[2]))
				len = ft_push(s, len, 1);
			else
				ft_sb(s, USED);
		}
	}
	return (0);
}

int	ft_middle(int *pivot, int *stack, int size)
{
	int		*tmp_stack;
	int		i;

	tmp_stack = (int *)malloc(size * sizeof(int));
	if (!tmp_stack)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp_stack[i] = stack[i];
		i++;
	}
	ft_swap_sort(tmp_stack, size);
	*pivot = tmp_stack[size / 2];
	free(tmp_stack);
	return (1);
}

int	ft_quicksort_a(t_stack *stack, int len, int cnt)
{
	int	pivot;
	int	items;

	if (ft_issorted(stack->a, len, ASC) == 1)
		return (1);
	items = len;
	if (len <= 3)
	{
		ft_quicksort_three(stack, len);
		return (1);
	}
	if (!cnt && !ft_middle(&pivot, stack->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot && (len--))
			ft_pb(stack, USED);
		else if (++cnt)
			ft_ra(stack, USED);
	}
	while (items / 2 + items % 2 != stack->size_a && cnt--)
		ft_rra(stack, USED);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0)
		&& ft_quicksort_b(stack, items / 2, 0));
	return (1);
}

int	ft_quicksort_b(t_stack *stack, int len, int cnt)
{
	int	pivot;
	int	items;

	if (!cnt && ft_issorted(stack->b, len, DESC) == 1)
		while (len--)
			ft_pa(stack, USED);
	if (len <= 3)
	{
		ft_sort_b_s(stack, len);
		return (1);
	}
	items = len;
	if (!ft_middle(&pivot, stack->b, len))
		return (0);
	while (len != items / 2)
	{
		if (stack->b[0] >= pivot && len--)
			ft_pa(stack, USED);
		else if (++cnt)
			ft_rb(stack, USED);
	}
	while (items / 2 != stack->size_b && cnt--)
		ft_rrb(stack, USED);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0)
		&& ft_quicksort_b(stack, items / 2, 0));
}
