#include <stdio.h>
#include <stdlib.h>

FILE *input;
FILE *output;

void vvodcons()
{
    int A[3];
    for (int i = 0; i<3; i++) {
        printf("Input a%d = ", i+1);
        scanf("%d", &A[i]);
        printf("\n");
    }
    int B[3][3];
    int k;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            k = A[j] * 3;
            B[i][j] = A[i] - k;
        }
    }
    printf ("Your matrix :\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
 printf("Input 1 to put the result into file\n");
    int r = 0;
    scanf("%d", &r);
    if (r==1) {
        output = fopen("output.txt", "w");
        for (int i=0; i<3; i++) {
            fprintf(output, "%d  %d  %d\n", B[i][1], B[i][2], B[i][3]);
        }
        fclose(output);
    }
}



void vvodfile()
{
    int A[3];
    input = fopen("input.txt", "r");
    for (int i=0; i<3; i++) {
        fscanf(input, "%d", &A[i]);
    }
    fclose(input);

    int B[3][3];
    int k;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            k = A[j] * 3;
            B[i][j] = A[i] - k;
        }
    }
    printf ("Your matrix :\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
 printf("Input 1 to put the result into file\n");
    int r = 0;
    scanf("%d", &r);
    if (r==1) {
        output = fopen("output.txt", "w");
        for (int i=0; i<3; i++) {
            fprintf(output, "%d  %d  %d\n", B[i][1], B[i][2], B[i][3]);
        }
        fclose(output);
    }
}


int main()
{
    int restart = 0;
    do {
        printf("How to input a1, a2, a3 ?\n1)by console\n2)by file\n");
        int c;
        scanf("%d", &c);

        int m = 1;
        while (m != 0)
        {
            if (c==1) {
                vvodcons();
                m = 0;
            }
            else if (c==2) {
                vvodfile();
                m = 0;
            }
            else {
                printf("Wrong number, try again\n");
            }
        }
        printf("\n\nInput 1 to restart\n");
        scanf("%d", &restart);
        printf("\n\n");
    } while (restart ==1);

    return 0;
}
