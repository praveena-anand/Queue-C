#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node;

node *front = 0, *rear = 0, *temp, *newnode;

void enqueue()
{
	newnode = (node *)malloc(sizeof(node));
	printf("Enter the Data : ");
	scanf("%d", &newnode -> data);
	newnode -> next = 0;
	
	if (front == 0)
		front = rear = newnode;
		
	else
	{
		rear -> next = newnode;
		rear = newnode;
	}
	
	newnode -> next = front;
}

void dequeue()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	temp = front;
	
	if (front == rear)
		front = rear = 0;
		
	else
	{
		front = front -> next;
		rear -> next = front;
	}
	
	printf("%d\n", temp -> data);
	
	free(temp);
}

void peek()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	printf("%d\n", front -> data);
}

void display()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	temp = front;
	
	while (temp -> next != front)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	printf("%d\n", temp -> data);
}

int isEmpty()
{
	return front == 0;
}

int main()
{
	do
	{
		int ch;
		printf("\nMAIN MENU - \n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		
		switch (ch)
		{
			case 1:
				enqueue();
				break;
				
			case 2:
				dequeue();
				break;
				
			case 3:
				peek();
				break;
			
			case 4:
				display();
				break;
				
			case 5:
				printf("Thank you!\n");
				return 0;
				
			default:
				printf("Invalid Input!\n");
		}
	}
	while (1);
}
