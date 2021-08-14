#include <math.h>		/* pow */
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, srand, rand  */
#include <time.h>       /* time */
#include <string.h>    /* memset */

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

#if 1
	for(int i = 0; i < nums1Size; i++)
	{
		printf("%d ",nums1[i]);
	}
	
	printf("\r\n");
	
	for(int i = 0; i < nums2Size; i++)
	{
		printf("%d ",nums2[i]);
	}
	
	printf("\r\n");
#endif
    
    
    
    int length_s;
	
    if(nums2Size >= nums1Size)
    {
        length_s = nums1Size;
    }
	else
    {
        length_s = nums2Size;
    }
    
	
	
    int *ans = (int *) calloc(sizeof(int) * length_s, sizeof(int));
    
    int index_1 = 0;
	int index_2 = 0;
    *returnSize = 0;
    while(index_1 < nums1Size && (index_2 < nums2Size))
    {
		if(nums1[index_1] < nums2[index_2])
		{
			index_1++;
		}else if(nums1[index_1] > nums2[index_2])
		{
			index_2++;
		}else
		{
            ans[*returnSize] = nums1[index_1];
			*returnSize += 1;
			index_1++;
			index_2++;
		}

		//printf("index_s %d, index_l %d \r\n", index_1, index_2);
    }
    
    return ans;
}

int main(void)
{
	int rsize;
	int num1Size = 3;
	int num2Size = 2;
	int num1[3] = {3,1,2};
	int num2[2] = {1,1};
	int *ans = NULL;
	
	ans = intersect(num1, num1Size, num2, num2Size, &rsize);
	
	for(int i = 0; i < rsize; i++)
	{
		printf("%d ",ans[i]);
	}
	
	printf("\r\n");
	free(ans);
	
	return 0;
	
}