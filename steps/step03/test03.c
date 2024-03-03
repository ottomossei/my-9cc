#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Token Token;

// トークン型
// 自己参照構造体とすることで、
// リンクリストや木などの再帰的なデータ構造を実装できる
struct Token {
  Token *next;  // 次の入力トークン
  int val;
};

// 新しいトークンを作成してcurに繋げる
Token *new_token(Token *cur, char *str) {
  Token *tok = calloc(1, sizeof(Token));
  cur->next = tok;
  return tok;
}

Token *tokenize(char *p) {
  Token head;  // 先頭のToken
  head.next = NULL;
  Token *cur = &head;  // CurrentのToken

  while (*p) {
    printf("[%s]\n", p);
    cur = new_token(cur, p);
    cur->val = strtol(p, &p, 10);
  }
  return head.next;
}

int main() {
  Token *token;
  char *p = "987+654";

  // トークン作成
  printf("tokenize\n");
  token = tokenize(p);

  // 出力
  printf("output\n");
  for (int i = 0; i < 2; i++) {
    printf("%d\n", token->val);
    token = token->next;
  }

  printf("Ok\n");
}
