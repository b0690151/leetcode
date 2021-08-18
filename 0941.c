bool validMountainArray(int* arr, int arrSize){
    bool res = true;
    bool falling = false;
    int  max, i;
    if(arrSize >= 3)
    {
       max = arr[0];
       for( i = 1; i < arrSize; i++)
       {
            if( arr[i] - arr[i - 1] > 0)
            {   
                if(falling)
                {
                    res = false;
                    break;                      
                }
                if(max < arr[i])
                {
                    max = arr[i];
                }
                else
                {
                    res = false;
                    break;                    
                }
                
            } 
            else if ( arr[i] - arr[i - 1] < 0)
            {
                falling = true;
                if(max < arr[i])
                {
                    res = false;
                    break;
                }   
            }
            else // == 0
            {
                res = false;
                break;
            }
           
           //printf("a[%d] %d a[%d] %d max %d\r\n", i, arr[i], i - 1, arr[i-1],max);
       }
       
        if(max == arr[0] || max == arr[arrSize - 1])
        {
            res = false;
        }
        //printf("index %d\r\n",i);
    }
    else
    {
        res = false;
    }
    
    return res;
}