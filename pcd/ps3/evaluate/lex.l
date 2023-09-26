%{
    #include <stdlib.h>
    #include "nodeType.h"
    #include "y.tab.h"
    int yyerror(char *s);
%}

%%
"print"         return PRINT;
"while"         return WHILE;
"if"            return IF;
"else"          return ELSE;
"&&"            return AND;
"||"            return OR;
"=="            return EQ;
"!="            return NE;
"<="            return LE;
">="            return GE;
[!+\-*/()<>=;{}] return *yytext;
[a-z]           { yylval.sIndex = *yytext - 'a'; return VARIABLE; }
[0-9]+          { yylval.iValue = atoi(yytext); return INTEGER; }
[ \t\n]+        ;
.               yyerror("Invalid character");
%%

int yywrap(void) {
    return 1;
}