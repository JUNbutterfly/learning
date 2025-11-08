#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#define M 10
#define N 10
double mean(uint8_t Mat[M][N], uint8_t m,uint8_t n);
void hist(uint8_t destHist[10], uint8_t Mat[M][N], uint8_t m, uint8_t) ;
void draw(uint8_t destHist[10]);//绘制频数直方图

int32_t main(){
  srand((uint32_t)time(NULL)); //生成随机种子
  uint8_t histVal[10] = {0};
  uint8_t Mat[M][N];
  for (uint8_t i = 0 ; i < M ; i++){
    for (uint8_t j = 0 ; j < N ; j++){
      Mat[i][j] = (rand() % 10); //[0,9]的随机整数
      }
  }

  printf("average = %f\n",mean(Mat,M,N));
  hist(histVal,Mat,M,N);
  draw(histVal);
}  

double mean(uint8_t Mat[M][N], uint8_t m,uint8_t n){
  double sum = 0;
  for (uint8_t i = 0 ; i < m ; i++){
      for (uint8_t j = 0 ; j < n ; j++){
        sum += Mat[i][j] ;
        }
    }
  return sum / (m * n); 
}

void hist(uint8_t destHist[10], uint8_t Mat[M][N], uint8_t m, uint8_t n){//destHist的下标n对应的值为
   for (uint8_t i = 0 ; i < m ; i++){                                    //Mat数组中n所出现的次数
      for (uint8_t j = 0 ; j < n ; j++){
        destHist[Mat[i][j]] += 1; 
        }
   }
}

void draw(uint8_t destHist[10]){
    uint8_t max = 0; //用于记录destHist中的最大值的下标
    const char str1[] = "*       ";
    const char str2[] = "        ";
    char *line = calloc(41,1);
    printf("\n频\n数\n");
      

    for (uint8_t i = 0; i < 5; i++){ printf("|\n");}
    for (uint8_t i = 0; i < 10 ; i++){
      if (destHist[i] > max){ max = i;}
    }


    for (uint8_t i = destHist[max]; i <= destHist[max]; i--){
      for (uint8_t j = 0 ; j < 10 ; j++){
        if (destHist[j] >= i){strcat(line,str1);}
        else { strcat(line,str2);}
      }printf("|    %s",line);
      memset(line,0,41);
      printf("\n|\n");
    }
    printf("     ");     
    for (uint8_t i = 0; i < 10; i++){
      printf("-       ");
    }
    printf("元素\n     ");
    for (uint8_t i = 0; i <10 ; i++){
      printf("%d       ",i);
    }
    printf("\n");
    free(line);
}


