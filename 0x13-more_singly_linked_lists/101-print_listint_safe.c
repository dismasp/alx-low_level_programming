#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a linked list of integers
 * @head: pointer to the head node of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *slow = head, *fast = head;
size_t count = 0;

while (fast && fast->next)
{
printf("[%p] %d\n", (void *)slow, slow->n);
slow = slow->next;
fast = fast->next->next;

if (slow == fast)
{
printf("[%p] %d\n", (void *)slow, slow->n);
printf("-> [%p] %d\n", (void *)fast->next, fast->next->n);
exit(98);
}
count++;
}

if (slow)
{
printf("[%p] %d\n", (void *)slow, slow->n);
count++;
}

return (count);
}
