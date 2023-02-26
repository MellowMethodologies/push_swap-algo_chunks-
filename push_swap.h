/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:45:53 by sbadr             #+#    #+#             */
/*   Updated: 2023/01/08 23:21:00 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct node {
	int			index;
	int			data;
	struct node	*next;
}t_stack;

typedef struct vars{
	int	pos;
	int	j;
	int	l;
	int	chunk;
	int	deep;
}t_vars;

void	free_lst(t_stack **stack);
void	doer(t_stack **head_a, t_stack **head_b, int ac);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*strrjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
void	error_print(void);
void	check_repeated(char **str, int size);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(int size, char **strs, char *sep);
t_stack	*push(t_stack *head, int data, int index);
t_stack	*push_back(t_stack *head, long data, int index);
t_stack	*ft_last(t_stack *lst);
t_stack	*pop(t_stack *head);
t_stack	*ft_last(t_stack *lst);
long	check_int(char *str);
size_t	ft_strlen(char *str);
int		ft_isdigit(int c);
long	ft_atoi(const char *str);
int		check_sorted(t_stack **a);
char	**ft_split(char *s, char c);
void	pa(t_stack **a, t_stack **b, int i);
void	pb(t_stack **a, t_stack **b, int i);
void	ra(t_stack **a, int i);
void	rb(t_stack **b, int i);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	sa(t_stack **head_a, int i);
int		check_it(size_t size, char **str);
void	sb(t_stack **head_b, int i);
void	rra(t_stack **head_a, int i);
void	rrb(t_stack **head_b, int i);

void	indexer(t_stack **a);
int		lst_size(t_stack *lst);
void	sorted(t_stack **a, t_stack **b, int chunk, int deep);
void	stacker(t_stack **a, t_stack **b, int size);
int		finder(t_stack **stack, int pos);
int		highest_index(t_stack *stack);
void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
t_stack	*node_position(t_stack **a, int index);
int		position(t_stack **a, int index);

#endif