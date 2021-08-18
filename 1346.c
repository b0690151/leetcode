bool checkIfExist(int* arr, int arrSize){
    int hashtable[2001];  //[0 - 1000] positive [1001 - 2000] to store [-1000 -  -1]
    int index = 0;
    memset((void*)hashtable, 0, sizeof(int) * 2001);
    bool res = false;
    for(int i = 0; i < arrSize; i++)    
    {
        if(arr[i] < 0)
        {
            index = arr[i] + 2001;
            hashtable[index]++;
            //printf("table[%d] ++ \r\n", index);
        }
        else
        {
            index = arr[i];
            hashtable[index]++;
            //printf("table[%d] ++ \r\n", index);
        }
    }    
    
    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] > 0 && arr[i] <= 500)
        {
            index = 2 * arr[i];
            if(hashtable[index])
            {
                //printf("hash[%d] %d A\r\n",index, hashtable[index]);
                res = true;
                break;
            }
        }
        else if (arr[i] < 0 && arr[i] >= -500)
        {
            index = 2 * arr[i]  + 2001;
            if(hashtable[index])
            {
                //printf("B\r\n");
                res = true;
                break;
            }
        }
        else // == 0
        {
            if(hashtable[0] > 1)
            {
                //printf("C\r\n");
                res = true;
                break;
            }
        }
    }
    
    return res;
}