%{
#include <stdio.h>
#include <stdlib.h>
%}

%token IDENTIFIER

%%

input: IDENTIFIER { printf("Valid identifier\n"); }
     | error      { printf("Invalid identifier\n"); yyerrok; }
     ;

%%

int main() {
    printf("Enter an identifier:\n");
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}
