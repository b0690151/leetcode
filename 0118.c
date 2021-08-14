#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string.h>

#define MAX_SIZE 10


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
   
	printf("numRows %d returnSize %d returnColumnSizes %x\r\n", numRows, *returnSize, returnColumnSizes);
	int **ans  = (int **)malloc(sizeof(int *) * numRows);
	*returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
	int *ptrColSize = *returnColumnSizes;
	*returnSize = 0;
	
	if(numRows)
	{
//==== Allocation part
		if(ptrColSize == NULL)
		{
			printf("1 Out of Resource\r\n");
		}
		
		if(ans == NULL)
		{
			printf("2 Out of Resource\r\n");
		}
		
		if(ans && ptrColSize)
		{
			*returnSize = numRows;
			for(int i = 0; i < numRows; i++)
			{
				ptrColSize[i] = i + 1;
				ans[i] = (int *)malloc(sizeof(int) * (ptrColSize[i]));
				
				if(ans[i] == NULL)
				{
					break;
				}
				
				printf("Col %d Ret %d\r\n", ptrColSize[i], *returnSize);
			}
		}

//====== Inductive 
		for(int i = 0; i < numRows; i++)
		{
			for(int j = 0; j < ptrColSize[i]; j++)
			{
				if(j == 0 || j == (ptrColSize[i] - 1))
				{
					ans[i][j] = 1;
				}
				else
				{
					ans[i][j] = ans[i-1][j-1] + ans[i-1][j]; 
				}
			}
		}
	}	

    return ans;
}


int main(void){
	srand (time(NULL));
	
	int numRows = 5;
	int *returnColumnSizes = NULL;
	int returnSize = 0;

	int **ans = generate(numRows, &returnSize, &returnColumnSizes);
	
	
	//Show time
	for(int i = 0; i < numRows; i++)
	{
		for(int j = 0; j < returnColumnSizes[i]; j++)
		{
			printf("%2d ", ans[i][j]);
		}
		printf("\r\n");
	}
	
	
	
	if(ans)
	{
		printf("free ans %x \r\n", ans);
		for(int i = 0; i < returnSize; i++)
		{
			if(ans[i])
			{
				printf("free ans[%d] %x \r\n",i, ans[i]);
				free(ans[i]);
			}

		}
		free(ans);
	}
	
	if(returnColumnSizes)
	{
		printf("free returnColumnSizes %x \r\n", returnColumnSizes);
		free(returnColumnSizes);
	}
	
	
	return 0;
}

