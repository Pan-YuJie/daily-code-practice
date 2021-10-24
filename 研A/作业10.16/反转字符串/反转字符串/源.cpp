#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


int strlen(char str1[]);
char* Str(char str[], int);
int main()
{
    char str1[40];

    gets_s(str1);
    
    int len =0; 
    len = strlen(str1);
    
    Str(str1, len);

    printf("%s", str1);

    return 0;
}


int strlen(char str1[])
{
    int len = 0;
    for (int i = 0; str1[i] != '\0'; i++)
    {
        len++;
    }

    return len;
}

char* Str(char str[], int len)
{

  /*  int i = 0;
    int j = len - 1;
    for (; i <= j; i++, j--)
    {
        int temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }*/

    int i = 0;
    int j = len - 1;
    while (i<=j)
    {
        int temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }


    return 0;
}
