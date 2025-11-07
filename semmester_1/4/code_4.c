#include <stdio.h>
#include <stdint.h>
int32_t main(){
  char s[80] = {0};
  char desc[80] = {0}; //经删除后的数组
  printf("输入字符串\n");
  scanf("%79s",s);
  char delete;
  getchar();
  printf("输入字符\n");
  scanf("%c",&delete);
  uint8_t count = 0;
  for (uint8_t i = 0,j = 0; i < 80; i++,j++){
    if (s[i] == '\0'){
      break;
    }


    if (s[i] != delete){
      desc[j] = s[i];
    }
    else {
      count += 1;
      j -= 1;
    }
  }
  if (count == 0){
    printf("%s未删除字符",s);
  } else{
    printf("%s被删除%hu个指定字符后更新为%s",s,count,desc);
  }
}
