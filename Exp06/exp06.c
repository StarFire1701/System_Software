#include <stdio.h>
#include <string.h>

void leftFactor(char prod[10][100], int n) {
    int done[10] = {0};  // To keep track of factored productions

    for (int i = 0; i < n; i++) {
        if (done[i]) continue;

        char prefix[100];
        int len = strlen(prod[i]);
        char nonTerm = prod[i][0];

        int j = 3; // skip "S->"
        strcpy(prefix, &prod[i][3]);

        for (int k = i + 1; k < n; k++) {
            if (prod[k][0] == nonTerm) {
                char temp[100];
                strcpy(temp, &prod[k][3]);

                int m = 0;
                while (prefix[m] && temp[m] && prefix[m] == temp[m]) {
                    m++;
                }
                prefix[m] = '\0'; // trim to common prefix
            }
        }

        int count = 0;
        if (strlen(prefix) > 0) {
            printf("%c -> %s%c'\n", nonTerm, prefix, nonTerm);

            for (int k = i; k < n; k++) {
                if (prod[k][0] == nonTerm) {
                    char temp[100];
                    strcpy(temp, &prod[k][3]);

                    if (strncmp(temp, prefix, strlen(prefix)) == 0) {
                        printf("%c' -> %s\n", nonTerm,
                               &temp[strlen(prefix)] == NULL ? "ε" : &temp[strlen(prefix)]);
                        done[k] = 1;
                        count++;
                    }
                }
            }

            if (count == 1) {
                // Only one production? No need to factor.
                printf("%s\n", prod[i]);
            }
        } else {
            printf("%s\n", prod[i]);
        }
    }
}

int main() {
    int n;
    char productions[10][100];
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter productions (Format: S->abc):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    printf("\nLeft Factored Grammar:\n");
    leftFactor(productions, n);

    return 0;
}
