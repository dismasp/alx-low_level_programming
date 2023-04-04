#include <stdio.h>
#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to the head of the list
 * @n: value to be added to the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *node_mpya, *tempo_node;

node_mpya = malloc(sizeof(listint_t));
if (node_mpya == NULL)
return (NULL);

node_mpya->n = n;
node_mpya->next = NULL;

if (*head == NULL)
{
*head = node_mpya;
}
else
{
tempo_node = *head;
while (tempo_node->next != NULL)
tempo_node = tempo_node->next;
tempo_node->next = node_mpya;
}

return (node_mpya);
}
