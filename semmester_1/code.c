#define weiku 0
#define shaoxian 1
#define zhengchang 2
#define TASTE shaoxian //weiku,shaoxian,zhengchang
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#if TASTE == weiku
uint8_t err;
int power_10(int x,int y){
  // 开始时，y 应该为1
  if (x == 0){
    return y;
  }
  return power_10(x - 1,10 * y);
}
double convert(){
  char x[40]; // 输入
  int temp = 0; //临时输出
  printf("\n请输入华氏温度，请确保它大于或等于绝对零度−459.6℉ ");
  printf("\n暂只支持小数点后一位的精度，超过部分会被截断");
  scanf("%s",x);
  char *ptr = strchr(x,'.');
  char *negative = strchr(x,'-'); //负数处理
  int y_ = (ptr) ? (ptr - x) / sizeof(char): strlen(x);  // '.'前的字符个数
  int y  = (negative) ? y_ : y_ + 1; // 处理后数字的个数
  int *intermediate = (int *)calloc(y,sizeof(int));

    for (int i =  (negative ? 1 : 0), i_ = 0;i < y_; i++,i_++){
     intermediate[i_] = (int)(x[i] - '0');
     if (intermediate[i_]  > 9 || intermediate[i_] < 0){err = 0;return -461.0;}       //对输入进行判断
  }
     if (ptr){
     if ((int)(*(ptr + 1) - '0') < 10 && (int)(*(ptr+1) - '0') > -1){
      intermediate[y-1] = (int)(*(ptr + 1) -'0');
      } else {err = 1;return -461.0;}
    } else {intermediate[y-1] = 0;}
  
//      for (int i = 0; i < y; i++){
 //   printf("\ndebug%d",intermediate[i]);
  //}
    
      for (int i = 0;i < y - 1;i++){
       temp += power_10(y - i - 2,1) * intermediate[i];
      }

      if (negative){
      if (temp < 459 || (temp == 459 && intermediate[y-1] <= 6)){
        return (0 - temp - intermediate[y-1] * 0.1);
      } else {err = 2;return -461.0;}
        }
       else { return temp + intermediate[y-1] * 0.1;}
      return -461.0; 
    }
int main(){
while (1){
    double input = convert();
    if ((int)input < -460){
      switch (err){
        case 0 :
        case 1 :
          printf("\nerror:请确保输入的是合理的数字");
          break;
        case 2 :
          printf("\nerror:请确保输入数字为绝对零度之上");
          break;
        default :
          printf("\nerror:未知错误");
          
      }
      continue;
    }
    printf("\ninput(已被处理):%.1f°C\n",input);
    printf("\noutput:%.1f℉ ",(input -32) * 5 / 9);
  }
}
#endif

#if TASTE == shaoxian
int main(){
  while(1){
  char input[40];
  printf("\n请输入:");
  scanf("%40s",input);
  char ** happy_coding;
  double output = strtod(input,happy_coding);
  if (!((strlen(input) == 1 && strchr(input,'0')) || (strlen(input) == 3 && strstr(input,"0.0"))) && ((int)output == 0)){
    printf("input：%s",input);
    printf("\n请不要给我奇奇怪怪的东西!!!");
  } else {output = (output - 32) * 5 / 9;printf("input:%s°C\noutput:%.1f℉ ",input,output);}
}
}
#endif

#if TASTE == zhengchang
int main(){
    while (1){
    double input;
    printf("请输入:");
    scanf("%lf",&input);
    printf("input:%.1f°C\noutput:%.1f℉ ",input,(input - 32) * 5 / 9);
  }
}
#endif
