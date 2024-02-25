# 参考
 - [低レイヤを知りたい人のためのCコンパイラ作成入門](https://www.sigbus.info/compilerbook)のノート  
 - [chibicc](https://github.com/rui314/chibicc/)

# 目次
- [参考](#参考)
- [目次](#目次)
- [Step1 (Cとそれに対応するアセンブラ)](#step1-cとそれに対応するアセンブラ)
- [Step2 (電卓レベルの言語の作成)](#step2-電卓レベルの言語の作成)
  - [整数1つをコンパイル](#整数1つをコンパイル)


# Step1 (Cとそれに対応するアセンブラ)
機械語とほぼ1対1で人間にとって読みやすい言語  
`objectdump`の逆アセンブルで、アセンブラが見れる。  
```shell
$ objdump -d -M intel /bin/ls | head -n 9
/bin/ls:     file format elf64-x86-64


Disassembly of section .init:

0000000000004000 <.init>: # 開始アドレスが表示
    4000:       f3 0f 1e fa             endbr64 # セキュリティ要件
    4004:       48 83 ec 08             sub    rsp,0x8 # 解説
```

 - 4004は機械語が入っているメモリアドレスで、プログラムカウンタが0x4004の時に実行される。  
 - RSPというレジスタから8を引く（substract）

ここで、C言語をコンパイルした後に期待するアセンブラを紹介する
```c
// C言語
int main() {
  return 42;
}

// 期待するアセンブリ
.intel_syntax noprefix　// intel記法の採用の宣言
.globl main
main:
        mov rax, 42 // RAXレジスタに42をコピー
        ret

```

 - Intel記法とUNIX等で広く使われるAT&T記法がある。
 - 関数の返値はRAXレジスタにmov（コピー）する

【コラム】  
gccやobjdumpはデフォルトではAT&T記法でアセンブリを出力する。  
どちらの記法を使っても、生成される機械語命令列は同一となる。
```c
mov rbp, rsp   // Intel
mov %rsp, %rbp // AT&T

mov rax, 8     // Intel
mov $8, %rax   // AT&T

mov [rbp + rcx * 4 - 8], rax // Intel
mov %rax, -8(rbp, rcx, 4)    // AT&T
```
関数呼び出しの場合は下記
```c
// C言語
int plus(int x, int y) {
  return x + y;
}

int main() {
  return plus(3, 4);
}

// 期待するアセンブリ
.intel_syntax noprefix
.globl plus, main

plus:
        add rsi, rdi // RSIレジスタとRDIレジスタを足した結果がRSIレジスタに書き込む
        mov rax, rsi // RAXレジスタにRSIレジスタをコピー
        ret // スタックからアドレスを1つポップし、そのアドレスにジャンプ

main:
        mov rdi, 3 // RDIレジスタに3をコピー
        mov rsi, 4 // RDIレジスタに4をコピー
        call plus
        ret
```

 - 関数コール時の第一引数はRDIレジスタにmov（コピー）する
 - 関数コール時の第二引数はRDIレジスタにmov（コピー）する
 - x86-64の整数演算命令(add)は通常2つのレジスタしか受け取らないため、第1引数のレジスタの値を上書きする形で結果が保存される
 - retはスタックからアドレスを1つポップし、そのアドレスにジャンプする

