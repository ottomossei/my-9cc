#include "9cc.h"
#include <stdio.h>
#include <stdlib.h>

/// グローバル変数
// my-9cc言語
char *user_input;
// 現在着目しているトークン
Token *token;

// エラーを報告するための関数
// printfと同じ引数を取る
void error(char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");
  exit(1);
}

// char *loc: エラーが発生した位置を示すポインタ
// char *fmt: printf形式のフォーマット文字列
void error_at(char *loc, char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);

  int pos = loc - user_input;
  fprintf(stderr, "%s\n", user_input);
  fprintf(stderr, "%*s", pos, ""); // print pos spaces.
  fprintf(stderr, "^ ");
  vfprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");
  exit(1);
}

int main(int argc, char **argv) {
  if (argc != 2) 
    error("引数の個数が正しくありません");

  // 字句解析と構文解析
  user_input = argv[1];
  token = tokenize();
  Node *node = expr();

  // アセンブリの前半部分を出力
  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");

  // ASTを走査して、アセンブラを生成
  gen(node);

  // 結果はスタックの一番上にあるため、RAXにポップしてプログラムの終了コードとする
  printf("  pop rax\n");
  printf("  ret\n");
  return 0;
}
