#include <math.h>		/* pow */
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, srand, rand  */
#include <time.h>       /* time */
#include <string.h>    /* memset */

#define LENGTH (8)

typedef struct element HashTableEntry;
typedef HashTableEntry *pHashTableEntry;
struct element
{
	int key;
	int data;
	pHashTableEntry next;
};

int firstUniqChar(char * s)
{
    int offset = (int) 'a';
    unsigned int table[26];
    memset(table, 0xffffffff, sizeof(table));
    unsigned int i =0;
    while (s[i])
    {
        unsigned int index = s[i] - offset;
        table[index]++;
        i++;
    }
    i = 0;
    while (s[i])
    {        
        unsigned index = s[i] - offset;
        if (table[index] == 0)
		{
			return i;
		}
        i++;
    }
    return -1;
}

int main(void)
{
	srand (time(NULL));
	
	char  *c = (char *) malloc(LENGTH);
	
	for(int i = 0; i < LENGTH; i++)
	{
		c[i] = (rand() % 26) + 97; 
		printf("%c ", c[i]);
	}
	printf("\r\n");
	
	int ans = firstUniqChar(c);
	
	printf("ans %d\r\n",ans);
	
	free(c);
	
	return 0;
}