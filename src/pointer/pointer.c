#include <stdio.h>
int vofm(int m){
    int ret;
    if(m<0)
	printf("输入m值必须大于0");	
	return -1;
    if(m>0)
    	ret = 2 * vofm(m-1);
    else
        ret = 1;
    return ret;
}
int main()
{
    int a=8,m;
    int *pa = &a;
    int **ppa = &pa;
    scanf("%d",&m);
    int (*p)(int m) = &vofm;
	//int mv = p(m); 	
	int mv = (*p)(m);
    printf("2 的%d次方为%d",m,mv);	
}
