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

Node* SearchNode(Node *head, int da)
{
	Node *current = head;
	
	while (current != NULL)
	{
		if (current->data == da)
		{
			printf("NODO ENCONTRADO\n");
			return current;
		}
		current = current->next;
	}
	
	printf("NODO NO EXISTENTE\n");
	return NULL;
}

void GetSize(Node *head)
{
	int tamano = 0;
	Node *current = head;
	
	while(current != NULL)
	{
		tamano++;
		current = current->next;
	}
	
	printf("TAMANO LISTA: %d\n",tamano);
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
	GetSize(head);
	
	AddNode(&head, 7);
	AddNode(&head, 10);
	AddNode(&head, 3);
	
	PrintNodes(head);
	
	Node *buscar;
	GetSize(head);
	
	buscar = SearchNode(head, 1);
	if (buscar != NULL)
		printf("%d\n",buscar->data);
		
	buscar = SearchNode(head, 3);
	if (buscar != NULL)
		printf("%d\n",buscar->data);
	
	FreeNodes(head);
		
	return 0;
}
