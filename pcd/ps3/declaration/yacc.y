%{
    #include<stdio.h>
    #include<stdlib.h>

    int yyerror(char*);
    int yylex(void);
%}

%token DATATYPE IDENTIFIER CONSTANT

%%

program:
    statements { printf("Valid statements\n"); }

statements:
    statements statement ';'
    | statement ';'


statement:
    DATATYPE lvalue
    | DATATYPE lvalue '=' rvalue
    | lvalue '=' rvalue
    ;

lvalue: 
    '*' lvalue 
    | IDENTIFIER
    ;

rvalue:
    lvalue
    | CONSTANT
    ;

%%

int yyerror(char* s) {
    fprintf(stderr, "%s\n", s);
    return 1;
}

int main() {
    yyparse();
    return 0;
}