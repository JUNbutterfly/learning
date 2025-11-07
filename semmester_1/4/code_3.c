#include <stdio.h>
#include <stdint.h>
int32_t main(){
  //按顺序输入每位同学6科成绩，共输入5位学生成绩
  uint16_t s[5][6];
  for (uint8_t i = 0 ; i < 5; i++){
    for (uint8_t j = 0; j < 6; j++){
      scanf("%hu",&s[i][j]);
      if (j == 5){
        putchar('\n');}}}
  uint16_t ts[5] = {0};
  for (int i = 0; i < 5; i++){
    for (uint8_t j = 0; j < 6 ;j++){
      ts[i] += s[i][j];}}
  uint16_t temp = 0; //用于临时储存
  for (uint8_t i = 4; i < 5; i--){//i用于记录当前需要被替换为更小值的索引
  uint8_t min = 0;//用于记录最小值的索引
    for (uint8_t j = 0 ; j <= i  ;j++){
      if (ts[j] < ts[min]){
        min = j;
      }
    }
  //ts总成绩交换
  if (min != i){
  temp = ts[min];
  ts[min] = ts[i];
  ts[i] = temp;
  //s各科成绩交换
  for (uint8_t k = 0; k < 6; k++){
  temp = s[min][k];
  s[min][k] = s[i][k];
  s[i][k] = temp;
  } }}
  //输出
  for (uint8_t i = 0; i < 5 ; i++){
    printf("\n***总分:%d***",ts[i]);
    for (uint8_t j = 0;j < 6; j++){
      printf("%5d",s[i][j]);
  }
  }
  putchar('\n');
}
