#include "sort.h"

/**
* swap_nodes - Swaps two adjacent nodes in a
*				listint_t doubly-linked list of ints.
* @left_node: A pointer to the Left adjacent node.
* @right_node: A pointer to the right adjacent node.
* @list: A double pointer to head of list.
*/
void swap_nodes(listint_t **list, listint_t *left_node, listint_t *right_node)
{
	listint_t *temp = left_node->prev;

	/* adjust the adjacent nodes of left_node */
	if (temp)
		temp->next = right_node;
	right_node->prev = temp;

	/* adjust pointers of left_node */
	left_node->next = right_node->next;
	left_node->prev = right_node;

	/* adjust rightnode pointer to left node */
	right_node->next = left_node;

	/* adjust new node infronf of left_node back to it */
	if (left_node->next != NULL)
		left_node->next->prev = left_node;
	/* set the head pointer */
	if (right_node->prev == NULL)
		(*list) = right_node;
	print_list(*list);
}

/**
* cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
*                      ascending order using the cocktail shaker algorithm.
* @list: A pointer to the head of a listint_t doubly-linked list.
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	bool swapped = true;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = false;

		current = (*list);
		while (current->next != NULL)
		{
			if (current->next)
			{
				if (current->n > current->next->n)
				{
					swap_nodes(list, current, current->next);
					swapped = true;
				}
				else
					current = current->next;
			}
		}

		if (!swapped)
			break;

		current = current->prev;
		while (current->prev != NULL)
		{
			if (current->prev->n > current->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = true;
			}
			else
				current = current->prev;
		}
	}
}
