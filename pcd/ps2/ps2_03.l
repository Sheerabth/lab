%{
#include<stdio.h>
%}

%%
"/*".*[ \n]* {fprintf(yyout, "");}
.*"*/"[ \n]* {fprintf(yyout, "");}
"//".*[\n] {fprintf(yyout, "");}
%%

int yywrap(){ return 1; }

int main(){
	extern FILE *yyin, *yyout;
 
    yyin = fopen("pcd/ps2/files/input.cpp", "r");
    yyout = fopen("pcd/ps2/files/output.cpp", "w");
	yylex();
	return 0;
}