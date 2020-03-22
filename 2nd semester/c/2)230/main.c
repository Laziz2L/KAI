#include <stdio.h>
#include <stdlib.h>

FILE *input;
FILE *output;

void vvodrand()
{
    int n;
    printf("Input the number of sequence elements\n");
    scanf("%d", &n);
    int A[n];
    printf("The sequence:\n");
    for (int i=0; i<n; i++) {
        A[i] = rand();
        printf("%d ", A[i]);
    }

    int l, s;
    l = -60000;
    s = 60000;
    for (int i=0; i<n; i++) {
        if (A[i] < s) {
            s = A[i];
        }
        if (A[i] > l) {
            l = A[i];
        }
    }
    int k;
    k = l - s;
    printf("\n");
    printf("the lenght of the smallest segment of the number axis containing all elements - %d", k);
    printf("\n\n");
    printf("Input 1 to put this result into the file\n");
    int r = 0;
    scanf("%d", &r);
    if (r == 1) {
        output = fopen ("output.txt", "w");
        fprintf(output, "%d", k);
        fclose(output);
    }
}

void vvodcons()
{
    int n;
    printf("Input the number of sequence elements\n");
    scanf("%d", &n);
    int A[n];
    for (int i=0; i<n; i++) {
        printf("input element %d", i+1);
        printf("\n");
        scanf("%d", &A[i]);
    }

    int l, s;
    l = -60000;
    s = 60000;
    for (int i=0; i<n; i++) {
        if (A[i] < s) {
            s = A[i];
        }
        if (A[i] > l) {
            l = A[i];
        }
    }
    printf("\n");
    printf("%d, %d", l, s);
    int k;
    k = l - s;
    printf("\n");
    printf("the lenght of the smallest segment of the number axis containing all elements - %d", k);
    printf("\n\n");
    printf("Input 1 to put this result into the file\n");
    int r = 0;
    scanf("%d", &r);
    if (r == 1) {
        output = fopen ("output.txt", "w");
        fprintf(output, "%d", k);
        fclose(output);
    }
}

void vvodfile()
{
    input = fopen ("input.txt", "r");
    int n;
    printf("Input the number of sequence elements\n");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++ ) {
        fscanf(input, "%d", &A[i]);
        printf("%d ", A[i]);
    }
    fclose(input);
    int l, s;
    l = -60000;
    s = 60000;
    for (int i=0; i<n; i++) {
        if (A[i] < s) {
            s = A[i];
        }
        if (A[i] > l) {
            l = A[i];
        }
    }
    int k;
    k = l - s;
    printf("\n");
    printf("the lenght of the smallest segment of the number axis containing all elements - %d", k);
    printf("\n\n");
    printf("Input 1 to put this result into the file\n");
    int r = 0;
    scanf("%d", &r);
    if (r == 1) {
        output = fopen ("output.txt", "w");
        fprintf(output, "%d", k);
        fclose(output);
    }
}

int main()
{
    int restart = 1;
    while (restart == 1) {
        printf("How we will build the sequence?\nChoose and input the number\n1)randomly\n2)by console\n3)by file");
        int c;

        int m = 1;
        while (m!=0) {

            printf("\n");
            scanf("%d", &c);

            if (c==1) {
                vvodrand();
                m = 0;
            }
            else if (c==2) {
                vvodcons();
                m = 0;
            }
            else if (c==3) {
                vvodfile();
                m = 0;
            }
            else {
                printf("wrong number, try again");
            }
        }
        printf("\n\n");
        printf("Input 1 to restart or any other symbol to close program\n");
        scanf("%d", &restart);
    }
    return 0;
}
