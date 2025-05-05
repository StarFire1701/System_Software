
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
char input[100]; 
int i = 0; 
char lookahead; 
void E(); 
void EPrime(); 
void T(); 
void TPrime(); 
void F(); 
void match(char expected) { 
if (lookahead == expected) { 
i++; 
lookahead = input[i]; 
} else { 
printf("Error: Expected '%c' but found '%c'\n", expected, lookahead); 
exit(1); 
} 
} 
void E() { 
T(); 
EPrime(); 
} 
void EPrime() { 
if (lookahead == '+') { 
match('+'); 
T(); 
EPrime(); 
} 
// else epsilon (do nothing) 
} 
void T() { 
F(); 
TPrime(); 
} 
void TPrime() { 
if (lookahead == '*') { 
match('*'); 
F(); 
TPrime(); 
} 
} 
// else epsilon (do nothing) 
void F() { 
if (lookahead == 'i') { 
match('i'); 
} else if (lookahead == '(') { 
match('('); 
E(); 
match(')'); 
} else { 
printf("Error: Invalid symbol '%c'\n", lookahead); 
exit(1); 
} 
} 
int main() { 
printf("Enter the input string ending with $ (e.g., i+i*i$): "); 
scanf("%s", input); 
lookahead = input[0]; 
E(); 
if (lookahead == '$') { 
printf("The input string is successfully parsed.\n"); 
} else { 
printf("Error: Unexpected symbol '%c' at end.\n", lookahead); 
} 
return 0; 
} 