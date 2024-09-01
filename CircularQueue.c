#include <stdio.h>
#define N 5

int queue[N], front = -1, rear = -1;

void enqueue()
{
	if (isFull())
	{
		printf("Overflow!\n");
		return;
	}
	
	if (front == -1 && rear == -1)	
		front = rear = 0;
	
	else
		rear = (rear + 1) % N;
		
	printf("Enter the Element : ");
	scanf("%d", &queue[rear]);
}

void dequeue()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	printf("%d\n", queue[front]);
	
	if (front == rear)
		front = rear = -1;
		
	else
		front = (front + 1) % N;
}

void display()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	int i;
	printf("Queue is :\t");
	while (i != rear)
	{
		printf("%d\t", queue[i]);
		i = (i + 1) % N;
	}
	printf("%d", queue[rear]);
}

void peek()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	printf("%d\t", queue[front]);
}

int isFull()
{
	return (rear + 1) % N == front;
}

int isEmpty()
{
	return front == -1 && rear == -1;
}

int main()
{
	do
	{
		int ch;
		printf("\nMAIN MENU - \n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");
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
				display();
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
}


