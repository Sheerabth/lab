%{
    #include <stdlib.h>
    int yyerror(char *s);
    #include "y.tab.h"
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
[a-zA-Z]+       return VARIABLE;
[0-9]+          return INTEGER;
[ \t\n]+        ;
.               yyerror("Invalid character");
%%

int yywrap(void) {
    return 1;
}