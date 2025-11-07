#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int find(int32_t * array,int32_t value,  uint32_t index1,uint32_t index2){
   if (index2 - index1 == 1) {//由题目可知需要插入的数于数组中的数并不相同
                              //所以value一定夹在两个元素之间
      return index2;
   }
   int temp = (index1 + index2) / 2;
   if (value >= array[temp]){ //尾递归
     return find(array,value,temp,index2);}
   else {
     return find(array,value,index1,temp);
   }
}
    

      

int main(){
  int array[] = {5,12,22,34,45,55,67,78,89,98};
  int input;
  scanf("%d",&input);
  uint32_t size = sizeof(array)/sizeof(array[0]);
  //二分查找
  int index;
  index = find(array,input,0,size-1);
  //插入
  int *array_new = malloc((size + 1) * sizeof(int));
  for (uint32_t i = 0; i < index; i++){
    array_new[i] = array[i];
  }
  array_new[index] = input;
  for (uint32_t i = index + 1; i < size + 1;i++){
    array_new[i] = array[i-1];
  }
  printf("array_new = ");
  for (uint32_t i = 0; i < size + 1; i++){
    printf("%d ",array_new[i]);
  }
  printf("\n新插入元素的下标为%d", index);
  }
