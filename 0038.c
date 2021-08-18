/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr_size = 1024;

char * countAndSay(int n){
    
    char *ans  = (char *) malloc(arr_size);
    char *temp = (char *) malloc(arr_size);
    memset(ans, 0, arr_size);
    ans[0] = '1';
    
    if(n > 1)
    {
        int index = 0;
        int len = strlen(ans);
        for(int i = 2; i <= n; i++)
        {
            index = 0;
            len = strlen(ans);
            int char_number = ans[0];
            int count = 1;
            
            for(int j = 1; j < len; j++)
            {
                if(ans[j] == char_number)
                {
                    //printf("ans[%d] : %c == %c  index %d\r\n", j, ans[j], char_number,index);
                    count++;
                }
                else
                {
                    //printf("ans[%d] : %c != %c index %d\r\n", j, ans[j], char_number, index);
                    temp[index++] = count + '0';
                    temp[index++] = char_number;
                    char_number = ans[j];
                    count = 1;
                }
            }

            temp[index++] = count + '0';
            temp[index++] = char_number;
            temp[index] = 0;
            
            memcpy(ans, temp, strlen(temp) + 1);
            
            if( (index * 2 + 1) > arr_size && i != n)
            {
                arr_size = arr_size * 2; //min index * 2 + 1
                ans = (char *) realloc(ans, arr_size);
                temp = (char *) realloc(temp, arr_size);
                //printf("i %d strlen(temp) %5d index %5d arr_size %5d\r\n",i,strlen(temp),index,arr_size);
            }   
        }     
        
         free(temp);
         //printf("Final len %5d index %5d\r\n", len, index);
    }
    
    
    return ans;    
}

int main()
{
    for(int i = 1; i <= 30; i++)
    {
        countAndSay(i);
        //printf("%d %s\r\n", i, countAndSay(i));
    }
    
    return 0;
}





