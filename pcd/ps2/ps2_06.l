%{
    #include<stdio.h>
    FILE* yyout_valid;
    FILE* yyout_invalid;
%}

%%
https?:\/\/[a-zA-Z0-9.-]+(\/[a-zA-Z0-9.-]*)* {fprintf(yyout_valid, "%s\n", yytext);}
www\.[a-zA-Z0-9.-]+(\/[a-zA-Z0-9.-]*)* {fprintf(yyout_valid, "%s\n", yytext);}
.* {fprintf(yyout_invalid, "%s\n", yytext);}
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char* argv[]) {
	if (argc != 4)  {
		fprintf(stderr, "Usage %s <input file> <valid output file> <invalid output file>\n", argv[0]);
		return 1;
	}

	yyin = fopen(argv[1], "r");
	yyout_valid = fopen(argv[2], "w");
	yyout_invalid = fopen(argv[3], "w");

	if (yyin == NULL) {
		fprintf(stderr, "Could not open file %s\n", argv[1]);
		return 1;
	}

	if (yyout_valid == NULL) {
		fprintf(stderr, "Could not open file %s\n", argv[2]);
		return 1;
	}

    if (yyout_invalid == NULL) {
		fprintf(stderr, "Could not open file %s\n", argv[3]);
		return 1;
	}

	yylex();
	return 0;
}
