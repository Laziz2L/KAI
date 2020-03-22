#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>



typedef struct Staff {
    char name[30];
    char surname[30];
    char patr[30];
    char post[30];
    char home[30];
    struct Staff *next;
}Staff;

typedef Staff* pStaff;
pStaff pHead;                  //элемент до первого
pStaff pTemp;                  //промежуточный элемент
pStaff pCurrent;               //последний введеный элемент

char NewlastName[100];         //для ввода с файла фамилия
char NewmiddleName[100];       //                   отчество
char NewfirstName[100];        //                   имя
char Newpost[100];             //                   должность
char Newadress[10];            //                   место проживания

void push(char name[],char surname[], char patr[], char post[], char home[]);       //ввод с консоли
int AddFILE();                                                                      //ввод с файла
int elements_counter();                                                             //функция, считающая количество элементов
int sorter();                                                                       //функция сортировки
void FindSname(Staff *pL, char *SurnameIn);                                  //функции поиска по фамилии
void FindPost(Staff *pL, char *PostIn);                                      //               по должности
void FindHome(Staff *pL, char *HomeIn);                                      //               по месту проживания
int print();                                                                       //вывод в консоль
int printfile();                                                                    //вывод в файл
int DeleteAll();                                                                    //удаление - обнуление
void getFileName(char row[]);                                                //функция для ввода имени файла
void to_reset(); //обнуление списка.

void menu()
{
    printf("---------menu----------\n");
    printf("1)Insert data by file\n");
    printf("2)Add data by console\n");
    printf("3)Search across surname\n");
    printf("4)Search across post\n");
    printf("5)Search across residence\n");
    printf("6)Print list in console\n");
    printf("7)Print list in file\n");
    printf("8)Reset list\n");
    printf("9)Exit\n");
    printf(":");
}

int main()
{
 pHead = (Staff *) malloc(sizeof(Staff));
 pHead->next = pHead;

 char surname[30];
 char name[30];
 char patr[30];
 char post[30];
 char home[30];
   int flag = 1;
   while (flag)
   {
       menu();
       int ans;
       scanf("%d", &ans);
       printf("\n");
       switch (ans)
       {
       case 1 : AddFILE();
                break;
       case 2 :
            puts("Input data:");
            scanf("%s", surname);
            scanf("%s", name);
            scanf("%s", patr);
            scanf("%s", post);
            scanf("%s", home);
            push(name, surname, patr, post, home);
            break;
       case 3 :
            printf("\nEnter surname to find\n");
            char SurnameIn[30];
            scanf("%s", SurnameIn);
            //int j = elements_counter();
            FindSname(pHead->next, SurnameIn);
            break;
       case 4 :
            printf("\nEnter post to find\n");
            char PostIn[30];
            scanf("%s", PostIn);
            //j = elements_counter();
            FindPost(pHead->next, PostIn);
            break;
       case 5 :
            printf("\nEnter residence to find\n");
            char HomeIn[30];
            scanf("%s", HomeIn);
            //j = elements_counter();
            FindHome(pHead->next, HomeIn);
            break;
       case 6:
            sorter();
            print();
            break;
       case 7:
            sorter();
            printfile();
            break;
       case 8:
            to_reset();
            break;
       case 9:
            DeleteAll();
            exit(1);
       default :
            break;
       }
   }
}

void push(char name[],char surname[], char patr[], char post[], char home[])
{
    pCurrent = pHead->next;

    if (pCurrent == pHead)
    {
        pTemp = (pStaff)(malloc(sizeof(Staff)));
        strcpy(pTemp->name,name);
        strcpy(pTemp->surname, surname);
        strcpy(pTemp->patr, patr);
        strcpy(pTemp->post, post);
        strcpy(pTemp->home, home);

        pHead->next = pTemp;
        pTemp->next = pHead;

    }
    else
    {
        while(pCurrent!= pHead && pCurrent->next != pHead)
        {
            pCurrent = pCurrent->next;
        }

        pTemp = (pStaff)(malloc(sizeof(Staff)));
        strcpy(pTemp->name,name);
        strcpy(pTemp->surname, surname);
        strcpy(pTemp->patr, patr);
        strcpy(pTemp->post, post);
        strcpy(pTemp->home, home);;

        pCurrent->next = pTemp;
        pTemp->next = pHead;

    }
}

void FindSname(Staff *pL, char *SurnameIn)
{
    while (pL != pHead)
    {
        if (strcmp(pL->surname, SurnameIn) == 0)
        {
            printf("%s %s %s %s %s \n", pL->name, pL->surname, pL->patr, pL->post, pL->home);
            break;
        }
        pL = pL->next;
    }
    if(pL == pHead)
        puts("Element not found!");
}

