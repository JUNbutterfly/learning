#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main(){
	double input;
	printf("please input a number:");
	int status = scanf("%lf",&input);
	if (status != 1 || (input > 1000 || input <= 0)){
			fprintf(stderr,"invalid number");
			exit(1);
	} else {
	printf("这是一个%s数",(((int)floor(input) % 2) == 0) ? "偶" : "奇");
	return 0;
}
}


/* 对于计算机如何表示浮点数仍然有点搞不懂，
 * 这使得我对于浮点数的比较有点不知所措。
 * 我想是时候该写一个自动化工具，用于生成执行文件。
 */
