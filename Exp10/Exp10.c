#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 
struct Quadruple { 
char op; 
char arg1[10]; 
char arg2[10]; 
char result[10]; 
}; 
struct Quadruple quads[20]; 
char stack[20][10]; 
int top = -1, tempCount = 1, quadCount = 0; 
void push(char *str) { 
strcpy(stack[++top], str); 
} 
char* pop() { 
return stack[top--]; 
} 
void generate(char op) { 
char arg2[10], arg1[10], result[10]; 
strcpy(arg2, pop()); 
strcpy(arg1, pop()); 
sprintf(result, "t%d", tempCount++); 
quads[quadCount].op = op; 
strcpy(quads[quadCount].arg1, arg1); 
strcpy(quads[quadCount].arg2, arg2); 
strcpy(quads[quadCount].result, result); 
quadCount++; 
push(result); 
} 
int main() { 
char postfix[100]; 
printf("Enter postfix expression: "); 
scanf("%s", postfix); 
for (int i = 0; i < strlen(postfix); i++) { 
if (isalnum(postfix[i])) { 
char op[2] = { postfix[i], '\0' }; 
push(op); 
} else { 
generate(postfix[i]); 
} 
} 
printf("\nQuadruple Table:\n"); 
printf("%-10s %-10s %-10s %-10s\n", "OP", "ARG1", "ARG2", "RESULT"); 
for (int i = 0; i < quadCount; i++) { 
printf("%-10c %-10s %-10s %-10s\n", quads[i].op, quads[i].arg1, quads[i].arg2, 
quads[i].result); 
} 
return 0; 
}