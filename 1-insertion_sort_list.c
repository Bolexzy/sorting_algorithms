#include "sort.h"

/**
* insertion_sort_list - Sorts doubly linked list using insertion sort.
* @list: A double pointer to the head of the list.
*
* Description: Loops through list and prints after each swap.
*               comparing the value of the current node with the
*                value of its predecessor.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		while ((prev = current->prev) != NULL && prev->n > current->n)
		{
			/* temp node to hold the current node */
			listint_t *temp = current;
			/* adjust adjacent nodes (current->next and prev)*/
			if (temp->next)
				temp->next->prev = current->prev;
			temp->prev->next = current->next;

			/* change current node to previous node to be swapped */
			current = current->prev;
			/* adjust temp node(next and prev) to point to previous node(curren)^ */
			temp->next = current;
			temp->prev = temp->prev->prev;
			/* adust current node (now moved behind) back to temp */
			current->prev = temp;
			/* adjust temp prev */
			if (temp->prev)
				temp->prev->next = temp;
			/* adjust head node */
			if (temp->prev == NULL)
				(*list) = temp;

			/* print list */
			print_list(*list);
			/* loop through predecessors */
			current = current->prev;
		}
		current = current->next;
	}
}
