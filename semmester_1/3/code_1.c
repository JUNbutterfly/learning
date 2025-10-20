#include <stdio.h>
#include <stdlib.h>
typedef struct {
	unsigned int lcm; //最小公倍数
	unsigned int hcf; //最小公因数
	} outcome;
outcome *method_1(unsigned int m, unsigned int n);
outcome *method_2(unsigned int m, unsigned int n);
int main(){
	unsigned int m;
	unsigned int n;
	printf("请输入任意两个整数");
	scanf("%d",&m);
	scanf("%d",&n);
	if ( m < n ){
		m = m + n;
		n = m - n;
		m = m - n;
	}// 交换m与n的值
	outcome *oc_1 = method_1(m,n);
        outcome *oc_2 = method_2(m,n);
	printf("方法一：最小公倍数%d,最大公因数%d\n",oc_1->lcm,oc_1->hcf);
	printf("方法二：最小公倍数%d,最大公因数%d",oc_2->lcm,oc_2->hcf);
	free(oc_1);
	free(oc_2);

}



	
outcome *method_1(unsigned int m, unsigned int n){
	outcome *oc = (outcome *)malloc(sizeof(outcome));
	unsigned m_ = m;
	unsigned n_ = n;
  	unsigned int k;
	do{
		k = m % n;
		m = n;
		n = k;
  		}while ( k != 0 );
	oc->hcf = m;
	oc->lcm = m_ * n_ / m;
	return oc;


}
outcome *method_2(unsigned int m, unsigned int n){
	outcome *oc = (outcome *)malloc(sizeof(outcome));
	unsigned k = n; 
	for (;;k--) {
 		if ((m % k == 0 && n % k == 0) || k == 1 ){
			oc->hcf = k;
			oc->lcm = m * n / k;
			return oc;
}
}
}



	
		
