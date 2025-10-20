#include "fibonacci.h"
#include <stdio.h>
int main(){
	int sum=0;
	for (int x=1;x<=10;x++){
		int value = get_fib(1,1,x);
		if (value%2 == 1){
			sum +=value;
			printf("项数:%d项值:%d\n",x,value);
		}
	}
	printf("sum=%d",sum);
}
				
