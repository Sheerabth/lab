%{
    #include<stdio.h>
    #include<stdarg.h>
    #include<stdlib.h>
    #include"Node.h"

    int yyerror(char*);
    int yylex(void);

    Node* allocNode();
    Node* createConstant(int value);
    Node* createIdentifier(int index);
    Node* createOperation(int operator, int no_of_operands, ...);
    int exec(Node* node);
    
    int sym[26];
%}

%union{
    int iValue;
    int sIndex;
    Node* nodePtr;
};

%token IF WHILE PRINT

%token<iValue> CONSTANT
%token<sIndex> IDENTIFIER
%type<nodePtr> expr statement statements conditional loop

%nonassoc IFX
%nonassoc ELSE

%right '='

%left OR
%left AND
%left '!'

%left EQ NE '<' LE '>' GE

%left '+' '-'
%left '*' '/'

%nonassoc UMINUS

%%

program:
    program statement { exec($2); }
    |
    ;

statements:
    statement
    | statements statement { $$ = createOperation(';', 2, $1, $2); }
    ;

statement:
    ';' { $$ = NULL; }
    | expr ';'
    | PRINT expr ';' { $$ = createOperation(PRINT, 1, $2); }
    | '{' statements '}' { $$ = $2; }
    | conditional
    | loop
    ;

loop:
    WHILE '(' expr ')' statement { $$ = createOperation(WHILE, 2, $3, $5); }
    ;

conditional:
    IF '(' expr ')' statement %prec IFX { $$ = createOperation(IF, 2, $3, $5); }
    | IF '(' expr ')' statement ELSE statement { $$ = createOperation(IF, 3, $3, $5, $7); }

expr:
    IDENTIFIER '=' expr { $$ = createOperation('=', 2, createIdentifier($1), $3); }
    | expr OR expr { $$ = createOperation(OR, 2, $1, $3); }
    | expr AND expr { $$ = createOperation(AND, 2, $1, $3); }
    | '!' expr { $$ = createOperation('!', 1, $2); }
    | expr EQ expr { $$ = createOperation(EQ, 2, $1, $3); }
    | expr NE expr { $$ = createOperation(NE, 2, $1, $3); }
    | expr '<' expr { $$ = createOperation('<', 2, $1, $3); }
    | expr LE expr { $$ = createOperation(LE, 2, $1, $3); }
    | expr '>' expr { $$ = createOperation('>', 2, $1, $3); }
    | expr GE expr { $$ = createOperation(GE, 2, $1, $3); }
    | expr '+' expr { $$ = createOperation('+', 2, $1, $3); }
    | expr '-' expr { $$ = createOperation('-', 2, $1, $3); }
    | expr '*' expr { $$ = createOperation('*', 2, $1, $3); }
    | expr '/' expr { $$ = createOperation('/', 2, $1, $3); }
    | '-' expr %prec UMINUS { $$ = createOperation(UMINUS, 1, $2); }
    | IDENTIFIER { $$ = createIdentifier($1); }
    | CONSTANT { $$ = createConstant($1); }
    | '(' expr ')' { $$ = $2; }
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

Node* allocNode() {
    Node* node;
    if ((node = malloc(sizeof(Node))) == NULL)
        yyerror("No space");
    return node;
}

Node* createConstant(int value) {
    Node* node = allocNode();
    node->type = T_CONSTANT;
    node->constant.value = value;
    return node;
}

Node* createIdentifier(int index) {
    Node* node = allocNode();
    node->type = T_IDENTIFIER;
    node->identifier.index = index;
    return node;
}

Node* createOperation(int operator, int no_of_operands, ...) {
    Node* node= allocNode();
    node->type = T_OPERATION;
    
    node->operation.operator = operator;
    node->operation.no_of_operands = no_of_operands;
    va_list args;
    va_start(args, no_of_operands);
    for (int i=0; i<no_of_operands; i++)
        node->operation.operands[i] = va_arg(args, Node*);
    va_end(args);

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
            Node** operands = node->operation.operands;
            switch (node->operation.operator) {
                case WHILE:
                    while (exec(operands[0]))
                        exec(operands[1]);
                    return 0;

                case IF:
                    if (exec(operands[0]))
                        return exec(operands[1]);
                    else if (node->operation.no_of_operands > 2)
                        return exec(operands[2]);
                    return 0;

                case ';':
                    exec(operands[0]);
                    return exec(operands[1]);

                case PRINT:
                    printf("%d\n", exec(operands[0]));
                    return 0;

                case '=':
                    return sym[operands[0]->identifier.index] = exec(operands[1]);
                
                case OR:
                    return exec(operands[0]) || exec(operands[1]);

                case AND:
                    return exec(operands[0]) && exec(operands[1]);

                case '!':
                    return !exec(operands[0]);

                case EQ:
                    return exec(operands[0]) == exec(operands[1]);

                case NE:
                    return exec(operands[0]) != exec(operands[1]);

                case '<':
                    return exec(operands[0]) < exec(operands[1]);

                case LE:
                    return exec(operands[0]) <= exec(operands[1]);

                case '>':
                    return exec(operands[0]) > exec(operands[1]);

                case GE:
                    return exec(operands[0]) >= exec(operands[1]);

                case '+':
                    return exec(operands[0]) + exec(operands[1]);

                case '*':
                    return exec(operands[0]) * exec(operands[1]);

                case '/':
                    return exec(operands[0]) / exec(operands[1]);

                case UMINUS:
                    return -exec(operands[0]);

            }
    }
    return 0;
}
