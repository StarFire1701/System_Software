%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<ctype.h>
%}

%%

[0-9]+\.[0-9]+ { printf("\nFloating point NUMBERS: %s\n", yytext); }
[0-9]+         { printf("\nNUMBERS: %s\n", yytext); }

%%

int main(){
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}
