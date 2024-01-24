#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two adjacent elements of a doubly linked list
 * @head: Pointer to the doubly linked list
 * @first: First element to be swapped
 * @second: Second element to be swapped
 *
 * Return: Doubly linked list with swapped elements
*/
void swap(listint_t **head, listint_t *first, listint_t *second)
{
	if (*head == NULL)
		return;

	if (first->prev == NULL)
	{
		first->next = second->next;
		if (first->next != NULL)
			first->next->prev = first;
		second->next = first;
		first->prev = second;
		second->prev = NULL;
		*head = second;
	}
	else
	{
		second->prev = first->prev;
		first->next = second->next;
		second->next = first;
		first->prev = second;
		if (first->next != NULL)
			first->next->prev = first;
		if (second->prev != NULL)
			second->prev->next = second;
	}
}

/**
 * insertion_sort_list - Insertion sort on a doubly linked list
 * @list: Pointer to the head of the linked list
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	do {
		if (current->n > current->next->n)
		{
			swap(list, current, current->next);
			print_list(*list);
			current = *list;
		}
		else
			current = current->next;
	} while (current->next != NULL);
}
