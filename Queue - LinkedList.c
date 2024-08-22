#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
} node;

node *rear, *front, *newnode, *temp;
node *rear, *front = 0;


void enqueue()
{
	newnode = (node *)malloc(sizeof(node));
	printf("Enter the Element : ");
	scanf("%d", &newnode -> data);
	newnode -> link = 0;
	
	if (front == 0)
		front = rear = newnode;
	else
	{
		rear -> link = newnode;
		rear = newnode;
	}
	
	printf("Element Enqueued Successfully!\n");
}

int isEmpty()
{
	if (front == 0)
		return 1;
	return 0;
}

void display()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	temp = front;

	printf("The Elements are : \n");
	while (temp != 0)
	{
		printf("%d\t", temp -> data);
		temp = temp -> link;
	}
	printf("\n");
}

void dequeue()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	temp = front;
	
	printf("The Dequeued Element is : %d.\n", temp -> data);
	front = front -> link;
	free(temp);
}

void peek()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	printf("The Peek Element is : %d.\n", front -> data);
}

int main()
{
	do
	{
		int ch;
		
		printf("\nMain Menu - \n1. Enqueue\n2. Display\n3. Dequeue\n4. Peek\n5. Exit\n");
		printf("Enter you choice : ");
		scanf("%d", &ch);
		
		switch (ch)
		{
			case 1:
				enqueue();
				break;
				
			case 2:
				display();
				break;
				
			case 3:
				dequeue();
				break;
				
			case 4:
				peek();
				break;
				
			case 5:
				printf("Thank you!\n");
				return 0;
				
			default:
				printf("Invalid Input!\n");
		}
	}
	while (1);
	
	return 0;
}

