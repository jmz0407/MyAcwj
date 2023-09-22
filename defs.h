//
// Created by Administrator on 2023/9/20.
//

#ifndef MYACWJ_DEFS_H
#define MYACWJ_DEFS_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
//todo:Tokens

enum {
    T_EOF, T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT
};

//todo: Token class
class token{
public:
    int Token;
    int intvalue;
    token(int t, int val):Token(t), intvalue(val){};
    token():Token(0), intvalue(0){};
};

//// Token structure
//struct token {
//    int token;
//    int intvalue;
//};

//AST node types
enum{
    A_ADD, A_SUBTRACT, A_MULTIPLY, A_DIVIDE, A_INTLIT
};

class ASTnode{
public:
    int op;
    ASTnode *left;
    ASTnode *right;
    int intvalue;
    ASTnode(int op, ASTnode *left, ASTnode *right, int intvalue):op(op), left(left), right(right), intvalue(intvalue){};
    ASTnode(int op, int intvalue):op(op), left(nullptr), right(nullptr), intvalue(intvalue){};
    ASTnode():op(0), left(nullptr), right(nullptr), intvalue(0){};
};
#endif //MYACWJ_DEFS_H
