#ifndef FIBONACCI
#define FIBONACCI 
int get_fib(int x,int y,int n){
	//x和y分别为第一项和第二项，n为项数
	switch (n) {
		case 1:
	 		return x;
		case 2:
			return y;
	}
	return get_fib(y,x+y,n-1);
}
#endif

	
