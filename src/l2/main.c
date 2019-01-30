#include <stdio.h>
int add_range(int low,int high){
    int i,sum;
    for(i=0;i<high;i++)
        sum += i;
    return sum;
}
int main(void){
    int result[100];
    result[0] = add_range(1,10);
    result[1] = add_range(1,100);
    printf("result[0]=%d \n result[1]=%d \n",result[0],result[1]);
    return 0;
}