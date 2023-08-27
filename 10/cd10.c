#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count = 0, i = 0, l = 0;
char str[100][100];

void gen();

int main() {
    printf("\n CODE GENERATOR \n");
    printf("\n ENTER THREE ADDRESS CODE \n\n");
    do {
        printf("\t");
        gets(str[i]);
        i++;
    } while (strcmp(str[i - 1], "QUIT") != 0);
    i = 0;
    printf("\n ASSEMBLY LANGUAGE CODE: \n");
    while (strcmp(str[i - 1], "QUIT") != 0) {
        gen();
        printf("\n");
        i++;
    }
    printf("\n PRESS ENTER TO EXIT FROM CODE GENERATOR\n");
    getchar();
    return 0;
}

void gen() {
    int j;
    printf("\n");
    for (j = strlen(str[i]) - 1; j >= 0; j--) {
        char reg = 'R';
        if (isdigit(str[i][j]) || (isalpha(str[i][j])) ||
            str[i][j] == '+' || str[i][j] == '-' || str[i][j] == '*' || 
            str[i][j] == '/' || str[i][j] == ' ' || str[i][j] == '|' ||
            str[i][j] == '&' || str[i][j] == ':' || str[i][j] == '=') {
            switch (str[i][j]) {
                case '+':
                    printf("\n\tMOV\t%c,%c%d;", str[i][j - 1], reg, count);
                    break;
                case '-':
                case '*':
                case '/':
                case '|':
                    printf("\n\tADD\t%c,%c%d;", str[i][j + 1], reg, count);
                    break;
                case '&':
                    printf("\n\tAND\t%c,%c%d;", str[i][j + 1], reg, count);
                    break;
                case ':':
                    if (str[i][j + 1] == '=') {
                        printf("\n\tMOV\t%c%d,%c;", reg, count, str[i][j - 1]);
                        count++;
                    } else {
                        printf("\n\tSyntax error...\n");
                    }
                    break;
                default:
                    break;
            }
        }
    }
}
