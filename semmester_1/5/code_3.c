#include <stdio.h>
#include <inttypes.h>//拥抱可移植性,拒绝背又臭又杂的格式化控制符中的type specifier
#include <stdlib.h>
#define N 4 //人数
#define M 3 //课程
void input(uint8_t score[N][M]){
  for (uint16_t i = 0; i < N; i++){
    for (uint16_t j = 0; j < M; j++){
      scanf("%"SCNu8,&score[i][j]);
    }
    putchar('\n');
  }
}

void output(double array[], uint16_t n){//i和n都使用有符号整型或许更加安全
                                       //但我们选择相信程序员
  for (uint16_t i = 0;i < n; i++){
    printf("output:array[%"PRIu16"] = %lf\n",i,array[i]);
  }
}

void avgsub(uint8_t score[N][M],double subscore[M]){
  for (uint16_t i = 0;i < M; i++){
    uint16_t sum = 0;
    for (uint16_t j = 0;j < N; j++){
      sum += score[j][i];
    }
    subscore[i] = (double)sum / (double)M;
  }
}
uint16_t maxid(double array[],uint16_t n, uint16_t i){//i表示从array[i] (included)开始查询
  //这时n和i使用无符号整型是更优选择，这方便我们对数组访问是否越界很有帮助
  if (i >= n){fprintf(stderr,"valid access to array in function maxid"); exit(EXIT_FAILURE);}
  uint16_t max = i;//临时记录最大元素下标
  for (;i < n; i++){
    if (array[i] > array[max]){
      max = i;
    }
  }
  return max;
}

void swap(double array[],uint16_t n,uint16_t i, uint16_t j){
  //n为元素个数, 用于判断swap函数是安全的
  if (i >= n || j >= n){fprintf(stderr,"valid access to array in function maxid"); exit(EXIT_FAILURE);}
  double temp;
  if( i != j ){
  temp = array[i];
  array[i] = array[j];
  array[j] = temp;
  }
}
void sort(double array[], uint16_t n){
  //选择排序
  for (uint16_t i = 0;i < n; i++){ //i为每次应该被未排序部分最大值替换的位置
    swap(array,n,i,maxid(array,n,i));
  }
}

int32_t main(){
  uint8_t s[N][M];
  double sub[M];
  input(s);
  avgsub(s,sub);
  sort(sub,M);
  output(sub,M);
}
