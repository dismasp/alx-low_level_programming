#include <stdio.h>
#include "lists.h"

/**
 * free_listint - Frees a linked list
 * @head: pointer to the head of the list
 *
 * Return: void
 */
void free_listint(listint_t *head)
{
listint_t *hivisasa;

while (head)
{
hivisasa = head;
head = head->next;
free(hivisasa);
}
}
