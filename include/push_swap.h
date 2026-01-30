#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct	s_node
{
   int				value;
   int				index;
   struct s_node	*next;
   struct s_node	*prev;
}	t_node;

typedef struct	s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

/* ------- PARSING FUNCTIONS ------- */
int		is_valid_number(char *str);
long	safe_atoi(char *str, int *error);
int		has_duplicate(t_stack *a, int value);
void	parse_arguments(int argc, char **argv, t_stack *a);
void	assign_indexes(t_stack *a);


/* ------- STACK FUNCTIONS ------- */
t_node	*new_node(int value);
void	stack_add_bottom(t_stack *stack, t_node *new);
void	stack_add_top(t_stack *stack, t_node *new);
t_node	*stack_pop_top(t_stack *stack);
t_node  *stack_pop_bottom(t_stack *stack);
void	sort_stack(t_stack *a, t_stack *b);


/* ------- INSTRUCTIONS ------- */

/*SWAP*/
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

/*PUSH*/
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
/*ROTATE*/
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
/*REVERSE ROTATE*/
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);


/* ------- SORTING ALGORITHMS ------- */
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);
//void	radix_sort(t_stack *a, t_stack *b);
void	chunk_sort(t_stack *a, t_stack *b);





/* ------- UTILS ------- */
void	free_stack(t_stack *s);

/* ------- ERROR ------- */
void	error_exit(void);

#endif
