%{
    #include<stdio.h>
    #include<stdlib.h>
    int yyerror(char*);
    int yylex(void);
%}

%token SELECT FROM AS WHERE GROUP_BY LIMIT OFFSET IDENTIFIER CONSTANT INSERT_INTO VALUES UPDATE SET DELETE_FROM

%left OR
%left AND
%left '!'
%left '=' NE 
%left '<' LE '>' GE

%%
program:
    program statement { printf("Valid statement\n"); }
    |
    ;

statement:
    select ';'
    | insert ';'
    | update ';'
    | delete ';'

select:
    SELECT projection FROM IDENTIFIER where groupBy limit offset
    ;

insert:
    INSERT_INTO IDENTIFIER '(' columns ')' VALUES '(' values ')'
    | INSERT_INTO IDENTIFIER VALUES '(' values ')'
    ;

update:
    UPDATE IDENTIFIER SET updateValues WHERE expr
    ;

delete:
    DELETE_FROM IDENTIFIER where
    ;

updateValues:
    updateValues ',' updateValue
    | updateValue

updateValue:
    IDENTIFIER '=' CONSTANT
    ;

projection:
    '*'
    | columns
    ;

values:
    values ',' CONSTANT
    | CONSTANT
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
    GROUP_BY IDENTIFIER
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
