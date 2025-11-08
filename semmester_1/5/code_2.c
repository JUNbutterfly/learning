#include <stdio.h>
#include <stdint.h>
uint32_t calcu(uint32_t x, uint32_t n){
  if ( n == 1){//尾递归，在递的过程中进行计算
    return x;
  }
  return calcu(x * x, n - 1);
}
int32_t main(){
  printf("%u",calcu(2,32)-1);
}
