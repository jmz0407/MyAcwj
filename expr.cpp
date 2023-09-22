//
// Created by Administrator on 2023/9/21.
//

#include "defs.h"
#include "data.h"
#include "decl.h"

//parsing of expressions

//Parse a primary factor and return an AST node representing it.
static ASTnode* primary(void){
    ASTnode* n;
    //For an INTLIT token, make a leaf AST node for it and scan in the next token.
    //Otherwise, a syntax error for any other token type.
    switch(Token.Token){
        case T_INTLIT:
            n = mkastleaf(A_INTLIT, Token.intvalue);
            scan(&Token);
            return n;
        default:
            fprintf(stderr, "syntax error on line %d\n", Line);
            exit(1);
    }
}

// Convert a token into an AST operation.
int arithop(int tok) {
    switch (tok) {
        case T_PLUS:
            return (A_ADD);
        case T_MINUS:
            return (A_SUBTRACT);
        case T_STAR:
            return (A_MULTIPLY);
        case T_SLASH:
            return (A_DIVIDE);
        default:
            fprintf(stderr, "unknown token in arithop() on line %d\n", Line);
            exit(1);
    }
}


//Return an AST node whose root is a binary operator.
ASTnode* binexpr(){
    ASTnode *n, *left, *right;
    int nodetype;

    //Get the integer literal on the left.
    //Fetch the next token at the same time.
    left = primary();

    //If no tokens left, return just the left node.
    if(Token.Token == T_EOF)
        return (left);

    //Convert the token into a node type.
    nodetype = arithop(Token.Token);

    //Get the next token in the expression.
    scan(&Token);

    //Recursively get the right-hand tree
    right = binexpr();

    //Now build a tree with both sub-trees.
    n = mkastnode(nodetype, left, right, 0);
    return (n);
}