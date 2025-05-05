#include <stdio.h> 
#include <string.h> 
int main() { 
char prod[10], alpha[10], beta[10]; 
int i = 0, j = 0, k = 0, l = 0; 
printf("Enter production (format A->Aa|b): "); 
scanf("%s", prod); 
char nonTerm = prod[0]; 
i = 3; 
// Check for left recursion 
if (prod[3] == nonTerm) { 
i++; // Skip the left recursion character 
while (prod[i] != '|' && prod[i] != '\0') { 
alpha[j++] = prod[i++]; 
} 
alpha[j] = '\0'; 
if (prod[i] == '|') { 
i++; 
} 
while (prod[i] != '\0') { 
beta[k++] = prod[i++]; 
} 
beta[k] = '\0'; 
printf("The production has left recursion.\n"); 
printf("After eliminating left recursion:\n"); 
printf("%c -> %s%c'\n", nonTerm, beta, nonTerm); 
printf("%c' -> %s%c' | ε\n", nonTerm, alpha, nonTerm); 
} else { 
printf("The production has no left recursion.\n"); 
printf("Production: %s\n", prod); 
} 
return 0; 
} 