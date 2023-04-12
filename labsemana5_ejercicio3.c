#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int data;
	struct node *next;
} Node;

void Push(Node **top, int da)
{
	Node *nuevito = (Node*)malloc(sizeof(Node));
	nuevito->data = da;
	nuevito->next = *top;
	
	*top = nuevito;
}

Node* Pop(Node **top)
{
	Node *popped = *top;
	
	if (popped->next != NULL)
	{
		*top = popped->next;
	}
	
	return popped;
}

Node* Peek(Node *top)
{
	return top;
}

void PrintNodes(Node *top)
{
	Node *current = top;
	
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


void FreeNodes(Node *top)
{
	Node *current = top;
	
	while (current != NULL)
	{
		Node *next = current->next;
		free(current);
		current = next;
	}
}

int main()
{
	Node *top = NULL;

	PrintNodes(top);
	
	Push(&top, 1);
	Push(&top, 5);
	Push(&top, 8);
	
	PrintNodes(top);
	
	Node *popping;
	
	popping = Pop(&top);
	if (popping != NULL)
	{
		printf("nodo sacado\n");
		printf("Data: %d\n\n", popping->data);
	}
		
	PrintNodes(top);
	
	Node *peeping;
	
	peeping = Peek(top);
	if (peeping != NULL)
	{
		printf("nodo superior\n");
		printf("Data: %d\n\n",peeping->data);
	}
	
	FreeNodes(top);
	
	return 0;
}
