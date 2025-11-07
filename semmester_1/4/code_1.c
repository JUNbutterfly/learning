#include <stdio.h>
#include <stdint.h>
int32_t main(){
  int32_t a[10];
  int32_t av = 0;
  uint8_t i;
  for ( i = 0; i<=9;i++){
    scanf("%d",&a[i]);
  }
  printf("\n");
  for (i = 0;i<=9;i++){
    av += a[i];
    printf("%d ",a[i]);
    if ((i+1) % 3 == 0){
      printf("\n");
    }
  }
  printf("\nav=%f",(double)av/10.0);
  return 0;
  }
