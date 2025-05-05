%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%

[0-9]+          { yylval = atoi(yytext); return ID; }
"+"             { return PLUS; }
"*"             { return MUL; }
"("             { return LPAREN; }
")"             { return RPAREN; }
[ \t\n]         { /* Ignore whitespace */ }
.               { printf("Invalid character: %s\n", yytext); }

%%
