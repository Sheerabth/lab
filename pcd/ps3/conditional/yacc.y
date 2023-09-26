%token INTEGER VARIABLE IF ELSE ELIF
%right '='
%left OR
%left AND
%nonassoc '!'
%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS


%{
    #include<stdio.h>
    int yyerror(char *);
    int yylex(void);
%}

%%

program:
    statements { printf("Valid expression\n"); }
    ;

block: '{' statements '}'

statements: 
    statements expr ';'
    | statements conditional
    |
    ;

conditional:
    if_else_if
    | conditional ELSE block

if_else_if:
    IF '(' expr ')' block
    | if_else_if ELIF '(' expr ')' block

expr:
    VARIABLE '=' expr
    | expr OR expr
    | expr AND expr
    | '!' expr
    | expr '<' expr
    | expr '>' expr
    | expr NE expr
    | expr EQ expr
    | expr GE expr
    | expr LE expr
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '-' INTEGER %prec UMINUS
    | '-' VARIABLE %prec UMINUS
    | '(' expr ')'
    | INTEGER
    | VARIABLE
    ;

%%

int yyerror(char* s) {
    fprintf(stderr, "%s\n", s);
    return 0;
}

int main() {
    yyparse();
    return 0;
}