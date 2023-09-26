%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"Node.h"
    #include"y.tab.h"

    int yyerror(char*);
%}

%%
"print" return PRINT;

"while" return WHILE;

"if" return IF;
"else" return ELSE;

"||" return OR;
"&&" return AND;

"==" return EQ;
"!=" return NE;
"<=" return LE;
">=" return GE;

[0-9]+ { yylval.iValue = atoi(yytext); return CONSTANT; }
[a-z] { yylval.sIndex = *yytext - 'a'; return IDENTIFIER; }
[=!<>+\-*/{}();] return *yytext;
[ \t\n] ;
. yyerror("Invalid character");
%%

int yywrap(void) {
    return 1;
}