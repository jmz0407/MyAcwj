//
// Created by Administrator on 2023/9/20.
//
#include "defs.h"
#include "data.h"
#include "decl.h"

//TODO: Return the position of the next token in the input stream
static int chrpos(char *s, int c) {
    char *p;
    p = strchr(s, c);

    return (p ? p - s : -1);
}

//Overload to Cpp
static int chrpos(const std::string& str, char c){
    size_t pos = str.find(c);
    if(pos != std::string::npos)
        return static_cast<int>(pos);
    else
        return -1;
}


static int next(void){
    int c;
    if(Putback){
        c = Putback;
        Putback = 0;
        return c;
    }
    c = fgetc(Infile);
    if(c == '\n')
        Line++;
    return c;
}

//TODO: Overload to Cpp
//static int Cnext(void){
//    int c;
//    if(Putback){
//        c = Putback;
//        Putback = 0;
//        return c;
//    }
//    c = Infile->get();
//    if(c == '\n')
//        Line++;
//    return c;
//}

//TODO: Put back an unwanted character
static void putback(int c){
    Putback = c;
}

/*TODO: Skip past input that we don't need to deal with
 * for example whitespace and newlines. return the first
 * character we do need to deal with.
 */
static int skip(void){
    int c;
    c = next();
    while(c == ' ' || c == '\t' || c == '\n' || c == '\r'){
        c = next();
    }

    return c;
}

/*TODO: Scan and return an Integer literal
 * value from the input file. Store the value
 * as a string in Text.
 */
 static int scanint(int c){
     int k, val = 0;

     //Connvert each character into an int value
     while((k = chrpos("0123456789", c)) >= 0){
         val = val * 10 +k;
         c = next();
     }
     //We hit a non-integer character, put it back
     putback(c);
     return val;
 }

 int peek(){
     int c = next();
     putback(c);
     return c;
 }
 //Overload to Cpp
// static int scanint(){
//     while(std::isdigit(peek())){
//        k = next() - '0';
//        val = val * 10 + k;
//     }
//
//     return val;
// }

 /*TODO: Scan and return the next token found in the input.
  * Return 1 if token valid , o if no tokens left.
  */
 int scan(class token* t){
     int c;
     //Skip whitespace and newlines
     c = skip();

     //Determine the token basd on the input character
     switch(c) {
         case EOF:
             t->Token = T_EOF;
             return (0);
         case '+':
             t->Token = T_PLUS;
             break;
         case '-':
             t->Token = T_MINUS;
             break;
         case '*':
             t->Token = T_STAR;
             break;
         case '/':
             t->Token = T_SLASH;
             break;
         default:
             //If it is a digit, scan the literal interger value in
             if (std::isdigit(c)) {
                 t->intvalue = scanint(c);
                 t->Token = T_INTLIT;
                 break;
             }
             printf("Unrecongnized character %c on line %d\n", c, Line);
            exit(1);
        }
        return (1);
 }
