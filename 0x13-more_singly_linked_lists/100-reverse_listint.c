#include <stdio.h>
#include "lists.h"

/**
 * reverse_listint - Reverses a linked list
 * @head: Pointer to a pointer to the first node of the linked list
 *
 * Return: Pointer to the first node of the reversed linked list
 */

listint_t *reverse_listint(listint_t **head)
{
listint_t *prev = NULL, *current = *head, *next = NULL;

while (current)
{
next = current->next;
current->next = prev;
prev = current;
current = next;
}
*head = prev;
return (*head);
}

/**
 * reverse_list_helper - Helper function to reverse a linked list
 * @node: Pointer to the current node of the linked list
 * @new_head: Pointer to apointer to the first node of the reversed linked list
 */

void reverse_list_helper(listint_t *node, listint_t **new_head)
{
if (node == NULL)
return;

if (node->next == NULL)
{
*new_head = node;
return;
}

reverse_list_helper(node->next, new_head);
node->next->next = node;
node->next = NULL;
}
