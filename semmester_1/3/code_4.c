#include "fibonacci.h"
#include <stdio.h>
int main(){
	for (int x=1;x<=10;x++){
		int k=get_fib(1,1,x);
		if (k>10){
			printf("项数:%d项值%d",x,k);
			break;
		}
	}
}
