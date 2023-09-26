%{
    #include <stdlib.h>
    int yyerror(char *s);
    #include "y.tab.h"
%}

%%
"if"            { return IF; }
"else"          { return ELSE; }
"elif"          { return ELIF; }
"&&"            { return AND; }
"||"            { return OR; }
"=="            { return EQ; }
"!="            { return NE; }
"<="            { return LE; }
">="            { return GE; }
[!+\-*/()<>=;{}] { return *yytext; }
[a-zA-Z]+       { return VARIABLE; }
[0-9]+          { return INTEGER; }
[ \t\n]+        ;
.               { yyerror("Invalid character"); }
%%

int yywrap(void) {
    return 1;
}