#include <stdio.h>
#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: double pointer to the head of the list
 * @n: integer value to be stored in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *dismas_node;

/* Allocate memory for new node */
dismas_node = malloc(sizeof(listint_t));
if (dismas_node == NULL)
return (NULL);

/* Set value of new node */
dismas_node->n = n;

/* Set next of new node to current head */
dismas_node->next = *head;

/* Set head to new node */
*head = dismas_node;

return (dismas_node);
}
