/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int i  = 0, temp = 0; 
    for(int i = 0, j = numsSize - 1; i < numsSize; i++)
    {
        while(nums[i] & 0x1)
        {
            temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            j--;
            if(j <= i)
            {
                break;
            }
        }
        
        if(j <= i)
        {
            break;
        }
        
    }
    
    
    return nums;
}