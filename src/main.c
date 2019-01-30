#include <stdio.h>
#include "min.c"
#include "max.c"
int a,b;
int main()
{
    a=20;
    b=25;
    int sum = a + b;
    int minNum = minof(a,b);
    int maxNum = maxof(a,b);
    printf(" a is %d \n b is %d \n sum is %d \n",a,b,sum);
    printf("min:%d \n,max:%d \n",minNum,maxNum);
    for(int i=0;i<sum;i++){
        if(i<10){
            printf("i is %d < 10 \n",i);
        }else{
            printf("i is %d > 10 \n",i);
        }
    }
    return 0;
}