#include "push_swap.h"

/* Permute first and second nodes positions*/
/* only if there are more than one element*/

int swap(t_list **stack)
{
    t_list *aux;
     
    if (ft_lstsize(*stack) < 2)
        return (0);
    aux = *stack;  //pointer to A
    *stack = aux->next; // pointer to B 
    aux->next = (*stack)->next; // A points to node B next (nodo 3)
    (*stack)->next = aux; //aux contains pointer to A
    return (1);
}