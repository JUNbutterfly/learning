#include <stdio.h>
int main(){
	unsigned int x;
	printf("输入查询范围\n");
	scanf("%d",&x);
	for (unsigned int a = 1;a<x;a++){
		for (unsigned int b = 2;b<=x;b++){
			if(2*a*a+2*a+1 == b*b){
				printf("[%d,%d,%d]\n",a,a+1,b);
			}
		}
	}
	printf("查询完毕");
}
