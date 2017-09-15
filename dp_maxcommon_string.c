#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_STRING_LENGTH 100

int find_the_maximum_string_and_length(char string1[],char string2[])
{
   int i = 0;
   int j = 0;
   int common[MAX_STRING_LENGTH][MAX_STRING_LENGTH];
   int max_length = 0;
   int common_start = 0 ;
   int common_end = 0;
   char common_string[MAX_STRING_LENGTH] = {0};

   memset(&common[0][0],0,(MAX_STRING_LENGTH*MAX_STRING_LENGTH));

   for(i=0;i<strlen(string1);i++)
   {
      for(j=0;j<strlen(string2);j++)
      {
	 if(string1[i] == string2[j])
         {
	    if(i==0 || j==0)
            {
		common[i][j] = 1;

            }
            else
            {
		common[i][j] = common[i-1][j-1] + 1;
                if(common[i][j] > max_length)
                {
                    common_start = i - common[i][j] + 1;
                    common_end = i+1;
                    memcpy(common_string,&string1[common_start],(common_end-common_start));
	            max_length = common[i][j];		
                }
            }
         }
      }
   }
   printf("the maxcommonstring is %s\n",common_string);
   return max_length;
}


int main(void)
{
   char string1[MAX_STRING_LENGTH] = {0};
   char string2[MAX_STRING_LENGTH] = {0};
   int string_length = 0;

   printf("please input string1\n");
   scanf("%s",string1);
   printf("please input string2\n");
   scanf("%s",string2);

   string_length = find_the_maximum_string_and_length(string1,string2);

   printf("the string_length is %d\n",string_length);
   return 0;
}
