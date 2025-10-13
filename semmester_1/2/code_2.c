#include <stdio.h>
#include <math.h>
#define requirement 1 // 1 or 2
int main(){
	double money;
	double months;
	printf("please input money:");
	scanf("%lf",&money);
	printf("please input months:");
	scanf("%lf",&months);
 	#if requirement == 1
	if (months >= 0){
		if (months <= 36){
			if (months <= 12){
				if (months <= 6){
					printf("output:%f",money * pow(1 + 0.0610,months));} else{
				        	printf("output:%f",money * pow(1 + 0.0656,months));}	
								}else{
        printf("output:%f",money * pow(1 + 0.0665,months));}
			}else {
                               	printf("output:%f",money * pow(1 + 0.0690,months));}
						}else{printf("you should input a postive number at least!");}
        #endif
	#if requirement == 2
	if ( months >= 0 && months <= 6){
	printf("output:%f",money * pow(1 + 0.0610,months));}
	else if ( months > 6 && months <= 12 ){
	printf("output:%f",money * pow(1 + 0.0656,months));}
	else if ( months >12 && months <= 36 ){
	printf("output:%f",money * pow(1 + 0.0665,months));}
	else if ( months >  36 ){
	printf("output:%f",money * pow(1 + 0.0690,months));}
	else {
 	printf("you should input a positive number at least !")}
	#endif
	                        
}
