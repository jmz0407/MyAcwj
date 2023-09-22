#include "defs.h"
#define extern_
#include "data.h"
#undef extern_
#include "decl.h"
#include <cerrno>

//Initialize global variables
static void init(){
    Line = 1;
    Putback = '\n';
}

//Print out a usage if started incorrectly
static void usage(char *prog){
    fprintf(stderr, "Usage: %s infile\n", prog);
    exit(1);
}

//List of printable tokens
char *tokstr[] = { "+", "-", "*", "/", "intlit" };

//Loop scanning in all the tokens of input file.
//Print out details of each token found.
static void scanfile(){
    token T;

    while(scan(&T)){
        printf("Token %s", tokstr[T.Token]);
        if(T.Token == T_INTLIT)
            printf(", value %d", T.intvalue);
        printf("\n");
    }
}
    int main() {
        ASTnode *n;
        init();
        const char* filename = "../input06";
        if ((Infile = fopen(filename, "r")) == NULL) {
            fprintf(stderr, "Unable to open %s: %s\n", filename, strerror(errno));
            exit(1);
        }
        printf("Processing %s...\n", filename);
        scan(&Token);
        n = binexpr();
        printf("%d\n", interpretAST(n));
        exit(0);
        for(int i = 1; i < 5; i++) {
            char filename[20]; // 文件名字符串缓冲区
            sprintf(filename, "../input%02d", i); // 根据循环变量构建文件名

            if ((Infile = fopen(filename, "r")) == NULL) {
                fprintf(stderr, "Unable to open %s: %s\n", filename, strerror(errno));
                exit(1);
            }

            printf("Processing %s...\n", filename);

            //scanfile();
            scan(&Token);
            n = binexpr();
            printf("%d\n", interpretAST(n));
            fclose(Infile); // 关闭文件
        }
        return 0;
    }


