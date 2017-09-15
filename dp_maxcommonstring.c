#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define STRING_LENGTH 100

int calculate_max_common_string_length(char string1[],char string2[])
{
    unsigned int common[STRING_LENGTH][STRING_LENGTH]; 
    int i = 0;
    int j = 0;
    int max_common_length = 0;
    int common_start = 0;
    int common_end = 0;
    char common_string[STRING_LENGTH]={0};
//    memset(common,0,STRING_LENGTH*STRING_LENGTH);
  
    for(i=0; i<STRING_LENGTH; i++)
    {
	for(j=0; j<STRING_LENGTH; j++)
        {
	    common[i][j] = 0;
        }
    }
     
//    for(i=0; i<STRING_LENGTH; i++)
  //  {
//	for(j=0; j<STRING_LENGTH; j++)
  //      {
//	    printf("the common value is %d\n",common[i][j]);
  //      }
    //}
   

    printf("the length of string1 is %d\n",strlen(string1));
    printf("the length of string2 is %d\n",strlen(string2));
        
    for(i = 0;i< strlen(string1);i++)
    {
	for(j=0;j < strlen(string2);j++)
        {
	    if(string1[i] == string2[j])
            {
		if(i == 0 || j == 0)
                {
		    common[i][j] = 1;
                }
		else
                {
                    printf("the value of common[%d][%d] is %d\n",i-1,j-1,common[i-1][j-1]);
		    common[i][j] = common[i-1][j-1] + 1;
                    if(common[i][j] > max_common_length)
                    {
                        memset(common_string,0,sizeof(common_string));
                                                        
			max_common_length = common[i][j];
                       
                        printf("middle the max_common_length is %d\n",max_common_length);
                        common_start = i - common[i][j] + 1;
                        common_end = i+1;
                        memcpy(common_string,&string1[common_start],(common_end-common_start));
                   }
                }
            }
        }
    }
    printf("the commonstring is %s\n",common_string);
    return max_common_length;
}

int main(void)
{
   char string1[STRING_LENGTH] = {0};
   char string2[STRING_LENGTH] = {0};
   int length = 0;

   printf("please input string1\n");
   scanf("%s",string1);
   printf("please input string2\n");
   scanf("%s",string2);
   
   length =calculate_max_common_string_length(string1,string2);
   printf("the maximum length is %d\n",length);
   return 0;
}



