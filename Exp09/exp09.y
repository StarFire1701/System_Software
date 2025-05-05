%{ 
#include <stdio.h> 
#include <stdlib.h> 
int yylex(); 
void yyerror(const char *s); 
%} 
%token ID PLUS MUL LPAREN RPAREN 
%% 
E : T E1 ; 
E1 : PLUS T E1 
| /* empty */ ; 
T : F T1 ; 
T1 : MUL F T1 
| /* empty */ ; 
F : LPAREN E RPAREN 
| ID ; 
%% 
void yyerror(const char *s) { 
printf("Syntax Error: %s\n", s); 
} 
int main() { 
printf("Enter an arithmetic expression:\n"); 
yyparse(); 
printf("Parsing completed successfully.\n"); 
return 0; 
} 