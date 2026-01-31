#include "push_swap.h"

void	checker_read(t_stack *a, t_stack *b);
void	checker_print_result(t_stack *a, t_stack *b);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);

	/* Inicializa stacks (ajusta si tú tienes init_stack()) */
	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;

	/* PARSE: aquí tienes que llamar a tu función real */
	/* EJEMPLO:
		parse_arguments(&a, argc, argv);
	   o:
		parse_arguments(argc, argv, &a);
	*/
	parse_arguments(argc, argv, &a); /* <-- AJUSTA este nombre/firma */

	/* Ejecuta instrucciones leídas de stdin */
	checker_read(&a, &b);

	/* Resultado final */
	checker_print_result(&a, &b);

	/* Free */
	free_stack(&a);
	free_stack(&b);

	return (0);
}
