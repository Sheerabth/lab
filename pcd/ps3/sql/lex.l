%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"
    
    int yyerror(char*);
%}

%%

"select"|"SELECT" return SELECT;
"from"|"FROM" return FROM;
"where"|"WHERE" return WHERE;
"as"|"AS" return AS;

"group by"|"GROUP BY" return GROUPBY;
"limit"|"LIMIT" return LIMIT;
"offset"|"OFFSET" return OFFSET;

"or"|"OR" return OR;
"and"|"AND" return AND;

"!=" return NE;
"<=" return LE;
">=" return GE;

[!=<>(),;*] return *yytext;

[0-9]+ return CONSTANT;
[a-zA-Z0-9_]+ return IDENTIFIER;

[ \t\n] ;

. yyerror("invalid character");
%%

int yywrap(void) {
    return 0;
}