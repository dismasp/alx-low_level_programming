#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"


/**
 * delete_all_nodes - delete all nodes
 *@head: Pointer to the head of the linked list
 * Return: Always 0.
 */

/* Call to delete all systems */
void delete_all_nodes(listint_t **head)
{
int i;
for (i = 0; *head != NULL; i++)
{
delete_nodeint_at_index(head, 0);
printf("-----------------\n");
print_listint(*head);
}
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
listint_t *head;

head = NULL;
add_nodeint_end(&head, 0);
add_nodeint_end(&head, 1);
add_nodeint_end(&head, 2);
add_nodeint_end(&head, 3);
add_nodeint_end(&head, 4);
add_nodeint_end(&head, 98);
add_nodeint_end(&head, 402);
add_nodeint_end(&head, 1024);
print_listint(head);
printf("-----------------\n");
delete_nodeint_at_index(&head, 5);
print_listint(head);
printf("-----------------\n");
delete_nodeint_at_index(&head, 0);
print_listint(head);
printf("-----------------\n");
delete_nodeint_at_index(&head, 0);
print_listint(head);
printf("-----------------\n");
delete_nodeint_at_index(&head, 0);
print_listint(head);
printf("-----------------\n");

/* Call to delete all systems */
delete_all_nodes(&head);
return (0);
}
