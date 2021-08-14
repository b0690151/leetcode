#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string.h>

#define MAX_SIZE 5
#define MAX_NUMBER 100

typedef struct _queee
{
	int front;
	int rear;
	int size;
	int *ptr;
}QUEUE, *PQUEUE;

PQUEUE createQueue(int size)
{
	PQUEUE pQueue = (PQUEUE) malloc(sizeof(QUEUE));
	
	pQueue->front = 0;
	pQueue->rear  = 0;
	pQueue->size  = size;
	
	pQueue->ptr = (int *)malloc(sizeof(int) * size);
	
	return pQueue;
	
}

int isQueueEmpty(PQUEUE pQueue)
{
	return (pQueue->front == pQueue->rear);
}

int isQueueFull(PQUEUE pQueue)
{
	return (pQueue->front == ((pQueue->rear + 1) % pQueue->size));
}

int enQueue(PQUEUE pQueue, int data)
{
	int ans = 0;
	
	if(!isQueueFull(pQueue))
	{
		pQueue->ptr[pQueue->rear] = data; 
		pQueue->rear = (pQueue->rear + 1) % pQueue->size;
	}
	else
	{
		printf("Queue Full\r\n");
		ans = 1;
	}
	
	return ans;
}

int deQueue(PQUEUE pQueue, int *data)
{
	int ans = 0;
	
	if(!isQueueEmpty(pQueue))
	{
		*data = pQueue->ptr[pQueue->front]; 
		pQueue->front = (pQueue->front + 1) % pQueue->size;
	}
	else
	{
		printf("Queue Empty\r\n");
		ans = 1;
	}
	
	return ans;
}

void deleteQueue(PQUEUE pQueue)
{
	if(pQueue != NULL)
	{
		if(pQueue->ptr != NULL)
		{
			free(pQueue->ptr);
		}
		free(pQueue);
	}
}

void resizeQueue(PQUEUE pQueue, int size)
{
	if(pQueue != NULL)
	{
		if(pQueue->ptr != NULL)
		{
			pQueue->ptr = (int *) realloc(pQueue->ptr, sizeof(int)*size);
			pQueue->size = size;
		}
	}
}

void showQueue(PQUEUE pQueue)
{
	int temp = pQueue->front;
	while(temp != pQueue->rear)
	{
		printf("%2d ",pQueue->ptr[temp]);
		temp = (temp + 1) % pQueue->size;
	}
	
	printf("\r\n");
}


int main(void)
{
	PQUEUE pQueue = createQueue(MAX_SIZE);
	
	for(int i = 0; i < pQueue->size + 1; i++)
	{
		enQueue(pQueue, rand() % MAX_NUMBER);
		showQueue(pQueue);
	}

	resizeQueue(pQueue, 2*MAX_SIZE);
	
	printf("resize QUeue\r\n");
	for(int i = 0; i < pQueue->size + 1; i++)
	{
		enQueue(pQueue, rand() % MAX_NUMBER);
		showQueue(pQueue);
	}
	
	int data = -1;

	for(int i = 0; i < pQueue->size + 1; i++)
	{
		deQueue(pQueue, &data);
		printf("Get data %2d from queue \r\n",data);
		showQueue(pQueue);
	}
	
	deleteQueue(pQueue);
	return 0;
}
