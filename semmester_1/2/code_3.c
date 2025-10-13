#include <stdio.h>
int main(){
	unsigned int input;
	printf("input:");
	scanf("%d",&input);
	int a = input % 10; //个位
	int b = ( input % 100 - a ) / 10; //十位
	int c = ( input - input % 100 ) / 100; //百位
	if ( c == 0 ){
		if ( b == 0 ){
			puts("一位数");
			printf("正序:%d\n",a);
			printf("逆序:%d\n",a);
		} else {puts("两位数");printf("正序:%d %d\n",b,a);printf("逆序:%d %d\n",a,b);}
	} else {puts("三位数");printf("正序:%d %d %d\n",c,b,a);printf("逆序:%d %d %d\n",a,b,c);}
}


			
