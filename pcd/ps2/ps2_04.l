%{
#include<stdio.h>
%}

%%
[ ]+ {fprintf(yyout, " ");}
[\t]+ {fprintf(yyout, "\t");}
[\n]+ {fprintf(yyout, "\n");}
%%

int yywrap(){ return 1; }

int main(){
	extern FILE *yyin, *yyout;
 
    yyin = fopen("pcd/ps2/files/input.txt", "r");
    yyout = fopen("pcd/ps2/files/output.txt", "w");
	yylex();
	return 0;
}