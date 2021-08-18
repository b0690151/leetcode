void duplicateZeros(int* arr, int arrSize){
    int i, j;
    int zero_cnt = 0;
    for(i = 0; i < arrSize - zero_cnt; i++)
    {
        if(arr[i] == 0)
        {
            for(j = arrSize - 1; j > i; j--)
            {
                arr[j] = arr[j - 1];
            }
            i++;
        }
    }
}