#include <stdio.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list and returns its value.
 * @head: pointer to pointer to head node.
 *
 * Return: head node's value or 0 if list is empty.
 */
int pop_listint(listint_t **head)
{
int value;
listint_t *temp;

if (*head == NULL)
return (0);

value = (*head)->n;
temp = *head;
*head = (*head)->next;
free(temp);

return (value);
}
