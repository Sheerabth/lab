%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"

    int yyerror(char*);
%}

%%

"class" return CLASS;
"private" return ACCESS;
"public" return ACCESS;
"void" return DATATYPE;
"int" return DATATYPE;
"float" return DATATYPE;
"double" return DATATYPE;
"char" return DATATYPE;
[a-zA-Z_]+ return IDENTIFIER;
[0-9]+ return CONSTANT;
[*=,:;(){}] return *yytext;
[ \t\n] ;
. {printf("%s", yytext); yyerror("invalid input");}
%%

int yywrap(void) {
    return 1;
}