/*有N阶楼梯，你每次只能爬1,2,3阶楼梯，能有多少种
 * 方法
 */
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

long recursion(int n)
{
    int result = 0;
    
    if(1 == n) return 1;
    if(2 == n) return 2;
    if(3 == n) return 4;//(1+1+1) (1+2) (2+1) (3)ads
    return recursion(n-1) + recursion(n-2) + recursion(n-3); 
}
long iterate(n)
{
    long  pre_result[3] = {1,2,4};
    long pre_total = 0;
    int index = 0;

    if(1 == n) return 1;
    if(2 == n) return 2;
    if(3 == n) return 4;
  
    for(index = 4; index <= n;index++)
    {  
	pre_total = pre_result[0] + pre_result[1] + pre_result[2];
        pre_result[0] = pre_result[1];
        pre_result[1] = pre_result[2];
        pre_result[2] = pre_total;
    }

    return pre_result[2];
}

int main(void)
{
    int n = 0;
    long result_recursion = 0;
    long result_iterate = 0;
    clock_t start;
    clock_t end;   
    double recursion_duration = 0;
    double iterate_duration = 0;
     
    printf("please input the number\n"); 
    scanf("%d",&n);

    start = clock();        
    result_recursion = recursion(n);
    end = clock();
    recursion_duration = (end - start)/CLOCKS_PER_SEC; 
    printf("the recursion duration is %f second,the result is %ld\n",recursion_duration,result_recursion);   
    start = clock();
    result_iterate = iterate(n);
    end = clock();
    iterate_duration = (end - start)/CLOCKS_PER_SEC;    
    printf("the iterate_duration is %f seconds,the result is %ld\n",iterate_duration,result_iterate);

    return 0; 
}


 
