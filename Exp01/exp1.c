#include <stdio.h> 
#include <ctype.h> 
 
#define MAX_INPUT_SIZE 100 
 
void lexicalAnalyzer(char *input) { 
    int i = 0; 
    while (input[i] != '\0') { 
        if (isspace(input[i])) {  
            i++;  
            continue;  
        } 
        if (isalpha(input[i])) { 
                                                                                            // Enrollment No:  
            printf("Identifier: %c\n", input[i]); 
        } else if (isdigit(input[i])) {   
            printf("Number: %c\n", input[i]); 
        } else {   
            printf("Symbol: %c\n", input[i]); 
        } 
        i++; 
    } 
} 
 
int main() { 
    char input[MAX_INPUT_SIZE]; 
 
    printf("Enter input string: "); 
    fgets(input, MAX_INPUT_SIZE, stdin); 
 
    lexicalAnalyzer(input); 
 
    return 0; 
}