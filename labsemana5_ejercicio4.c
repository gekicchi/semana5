#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int data;
	struct node *next;
} Node;

void Enqueue(Node **head, int da)
{
	Node *nuevito = (Node*)malloc(sizeof(Node));
	nuevito->data = da;
	nuevito->next = NULL;
	
	if (*head == NULL)
	{
		*head = nuevito;
	}
	else
	{
		Node *current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = nuevito;
	}
}

Node* Dequeue(Node *head, Node **next)
{
	if (head != NULL)
	{
		Node *current = head;
		*next = current->next;
		current->next = NULL;
		return current;
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
			printf("Data: %d\n",current->data);
			
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

	PrintNodes(head);
	
	Push(&head, 1);
	Push(&head, 5);
	Push(&head, 8);
	
	PrintNodes(head);
	
	Node *popping;
	
	popping = Pop(&top);
	if (popping != NULL)
	{
		printf("nodo sacado\n");
		printf("Data: %d\n\n", popping->data);
	}
		
	PrintNodes(head);
	
	FreeNodes(head);
	
	return 0;
}
