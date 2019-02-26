#include <stdio.h>
int main(int argc,char *argv[])
{	
	/*
	// 指针数组
	#int *a[10]
	#typedef int *t
	#t a[10]
	// 数组指针
	#int (*a)[10]
	#typedef int t[10]
	#t *a

	#a[10]
	#(*pa)[10]
	**/
	for(int i=0;i<=argc;i++){
	    printf("array参数%d为%c\n",i,argv[i]);
	}
	printf("-----------\n");
	for(int i=0;i<=argc;i++){
	   printf("pointer参数%d为%c\n",i,*argv[i]);
	} 	
}
