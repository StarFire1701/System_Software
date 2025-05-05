%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
extern char *yytext;
%}

%% 
[0-9]+\.[0-9]+     { printf("Floating point NUMBER: %s\n", yytext); }
[0-9]+             { printf("NUMBER: %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
