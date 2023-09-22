//
// Created by Administrator on 2023/9/20.
//

#ifndef MYACWJ_DECL_H
#define MYACWJ_DECL_H
int scan(struct token *t);
int scan(class Token* t);
ASTnode *mkastnode(int op, ASTnode *left, ASTnode *right, int intvalue);
ASTnode *mkastleaf(int op, int intvalie);
ASTnode *binexpr(void);
int interpretAST(ASTnode *n);
#endif //MYACWJ_DECL_H
