#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
char *repeat_str(uint8_t times, const char *str){
  char *value = calloc(times+2,1);//2用于'\0'和'*'
  for (uint8_t i = 0; i < times; i++){
    strcat(value,str);
  }
  return value;
}

int32_t main(){
  //打印x轴
  char *x = repeat_str(20,"-");
  printf("0%s-->y轴\n",x);
  free (x);
  for (uint8_t i = 0; i < 19; i++){
    uint8_t times = (uint8_t)floor(10*(1+sin(i*M_PI/18)));
    char *temp = repeat_str(times,"-");
    strcat(temp,"*");
    printf("|%s\n",temp);
    free(temp);
  }
  printf("|\n|\n|\nx\n轴");
}
//main函数中的每次for循环都会进行堆上的内存的分配和释放
//但我们先暂时不要管

