#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char *keywords[] = {"int", "float", "char", "double", "return", "void", "if", "else", "for", "while"};
int isKeyword(char *word) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isInTable(char table[MAX][30], int size, char *item) {
    for (int i = 0; i < size; i++) {
        if (strcmp(table[i], item) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp = fopen("program.txt", "r");
    if (!fp) {
        printf("Cannot open program.txt\n");
        return 1;
    }

    char SYMTAB[MAX][30], LITTAB[MAX][30];
    int symCount = 0, litCount = 0;
    char line[256], word[50];
    int i, j;

    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '#') continue;  // Skip preprocessor lines

        int inString = 0;
        i = 0;
        while (line[i] != '\0') {
            if (line[i] == '"') {
                inString = !inString;
                i++;
                continue;
            }

            if (inString || line[i] == '%' || line[i] == '\\') {
                i++;
                continue;  // Skip string contents and format specifiers
            }

            if (isalnum(line[i]) || line[i] == '_' || line[i] == '.') {
                j = 0;
                while (isalnum(line[i]) || line[i] == '_' || line[i] == '.') {
                    word[j++] = line[i++];
                }
                word[j] = '\0';

                if (!isKeyword(word)) {
                    if (isalpha(word[0])) {
                        if (!isInTable(SYMTAB, symCount, word)) {
                            strcpy(SYMTAB[symCount++], word);
                        }
                    } else if (isdigit(word[0])) {
                        if (!isInTable(LITTAB, litCount, word)) {
                            strcpy(LITTAB[litCount++], word);
                        }
                    }
                }
            } else {
                i++;
            }
        }
    }

    fclose(fp);

    printf("----- SYMBOL TABLE -----\n");
    for (int k = 0; k < symCount; k++) {
        printf("%s\n", SYMTAB[k]);
    }

    printf("\n----- LITERAL TABLE -----\n");
    for (int k = 0; k < litCount; k++) {
        printf("%s\n", LITTAB[k]);
    }

    return 0;
}
