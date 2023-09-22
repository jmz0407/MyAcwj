//
// Created by Administrator on 2023/9/21.
//
#include "defs.h"
#include "data.h"
#include "decl.h"

//AST tree functions

//Build and return a generic AST node

ASTnode* mkastnode(int op, ASTnode *left, ASTnode *right, int intvalue){
    //Copy in the fields
    try{
        return new ASTnode(op, left, right, intvalue);
    }
    catch(std::bad_alloc& ba){
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
}

//Make an AST leaf node
ASTnode* mkastleaf(int op, int intvalue){
    return mkastnode(op, nullptr, nullptr, intvalue);
}

// Make a unary minus AST node
ASTnode *mkastunary(int op, ASTnode *left, int intvalue){
    return mkastnode(op, left, nullptr, intvalue);
}