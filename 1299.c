**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize){
    int temp;
    int max = arr[arrSize - 1];
    arr[arrSize - 1] = -1;
    *returnSize = arrSize;
    for(int i = arrSize - 2; i >= 0; i--)
    {
        if(arr[i] > max)
        {
            temp = arr[i];
            arr[i] = max;
            max = temp;
        }
        else
        {
            arr[i] = max;
        }
    }
    
    
    return arr;
}