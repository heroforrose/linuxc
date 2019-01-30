#include <stdio.h>
#include "min.h"
#include "max.h"
int main()
{
    int a=22;
    int b=40;
    int c;
    printf("the max is :%d\n.the min is :%d\n",max(a,b),min(a,b));
    c=a+b;
    printf("this is sum:%d \n",c);
    return 0;
}