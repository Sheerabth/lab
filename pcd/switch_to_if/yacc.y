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
    FILE *fptr ; 
    
    fptr = fopen(“ouput.txt”, “w”);
%}

%union{
    int iValue;
    int sIndex;
    Node* nodePtr;
};

%token IF WHILE PRINT SWITCH CASE EXPR BLOCK STMTS

%token<iValue> CONSTANT
%token<sIndex> IDENTIFIER
%type<nodePtr> expr statement statements conditional loop switch cases

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
    program statement { print($2); }
    |
    ;

statement:
    ';' { $$ = NULL; }
    | expr ';' { $$ = createOperation(EXPR, 1, $1); }
    | PRINT expr ';' { $$ = createOperation(PRINT, 1, $2); }
    | '{' statements '}' { $$ = createOperation(BLOCK, $2); }
    | conditional
    | loop
    | switch
    ;

switch:
    SWITCH '(' expr ')' '{' cases '}' { $$ = createOperation(SWITCH, 2, $3, $6); }

cases:
    CASE CONSTANT ':' statement { $$ = createOperation(CASE, 2, createConstant($2), $4); }
    | cases CASE CONSTANT ':' statement { $$ = createOperation(CASE, 3, createConstant($3), $5, $1); }
    ;

statements:
    statement
    | statements statement { $$ = createOperation(STMTS, 2, $1, $2); }
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

int printCases(Node* node, int target) {
    OperationNode operation = node->operation;
    if (operation.no_of_operands == 2 && operation.operands[0]->constant.value == target) {
        exec(operation.operands[1]);
        return 1;
    }
    
    else if (operation.no_of_operands == 3 && execCases(operation.operands[2], target) == 0 && operation.operands[0]->constant.value == target) {
        exec(operation.operands[1]);
        return 1;
    }
    return 0;

}

int print(Node* node) {
    if (!node)
        return 0;
    switch (node->type) {
        case T_CONSTANT:
            fprintf(fptr, "%d", node->constant.value);
            return 0;

        case T_IDENTIFIER:
            fprintf(fptr, "%c", sym[node->identifier.index]);
            return 0;

        case T_OPERATION:
            Node** operands = node->operation.operands;
            switch (node->operation.operator) {
                case SWITCH:
                    fprintf(fptr, "switch (");
                    print(operands[1]);
                    fprintf(fptr, ")\n");
                    execCases(operands[1], exec(operands[0]));
                    return 0;

                case WHILE:
                    fprintf(fptr, "while (");
                    print(operands[1]);
                    fprintf(fptr, ")\n");
                    print(operands[1]);
                    return 0;

                case IF:
                    if (node->operation.no_of_operands == 2)
                        fprintf(fptr, "if (");
                        print(operands[0]);
                        fprintf(fptr, ")\n");
                        print(operands[1]);
                        return 0;
                    else if (node->operation.no_of_operands == 3)
                        fprintf(fptr, "if (");
                        print(operands[0]);
                        fprintf(fptr, ")\n");
                        print(operands[1]);
                        fprintf(fptr, "else");
                        print(operands[2]);
                        return 0;
                    return 0;

                case EXPR:
                    print(operands[0]);
                    fprintf(fptr, ";\n");
                    return 0;

                case STMTS:
                    print(operands[0]);
                    print(operands[1]);
                    return 0;

                case BLOCK:
                    fprintf(fptr, "{\n");
                    print(operands[0]);
                    fprintf(fptr, "}\n");
                    return 0;

                case PRINT:
                    fprintf(fptr, "PRINT ");
                    print(operands[0]);
                    fprintf(fptr, ";\n");
                    return 0;

                case '=':
                    print(operands[0]);
                    fprintf(fptr, " = ");
                    print(operands[1]);
                    return 0;
                
                case OR:
                    print(operands[0]);
                    fprintf(fptr, " || ");
                    print(operands[1]);
                    return 0;

                case AND:
                    print(operands[0]);
                    fprintf(fptr, " && ");
                    print(operands[1]);
                    return 0;

                case '!':
                    fprintf(fptr, " !");
                    print(operands[0]);
                    return 0;

                case EQ:
                    print(operands[0]);
                    fprintf(fptr, " == ");
                    print(operands[1]);
                    return 0;

                case NE:
                    print(operands[0]);
                    fprintf(fptr, " != ");
                    print(operands[1]);
                    return 0;

                case '<':
                    print(operands[0]);
                    fprintf(fptr, " < ");
                    print(operands[1]);
                    return 0;

                case LE:
                    print(operands[0]);
                    fprintf(fptr, " <= ");
                    print(operands[1]);
                    return 0;

                case '>':
                    print(operands[0]);
                    fprintf(fptr, " > ");
                    print(operands[1]);
                    return 0;

                case GE:
                    print(operands[0]);
                    fprintf(fptr, " >= ");
                    print(operands[1]);
                    return 0;

                case '+':
                    print(operands[0]);
                    fprintf(fptr, " + ");
                    print(operands[1]);
                    return 0;

                case '-':
                    print(operands[0]);
                    fprintf(fptr, " - ");
                    print(operands[1]);
                    return 0;

                case '*':
                    print(operands[0]);
                    fprintf(fptr, " * ");
                    print(operands[1]);
                    return 0;

                case '/':
                    print(operands[0]);
                    fprintf(fptr, " / ");
                    print(operands[1]);
                    return 0;

                case UMINUS:
                    fprintf(fptr, " -");
                    print(operands[0]);
                    return 0;

            }
    }
    return 0;
}

int execCases(Node* node, int target) {
    OperationNode operation = node->operation;
    if (operation.no_of_operands == 2 && operation.operands[0]->constant.value == target) {
        exec(operation.operands[1]);
        return 1;
    }
    
    else if (operation.no_of_operands == 3 && execCases(operation.operands[2], target) == 0 && operation.operands[0]->constant.value == target) {
        exec(operation.operands[1]);
        return 1;
    }
    return 0;

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
                case SWITCH:
                    execCases(operands[1], exec(operands[0]));
                    return 0;

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

                case PRINT:
                    printf("%d\n", exec(operands[0]));
                    return 0;

                case EXPR:
                    return exec(operands[0]);

                case STMTS:
                    exec(operands[0]);
                    return exec(operands[1]);

                case BLOCK:
                    return exec(operands[0]);

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

                case '-':
                    return exec(operands[0]) - exec(operands[1]);

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

