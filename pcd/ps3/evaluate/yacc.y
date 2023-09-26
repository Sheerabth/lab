%{
    #include<stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include "nodeType.h"

    int yyerror(char*);
    int yylex(void);
    
    Node* allocNode();
    
    Node* addConstant(int value);
    Node* addIdentifier(int index);
    Node* addOperation(int operator, int no_of_operands, ...);
    
    int exec(Node* node);

    int sym[26];
%}

%union {
    int iValue;
    char sIndex;
    Node* nodePtr;
};

%token<iValue> INTEGER
%token<sIndex> VARIABLE
%token WHILE IF PRINT


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

%type<nodePtr> expr loop conditional statement statements

%%

program:
    function { exit(0); }
    ;

function:
    function statement { exec($2); }
    |
    ;

statements: 
    statement
    | statements statement { $$ = addOperation(';', 2, $1, $2); }
    ;

statement:
    ';' { $$ = NULL; }
    | expr ';'
    | PRINT expr ';' { $$ = addOperation(PRINT, 1, $2); }
    | '{' statements '}' { $$ = $2; }
    | loop
    | conditional
    ;


loop:
    WHILE '(' expr ')' statement { $$ = addOperation(WHILE, 2, $3, $5); }

conditional:
    IF '(' expr ')' statement %prec IFX { $$ = addOperation(IF, 2, $3, $5); }
    | IF '(' expr ')' statement ELSE statement { $$ = addOperation(IF, 3, $3, $5, $7); }
    ;

expr:
    VARIABLE '=' expr { $$ = addOperation('=', 2, addIdentifier($1), $3); }
    | expr OR expr { $$ = addOperation(OR, 2, $1, $3); }
    | expr AND expr { $$ = addOperation(AND, 2, $1, $3); }
    | '!' expr { $$ = addOperation('!', 1, $2); }
    | expr '<' expr { $$ = addOperation('<', 2, $1, $3); }
    | expr '>' expr { $$ = addOperation('>', 2, $1, $3); }
    | expr NE expr { $$ = addOperation(NE, 2, $1, $3); }
    | expr EQ expr { $$ = addOperation(EQ, 2, $1, $3); }
    | expr GE expr { $$ = addOperation(GE, 2, $1, $3); }
    | expr LE expr { $$ = addOperation(LE, 2, $1, $3); }
    | expr '+' expr { $$ = addOperation('+', 2, $1, $3); }
    | expr '-' expr { $$ = addOperation('-', 2, $1, $3); }
    | expr '*' expr { $$ = addOperation('*', 2, $1, $3); }
    | expr '/' expr { $$ = addOperation('/', 2, $1, $3); }
    | '-' expr %prec UMINUS { $$ = addOperation(UMINUS, 1, $2); }
    | '(' expr ')' { $$ = $2; }
    | INTEGER { $$ = addConstant($1); }
    | VARIABLE { $$ = addIdentifier($1); }
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

Node* allocNode() {
    Node* node;
    if ((node = malloc(sizeof(Node))) == NULL)
        yyerror("out of memory");
    return node;
}

Node* addConstant(int value) {
    Node* node = allocNode();

    node->type = T_CONSTANT;
    node->constant.value = value;
    return node;
}

Node* addIdentifier(int index) {
    Node* node = allocNode();

    node->type = T_IDENTIFIER;
    node->identifier.index = index;
    return node;
}

Node* addOperation(int operator, int no_of_operands, ...) {
    Node* node = allocNode();

    node->type = T_OPERATION;
    node->operation.operator = operator;
    node->operation.no_of_operands = no_of_operands;

    va_list argPtr;
    va_start(argPtr, no_of_operands);
    for (int i=0; i < no_of_operands; i++)
        node->operation.operands[i] = va_arg(argPtr, Node*);
    va_end(argPtr);
    return node; 
}

int exec(Node* node) {
    if (!node)
        return 0;
    switch (node->type) {
        case T_CONSTANT:
            return node->constant.value;
        
        case T_IDENTIFIER:
            return sym[node->identifier.index];
        
        case T_OPERATION:
            switch (node->operation.operator) {
                case WHILE:
                    while (exec(node->operation.operands[0]))
                        exec(node->operation.operands[1]);
                    return 0;

                case IF:
                    if (exec(node->operation.operands[0]))
                        exec(node->operation.operands[1]);
                    else if (node->operation.no_of_operands > 2)
                        exec(node->operation.operands[2]);
                    return 0;

                case PRINT:
                    printf("%d\n", exec(node->operation.operands[0]));
                    return 0;

                case ';':
                    exec(node->operation.operands[0]);
                    return exec(node->operation.operands[1]);

                case '=':
                    return sym[node->operation.operands[0]->identifier.index] = exec(node->operation.operands[1]);
                
                case OR:
                    return exec(node->operation.operands[0]) || exec(node->operation.operands[1]);

                case AND:
                    return exec(node->operation.operands[0]) && exec(node->operation.operands[1]);
                
                case '!':
                    return !exec(node->operation.operands[0]);
                
                case NE:
                    return exec(node->operation.operands[0]) != exec(node->operation.operands[1]);
                
                case EQ:
                    return exec(node->operation.operands[0]) == exec(node->operation.operands[1]);
                
                case '<':
                    return exec(node->operation.operands[0]) < exec(node->operation.operands[1]);
                
                case '>':
                    return exec(node->operation.operands[0]) > exec(node->operation.operands[1]);
                
                case GE:
                    return exec(node->operation.operands[0]) >= exec(node->operation.operands[1]);
                
                case LE:
                    return exec(node->operation.operands[0]) <= exec(node->operation.operands[1]);
                
                case '+':
                    return exec(node->operation.operands[0]) + exec(node->operation.operands[1]);
                
                case '-':
                    return exec(node->operation.operands[0]) - exec(node->operation.operands[1]);

                case '*':
                    return exec(node->operation.operands[0]) * exec(node->operation.operands[1]);
                
                case '/':
                    return exec(node->operation.operands[0]) / exec(node->operation.operands[1]);

                case UMINUS:
                    return -exec(node->operation.operands[0]);
            }
    }
    return 0;
}