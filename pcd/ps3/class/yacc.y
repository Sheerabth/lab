%{
    #include<stdio.h>
    #include<stdlib.h>

    int yyerror(char*);
    int yylex(void);
%}

%token CONSTANT IDENTIFIER DATATYPE ACCESS CLASS

%%

program:
    class { printf("Valid class\n"); }

class:
    CLASS IDENTIFIER '{' statements '}' ';'
    | CLASS IDENTIFIER ':' inheritances '{' statements '}' ';'
    ;


inheritances:
    inheritances ',' inheritance
    | inheritance

inheritance:
    ACCESS IDENTIFIER
    | IDENTIFIER
    ;

statements:
    statements accessStatement
    | accessStatement
    ;

accessStatement:
    statement
    | ACCESS ':' statement
    ;

statement:
    DATATYPE lvalue ';'
    | DATATYPE lvalue '=' rvalue ';'
    | lvalue '=' rvalue ';'
    | function ';'
    | function '{' '}'
    ;

function:
    DATATYPE lvalue '('')'
    | DATATYPE lvalue '(' parameters ')'
    ;

parameters:
    parameters ',' parameter
    | parameter
    ;

parameter:
    DATATYPE lvalue
    | DATATYPE lvalue '=' CONSTANT
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