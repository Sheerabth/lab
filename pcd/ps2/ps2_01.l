%{
#include<stdio.h>
int alphaCount=0, digitCount=0, spaceCount=0, specialCount=0, lineCount=0, wordCount=0;
%}

%%
[a-zA-Z]{1}[ ] {wordCount++; alphaCount++; spaceCount++;}
[a-zA-Z]{1}[\n] {wordCount++; alphaCount++; lineCount++;}
[a-zA-Z] { alphaCount++; }

[0-9]{1}[ ] {wordCount++; digitCount++; spaceCount++;}
[0-9]{1}[\n] {wordCount++; digitCount++; lineCount++;}
[0-9] { digitCount++; }

[ \t] { spaceCount++; }
[\n] { lineCount++; }

[^a-zA-Z0-9 \t\n]{1}[ ] {wordCount++; specialCount++; spaceCount++;}
[^a-zA-Z0-9 \t\n]{1}[\n] {wordCount++; specialCount++; lineCount++;}
[^a-zA-Z0-9 \t\n]+ { specialCount++; }
%%

int yywrap(){ return 1; }

int main(){
	extern FILE *yyin;
 
    yyin = fopen("pcd/ps2/files/input.txt", "r");
	yylex();
	printf("Number of aplhabets: %d\n", alphaCount);
	printf("Number of digits: %d\n", digitCount);
	printf("Number of spaces: %d\n", spaceCount);
	printf("Number of lines: %d\n", lineCount+1);
	printf("Number of words: %d\n", wordCount);
	printf("Number of special characters: %d\n", specialCount);
	return 0;
}
