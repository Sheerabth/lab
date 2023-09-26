%{
    #include<stdio.h>
    #include"y.tab.h"

    int yyerror(char*);
%}

%%

"int" return DATATYPE;
"float" return DATATYPE;
"double" return DATATYPE;
"char" return DATATYPE;
[a-z] return IDENTIFIER;
[0-9]+ return CONSTANT;
[;=*] return *yytext;
[ \t\n] ;
. yyerror("invalid input");
%%

int yywrap(void) {
    return 1;
}