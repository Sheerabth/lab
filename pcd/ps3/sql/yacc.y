%{
    #include<stdio.h>
    #include<stdlib.h>
    int yyerror(char*);
    int yylex(void);
%}

%token SELECT FROM AS WHERE GROUPBY LIMIT OFFSET IDENTIFIER CONSTANT

%left OR
%left AND
%left '!'
%left '=' NE 
%left '<' LE '>' GE

%%
program:
    program select { printf("Valid statements\n"); }
    |
    ;

select:
    SELECT projection FROM IDENTIFIER where groupBy limit offset
    ;

projection:
    '*'
    | columns
    ;

columns:
    columns ',' column
    | column
    ;

column:
    IDENTIFIER
    | IDENTIFIER AS IDENTIFIER
    ;

where:
    WHERE expr
    |
    ;

groupBy:
    GROUPBY IDENTIFIER
    |
    ;

limit:
    LIMIT CONSTANT
    |
    ;

offset:
    OFFSET CONSTANT
    |
    ;

expr:
    '!' operand
    | operand AND operand
    | operand OR operand
    | operand '=' operand
    | operand NE operand
    | operand '<' operand
    | operand LE operand
    | operand '>' operand
    | operand GE operand
    | '(' select ')'
    | '(' expr ')'
    ;

operand:
    expr
    | IDENTIFIER
    | CONSTANT
%%

int yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    return 1;
}

int main() {
    yyparse();
    return 0;
}
