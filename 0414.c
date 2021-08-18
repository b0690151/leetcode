int thirdMax(int* nums, int numsSize){
    int log[4];  // [0] 1st Max [1] 2nd Max [2] 3rd Max
    int ans = 0, i, j;
    if(numsSize < 3)
    {
        ans = nums[0];
        for(i = 1; i < numsSize; i++)
        {
            if(nums[i] > ans)
            {
                ans = nums[i];
            }
        }
    }
    else
    {
        //check there are 3 distinct number first O(N)
        log[0] = nums[0];
        log[1] = nums[0];
        log[2] = nums[0];
        
        int index = 1;
        bool distinct;
        for(i = 1; i < numsSize; i++)
        {
            if(nums[i] != log[0] && nums[i] != log[1])
            {
                log[index++] = nums[i];
            }
            
            if(index == 3)
            {
                break;
            }
        }
        
        if(index == 3)
        {
            distinct = true;
        }
        else
        {
            distinct = false; 
        }
        
        //Sort Big 3  constant to numsSize
        for(i = 0; i < 3; i++)
        {
            for(j = i+1; j < 3; j++)
            {
                if(log[i] < log[j])
                {
                    int temp = log[j];
                    log[j] = log[i];
                    log[i] = temp;
                }
            }
        }
#if 0
                for(i = 0; i < 3; i++)
                {
                    printf("%d ",log[i]);
                } 
#endif
        //if not return max
        //if exist 
        //compare number to the three number 3 O(N) or O(N)
        
        if(distinct)
        {
                bool check;
                for(i = 1; i < numsSize; i++)
                {
                    // check distinct
                    check  = true;
                    for(j = 0; j < 3; j++)
                    {
                        if(nums[i] == log[j])
                        {
                            check = false;
                            break;
                        }
                    }
                    
                    if(check == true)
                    {
                        log[3] = nums[i];
                        
                            //Sort Big 3  constant to numsSize
                            for(int k = 0; k < 4; k++)
                            {
                                for(j = k+1; j < 4; j++)
                                {
                                    if(log[k] < log[j])
                                    {
                                        int temp = log[j];
                                        log[j] = log[k];
                                        log[k] = temp;
                                    }
                                }
                            }   
                        }                     
                } 
                ans = log[2];
        }
        else
        {
            ans = nums[0];
            for(i = 1; i < numsSize; i++)
            {
                if(nums[i] > ans)
                {
                    ans = nums[i];
                }
            }            
        }
#if 0        
                for(i = 0; i < 3; i++)
                {
                    printf("%d ",log[i]);
                }  
#endif
    }
    
    return ans;
}