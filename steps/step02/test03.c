#include <stdio.h>
#include <stdlib.h>

// strtolは「str to long」から命名されている
int main() {
  char *p = "123+456+789";
  while (*p) {
    // 第三引数は進数を示す。
    // 符号等の数値でない値は、それを区切りとして次の数値の読み取りに移る
    printf("%ld\n", strtol(p, &p, 10));
  }
}

// 123
// 456
// 789
