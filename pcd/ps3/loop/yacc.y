%token INTEGER VARIABLE IF WHILE PRINT

%nonassoc IFX
%nonassoc ELSE

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

statements: 
    statement
    | statements statement
    ;

statement:
    ';'
    | expr ';'
    | PRINT expr ';'
    | '{' statements '}'
    | loop
    | conditional
    ;


loop:
    WHILE '(' expr ')' statement

conditional:
    IF '(' expr ')' statement %prec IFX
    | IF '(' expr ')' statement ELSE statement
    ;

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