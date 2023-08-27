#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main() {
    char a[25][25], u, op1 = '*', op2 = '+', op3 = '/', op4 = '-'; // Fix: op1, op2, op3, op4 should be single characters
    int p, q, r, l, o, ch, i = 1, c, k, j, count = 0;
    FILE *fi, *fo;

    printf("Enter three address code\n");
    printf("Enter the ctrl-z to complete:\n");
    fi = fopen("infile.txt", "w");
    while ((c = getchar()) != EOF)
        fputc(c, fi);
    fclose(fi);

    printf("\nUnoptimized input block\n");
    fi = fopen("infile.txt", "r");
    while ((c = fgetc(fi)) != EOF) {
        k = 1;
        while (c != ';' && c != EOF) {
            a[i][k] = c;
            printf("%c", a[i][k]);
            k++;
            c = fgetc(fi);
        }
    }
    count = i;
    fclose(fi);
    i = 1;
    printf("\n");
    i++;
    printf("\nOptimized three address code\n");
    while (i < count) {
        if (strcmp(a[i], op1) == 0 && strcmp(a[i], op1) == 0) {
            printf("\nType 1 reduction in strength\n");
            if (strcmp(a[i], "2") == 0) {
                for (j = 1; j <= 4; j++)
                    printf("%c", a[i][j]);
                printf("%c", a[i][3]);
            }
        } else if (isdigit(a[i][3]) && isdigit(a[i][5])) {
            printf("\nType 2 constant folding\n");
            p = a[i][3] - '0'; // Convert char digit to int
            q = a[i][5] - '0'; // Convert char digit to int
            if (strcmp(a[i], op1) == 0)
                r = p * q;
            if (strcmp(a[i], op2) == 0)
                r = p + q;
            if (strcmp(a[i], op3) == 0)
                r = p / q;
            if (strcmp(a[i], op4) == 0)
                r = p - q;
            for (j = 1; j <= 2; j++)
                printf("%c", a[i][j]);
            printf("%d", r);
            printf("\n");
        } else if (strcmp(a[i][5], '0') == 0 || strcmp(a[i][5], '1') == 0) {
            printf("\nType 3 algebraic expression elimination\n");
            if ((strcmp(a[i], op1) == 0 && strcmp(a[i][5], '1') == 0) || (strcmp(a[i], op3) == 0 && strcmp(a[i][5], '1') == 0)) {
                for (j = 1; j <= 3; j++)
                    printf("%c", a[i][j]);
                printf("\n");
            } else {
                printf("\nSorry, cannot optimize\n");
            }
        } else {
            printf("\nError input\n");
        }
        i++;
    }
    getch();
    return 0;
}
