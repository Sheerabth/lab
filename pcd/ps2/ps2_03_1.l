%{
	#include<stdio.h>
%}

%x COMMENT

%%
"*/" {BEGIN(COMMENT);}
<COMMENT>"/*" {BEGIN(INITIAL);}
<COMMENT>.* {}
<COMMENT>\n {}
%%

int yywrap(void) {
	return 1;
}

int main(int argc, char* argv[]) {
	if (argc != 3)  {
		fprintf(stderr, "Usage %s <file>\n", argv[0]);
		return 1;
	}

	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");

	if (yyin == NULL) {
		fprintf(stderr, "Could not open file %s\n", argv[1]);
		return 1;
	}

	if (yyout == NULL) {
		fprintf(stderr, "Could not open file %s\n", argv[2]);
		return 1;
	}

	yylex();
	return 0;
}
