#include <stdio.h>
#include <stdlib.h>

FILE *input;
FILE *output;

int n, j;
float a[100];
float b[100];

void vvodfile(){
    int i, O;

    j = 100;
    for (i = 0; i < j; i++ ){
        fscanf(input, "%f", &a[i]);
    }
    j--;
    while (a[j] == 0) {
        j--;
    } /* ������ j - ������ ���������� �������� ������� */
    b[0] = a[0];
    for (i = 1; i < j; i++ ){
        b[i] = (a[i+1]-a[i])/3;
    }
    b[j] = a[j];

    printf("\n���� �������� �������� ������: 1 - ����, 2 - �������: ");
    scanf("%d", &O);
    if (O == 1){
        output = fopen ("output.txt", "w");
        for (i = 0; i < j+1; i ++ ){
            fprintf(output, "b[%d]=%f\n", i + 1, b[i]);
        }
        fclose(output);
    }
    else if (O == 2){
        for (i = 0; i < j+1; i ++ ){
            printf("b[%d]=%f\n", i + 1, b[i]);
        }
    }
    else printf("���� ������������ ������!");
}

void vvodcons(){
int i, O;

printf("������� n: ");
scanf("%d", &n);
for (i = 0; i < n; i ++ ){
printf("������� a[%d] = ", i + 1 );
scanf("%f", &a[i]);
}
for (i = 0; i < n; i++ ){
b[i] = (a[i + 1]-a[i])/3;
}
b[0] = a[0];
b[n - 1] = a[n - 1];
printf("\n���� �������� �������� ������: 1 - ����, 2 - �������: ");
scanf("%d", &O);
if (O == 1){
output = fopen ("output.txt", "w");
for (i = 0; i < n; i ++ ){
fprintf(output, "b[%d]=%f\n", i + 1, b[i]);
}
fclose(output);
}
else if (O == 2){
for (i = 0; i < n; i ++ ){
printf("b[%d]=%f\n", i + 1, b[i]);
}
}
else printf("���� ������������ ������!");
}

int main(){
    int I, t, R, r;
    char s[256];

    system("chcp 1251");
    system("cls");

    input = fopen ("input.txt", "r");
    while(1){
        printf("\n������ �������� �������� ������: 1 - ����, 2 - �������: ");
        t = scanf("%d", &I);
        if (t == NULL) {
            gets(s);
            printf("���� ������������ ������!");
        }
        else if (I == 1){
            vvodfile();
            break;
        }
        else if (I == 2){
            vvodcons();
            printf("\n������ ���������: 0 - ���, 1 - ��: ");
            r = scanf("%d", &R);
            if (r == NULL){
                gets(s);
                printf("���� ������������ ������!");
            }
            else if (R == 0) break;
            else if (R == 1) continue;
            else printf("���� ������������ ������!");
        }
        else printf("���� ������������ ������!");
    }
    fclose(input);
}
