#include <math.h>		/* pow */
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, srand, rand  */
#include <time.h>       /* time */
#include <string.h>    /* memset */

#define LENGTH (2)



/**
 * Definition for singly-linked list.

 */
 struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode* createlist(int *data, int len)
{
	struct ListNode* head = NULL;
	struct ListNode* current = NULL;
	if(len > 0)
	{	
		for(int i = 0; i < len; i++)
		{

			if(i == 0)
			{
				current = (struct ListNode*) malloc(sizeof(struct ListNode));
				current->val = data[i]; 
				current->next = NULL;
				head = current;
			}else
			{
				current->next = (struct ListNode*) malloc(sizeof(struct ListNode));
				current = current->next;
				current->val = data[i]; 
				current->next = NULL;
			}
		}
	}
	return head;
}

void showlist(struct ListNode* head)
{
	struct ListNode* current = head;
	while(current)
	{
		printf("%2d ", current->val);
		current = current->next;
	}
	printf("\r\n");
}

void freelist(struct ListNode* head)
{
	struct ListNode* current = head;
	struct ListNode* previous = NULL;
	
	while(current)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
}

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* previous = NULL;
    struct ListNode* current; 
    struct ListNode* next;
    
    current = head;
    
    
    while(current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    
    return previous;
}

struct ListNode* reverseList2(struct ListNode* head, int count){
    struct ListNode* previous = NULL;
    struct ListNode* current; 
    struct ListNode* next;
    int cnt = 0;
    current = head;
    
    
    while(current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
		cnt++;
		if(cnt == count)
		{
			break;
		}
    }
    
    return previous;
}

bool isPalindrome(struct ListNode* head){
	//easy case first
#if 1
	if(head == NULL || head->next == NULL)
	{
		return 1;
	}
#else	
	
	if(head == NULL || head->next == NULL)
	{
		return 1;
	}else if((head->next->next) == NULL)
	{
		if( (head->val) ==(head->next->val))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}else if((head->next->next->next) == NULL)
    {
		if( (head->val) ==(head->next->next->val))
		{
			return 1;
		}
		else
		{
			return 0;
		}  
    }
#endif

	int length = 0;
	int i = 0;
	struct ListNode* cur = head;
	
	while(cur)
	{
		cur = cur->next;
		length++;
	}
	
	//printf("length %d  length/2 %d\r\n", length, length >> 1);
	//second part
	for(cur = head,  i = 0; i < (length >> 1); i++)
	{
		cur = cur->next;
	}
	
	if(length & 0x1)
	{
		cur = cur->next;
	}
	
	//showlist(cur);
	
	//first part
	head = reverseList2(head, length >> 1);
	//showlist(head);
	
	while(head && cur)
	{
		if(head->val != cur->val)
		{
			return 0;
		}
		head = head->next;
		cur = cur->next;
	}
	
	return 1;
}


int main(void)
{
	srand (time(NULL));
	int data[LENGTH] = {1,2};
	struct ListNode* head = createlist(data, LENGTH);
	struct ListNode* cur = NULL;

	showlist(head);
	
	//cur = reverseList2(head,2);
	
	//showlist(cur);
	//showlist(head);


	printf("ans %d", isPalindrome(head));

	freelist(head);
	
	
	
	return 0;
}