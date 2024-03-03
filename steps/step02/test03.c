#include <stdio.h>
#include <stdlib.h>

// strtolは「str to long」から命名されている
int main() {
  char *p = "123+456+789";
  while (*p) {
    // 第一引数は処理対象の文字列のポインタ
    // 第二引数はstrtol 関数が変換を終えた文字列の次の文字を指すポインタ
    // 第三引数は進数を示す。
    printf("%ld\n", strtol(p, &p, 10));
  }
}

// 123
// 456
// 789
