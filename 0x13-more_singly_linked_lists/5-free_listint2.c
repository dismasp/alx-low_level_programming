#include <stdio.h>
#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL
 * @head: Pointer to pointer to the beginning of the list
 */
void free_listint2(listint_t **head)
{
listint_t *hivisasa;

if (head == NULL)
return;

while (*head != NULL)
{
hivisasa = *head;
*head = hivisasa->next;
free(hivisasa);
}

*head = NULL;
}