void FindPost(Staff *pL, char *PostIn)
{
    while (pL != pHead)
    {
        if (strcmp(pL->post, PostIn) == 0)
        {
            printf("%s %s %s %s %s \n", pL->name, pL->surname, pL->patr, pL->post, pL->home);
            break;
        }
        pL = pL->next;
    }
     if(pL == pHead)
        puts("Element not found!");
}

void FindHome(Staff *pL, char *HomeIn)
{
    while (pL != pHead)
    {
        if (strcmp(pL->home, HomeIn) == 0)
        {
            printf("%s %s %s %s %s \n", pL->name, pL->surname, pL->patr, pL->post, pL->home);
            break;
        }
        pL = pL->next;
    }
     if(pL == pHead)
        puts("Element not found!");
}

int sorter()
{
    int i,j;
    pStaff p = pHead->next;

    char tmpName[40];
    char tmpSurname[40];
    char tmpPatr[40];
    char tmpPost[40];
    char tmpHouse[40];

    if(p == pHead)
    {
        return 0;
    }
    else
    {
        for(i=elements_counter() - 1; i>=0; i--)//Метод пузырька
        {
            p = pHead->next;
            for(j=0; j < i; j++)
            {
				if(strcmp(p->surname, p->next->surname)>0)
			   {
				   strcpy(tmpName, p->name);
				   strcpy(tmpSurname, p->surname);
				   strcpy(tmpPatr, p->patr);
				   strcpy(tmpPost, p->post);
				   strcpy(tmpHouse, p->home);

				   strcpy(p->name, p->next->name);
				   strcpy(p->surname, p->next->surname);
				   strcpy(p->patr, p->next->patr);
				   strcpy(p->post, p->next->post);
				   strcpy(p->home, p->next->home);

				   strcpy(p->next->name, tmpName);
				   strcpy(p->next->surname, tmpSurname);
				   strcpy(p->next->patr, tmpPatr);
				   strcpy(p->next->post, tmpPost);
				   strcpy(p->next->home, tmpHouse);

			   }
                    p = p->next;
            }


        }
    }
}

int elements_counter()
{
    int count=0;
    pStaff p = pHead->next;
    while(p != pHead)
    {
        count++;
        p=p->next;
    }
    return count;
}

int AddFILE()
{
    int n;
    pStaff NewStaff;
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
    while(1)
    {
        n = fscanf(f, "%s %s %s %s %s\n", NewlastName, NewfirstName, NewmiddleName, Newpost, Newadress);
        if (n <= 0)
            return 0;

         pCurrent = pHead->next;
		 while(pCurrent!= pHead && pCurrent->next != pHead)
         {
            pCurrent = pCurrent->next;
         }

        NewStaff = (pStaff)malloc(sizeof(struct Staff));

        strcpy(NewStaff->surname, NewlastName);
	    strcpy(NewStaff->patr, NewmiddleName);
	    strcpy(NewStaff->name, NewfirstName);
	    strcpy(NewStaff->post, Newpost);
	    strcpy(NewStaff->home, Newadress);

        NewStaff->next = NULL;

        if(pCurrent == pHead){
            pHead->next = NewStaff;
            NewStaff->next = pHead;
        }
        else{
            NewStaff->next = pCurrent->next;
            pCurrent->next = NewStaff;
        }
    }
    fclose(f);
}

int print()
{
    int i=1;
    pStaff p = pHead->next;

    if(p == pHead)
    {
        puts("List is empty!");
        return 0;
    }
    else
    {
        do
        {
            printf("\n[%d] %s %s %s %s %s\n", i++, p->surname, p->name, p->patr, p->post, p->home);
            p = p->next;
        }while ( p != pHead);
    }
}

int printfile()
{
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
    int i=1;
    pStaff p = pHead->next;

    if(p == pHead)
    {
        puts("List is empty!");
        return 0;
    }
    else
    {
        do
        {
            fprintf(f, "[%d] %s %s %s %s %s\n", i++, p->surname, p->name, p->patr, p->post, p->home);
            p = p->next;
        }while (p != pHead);
    }
    fclose(f);
    return 0;
}


void to_reset() //Элементы списка остаются, но обнуляется их содержимое
{
    pCurrent = pHead->next;
    while ( pCurrent != pHead)
        {
            memset(pCurrent->name, 0, sizeof(pCurrent->name));
            memset(pCurrent->surname, 0, sizeof(pCurrent->surname));
            memset(pCurrent->patr, 0, sizeof(pCurrent->patr));
            memset(pCurrent->post, 0, sizeof(pCurrent->post));
            memset(pCurrent->home, 0, sizeof(pCurrent->home));

            pCurrent = pCurrent->next;
        }
}

int DeleteAll()
{
    if (pHead->next == pHead)
            return 0;

    //pStaff p;
    pStaff pCur = pHead->next;
    while(pCur != pHead)
    {
        pCur = pHead->next->next;
        free(pHead->next);
        pHead->next = pCur;
    }
    pHead->next = pHead;
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
