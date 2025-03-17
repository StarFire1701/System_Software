%{
#include "y.tab.h"
%}

%%

[a-zA-Z_][a-zA-Z0-9_]*   { return IDENTIFIER; }
\n                       { return 0; }  // End input on a new line
.                        { return yytext[0]; }  // Pass unknown characters

%%

int yywrap() { return 1; }
