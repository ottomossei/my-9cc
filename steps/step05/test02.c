#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// callocとは、"contiguous allocation"の略で、
// 連続的なヒープの割り当てを意味する。

int main() {
  int n = 5;                               // 5要素の配列を作成
  printf("sizeof(n) : %ld\n", sizeof(n));  // nの型は4bytesなので、4が出力
  printf("sizeof(int) : %ld\n", sizeof(int));  // 直接、型を指定しても同様

  // arg1: 5要素分
  // arg2: nのサイズのバイト分
  // のメモリを割り当て
  // したがって、5*4=20バイトのメモリを割り当てる。
  int* array = calloc(n, sizeof(n));

  if (array == NULL) {
    fprintf(stderr, "メモリ割り当てに失敗\n");
    return 1;
  }

  // 配列を使用
  for (int i = 0; i < n; i++) {
    array[i] = i;
    printf("%d \n", array[i]);  // 初期化されているため、全ての要素は0
  }

  // メモリを解放
  free(array);

  // arrayは解放済みのポインタ（ダングリングポインタ）であるため、
  // 以降はアクセスすると未定義動作ではなくSegmentation faultとなるNULLを代入
  array = NULL;

  //   printf("%d \n", array[3]);  // Segmentation fault

  return 0;
}
