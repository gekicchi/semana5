#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int data;
	struct node *next;
} Node;

void AddNode(Node **head, int da)
{
	Node *nuevito = (Node*)malloc(sizeof(Node));
	nuevito->data = da;
	nuevito->next = NULL;
	Node *current = *head;
	
	if (current == NULL)
	{
		*head = nuevito;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		
		current->next = nuevito;
	}
}

void PrintNodes(Node *head)
{
	Node *current = head;
	
	if (current == NULL)
	{
		printf("LISTA VACIA\n");
	}
	else
	{
		while (current != NULL)
		{
			printf("Data: %d\n\n",current->data);
			
			current = current->next;
		}
	}
}

void FreeNodes(Node *head)
{
	Node *current = head;
	
	while (current != NULL)
	{
		Node *next = current->next;
		free(current);
		current = next;
	}
}

int main()
{	
	Node *head = NULL;
	
	PrintNodes(head); // LISTA VACIA
	
	AddNode(&head, 1); // añadido
	AddNode(&head, 5); // añadido
	AddNode(&head, 9); // añadido
	
	PrintNodes(head); // 1, 5, 9
	
	FreeNodes(head);
	
	return 0;
}
