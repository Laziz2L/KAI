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
    } /* теперь j - индекс последнего элемента массива */
    b[0] = a[0];
    for (i = 1; i < j; i++ ){
        b[i] = (a[i+1]-a[i])/3;
    }
    b[j] = a[j];

    printf("\n уда поступ€т конечные данные: 1 - файл, 2 - консоль: ");
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
    else printf("¬вод некорректных данных!");
}

void vvodcons(){
int i, O;

printf("¬ведите n: ");
scanf("%d", &n);
for (i = 0; i < n; i ++ ){
printf("¬ведите a[%d] = ", i + 1 );
scanf("%f", &a[i]);
}
for (i = 0; i < n; i++ ){
b[i] = (a[i + 1]-a[i])/3;
}
b[0] = a[0];
b[n - 1] = a[n - 1];
printf("\n уда поступ€т конечные данные: 1 - файл, 2 - консоль: ");
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
else printf("¬вод некорректных данных!");
}

int main(){
    int I, t, R, r;
    char s[256];

    system("chcp 1251");
    system("cls");

    input = fopen ("input.txt", "r");
    while(1){
        printf("\nќткуда поступ€т исходные данные: 1 - файл, 2 - консоль: ");
        t = scanf("%d", &I);
        if (t == NULL) {
            gets(s);
            printf("¬вод некорректных данных!");
        }
        else if (I == 1){
            vvodfile();
            break;
        }
        else if (I == 2){
            vvodcons();
            printf("\n’отите повторить: 0 - нет, 1 - да: ");
            r = scanf("%d", &R);
            if (r == NULL){
                gets(s);
                printf("¬вод некорректных данных!");
            }
            else if (R == 0) break;
            else if (R == 1) continue;
            else printf("¬вод некорректных данных!");
        }
        else printf("¬вод некорректных данных!");
    }
    fclose(input);
}
