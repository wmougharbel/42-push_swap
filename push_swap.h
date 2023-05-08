/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:35:57 by wmoughar          #+#    #+#             */
/*   Updated: 2023/04/11 13:35:57 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

# define ASC 0
# define DESC 1
# define USED 0
# define UNUSED 1

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

//program
void	ft_push_swap(char **argv);

//utils
void	ft_error(int *stack);
void	check_doubles(int *stack, int size);
int		ft_atoi2(char *nptr, int *stack);
int		ft_issorted(int *stack, int size, int order);
int		ft_strlen2(char **argv);

//swap
void	ft_sa(t_stack *stack, int status);
void	ft_sb(t_stack *stack, int status);
void	ft_ss(t_stack *stack, int status);

//push
void	ft_pb(t_stack *stack, int status);
void	ft_pa(t_stack *stack, int status);

//rotate
void	ft_ra(t_stack *stack, int status);
void	ft_rb(t_stack *stack, int status);
void	ft_rr(t_stack *stack, int status);

//reverse rotate
void	ft_rra(t_stack *stack, int status);
void	ft_rrb(t_stack *stack, int status);
void	ft_rrr(t_stack *stack, int status);

//sorting
void	ft_swap_sort(int *tmp_stack, int size);
void	ft_sort_three(t_stack *s);
int		ft_sort(t_stack *stack, int size);
int		ft_push(t_stack *stack, int len, int op);
void	ft_quicksort_three(t_stack *stack, int len);
int		ft_sort_b_s(t_stack *s, int len);
int		ft_middle(int *pivot, int *stack, int size);
int		ft_quicksort_a(t_stack *stack, int len, int count);
int		ft_quicksort_b(t_stack *stack, int len, int count);

#endif
