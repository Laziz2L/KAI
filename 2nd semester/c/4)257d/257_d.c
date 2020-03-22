#include <stdio.h>
#include <malloc.h>
#include <string.h>
void getFileName(char row[]);
int check(char row[]);
int main(int argc, char * argv[]){
    int restart = 1;
    while(restart){
        int in_f, out_f;
        char row[100];
        printf("Enter the 0 to read from console or 1 to read from file: ");
        scanf("%d", &in_f);
        printf("Enter the 0 to print in console or 1 to print in file: ");
        scanf("%d", &out_f);
        if(in_f){
            FILE * f;
            char * input_file_name = "input.txt";
            char temp[256] = {'\0'};
            printf("Enter the name of file to input data: ");
            getFileName(temp);
            if (temp[0] !='\n')
            {
                f = fopen(temp,"r");
            }
            else
            {
                f = fopen(input_file_name,"r");
            }
            fscanf(f,"%s",row);
            fclose(f); 
        }
        else{
            printf("Enter your row: ");
            scanf("%s",&row);
        }
        int flag = check(row);
        if(out_f){
            char * output_file_name = "output.txt";
            char temp[256] = {'\0'};
            printf("Enter the name of file to output: ");
            getFileName(temp);
            FILE * f;
            if (temp[0] != '\n')
            {
                f = fopen(temp, "w");
            }
            else
            {
                f = fopen(output_file_name, "w");
            }
            if(flag)
            {
                fprintf(f,"YES\n");
            }
            else
            {
                fprintf(f,"NO\n");
            } 
            fclose(f);
        }
        else{
            if(flag)
            {
               printf("YES\n");
            }
            else
            {
               printf("NO\n");
            } 
        }
        if (in_f){
            restart = 0;
        }
        else
        {
            printf("Enter the 1 to restart or enter the 0 to exit: ");
            scanf("%d",&restart);
        }
        
    }
    return 0;
}
void getFileName(char row[])
{
    fflush(stdin);
    row[0] = getchar();
    int i = 0;
    while(row[i] != '\n'){
        i += 1;
        row[i] = getchar();
    }
    if(i>0)
    {
        row[i] = '\0';
    }
}

int check(char row[])
{

    int ind = 1;
    int flag = 0;
    while (row[ind] != '!')
    {
        if (row[ind] == row[ind-1])
        {
            flag = 1;
        }
        ind += 1;
    }
    return flag;
}