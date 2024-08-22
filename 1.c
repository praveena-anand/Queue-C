#include <stdio.h>
#define MAX 5

int queue[MAX], rear = -1, front = -1, element, i;

int isFull()
{
	if (rear == MAX -1)
		return 1;
	return 0;
}

int isEmpty()
{
	if (front == -1 && rear == -1)
		return 1;
	return 0;
}

void enqueue()
{
	if (isFull())
	{
		printf("Queue Overflow!\n");
		return;
	}
	
	printf("Enter the Element : ");
	scanf("%d", &element);
	
	if (front == -1 && rear == -1)
		front = rear = 0;
	else
		rear++;
	queue[rear] = element;
	
	printf("Element Enqueued Successfully!\n");
}

void dequeue()
{
	if (isEmpty())
	{
		printf("Queue Underflow!\n");
		return;
	}
	
	printf("Dequeued Element is %d.\n", queue[front]);
	
	if (front == rear)
		front = rear = 0;
	else
		front++;
}

void peek()
{
	if (isEmpty())
	{
		printf("Queue Underflow!\n");
		return;
	}
	
	printf("Peek Element is %d.\n", queue[front]);
}

void display()
{
	printf("The Element are,\n");
	for (i = front; i <= rear; i++)
		printf("%d\n", queue[i]);
	printf("\n");
}

int main()
{
	do
	{
		int ch;
		printf("Main Menu - \n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
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
	
	return 0;
}
