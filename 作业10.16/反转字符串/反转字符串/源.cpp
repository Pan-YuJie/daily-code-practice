#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
    int i, n;
    char st1[40];
    char st2[40];

    gets_s(st1);

    for (n = 0, i = strlen(st1) - 1; i >= 0; n++,i--)
    {
        st2[n] = st1[i];
        
    }
    
    st2[strlen(st1)] = 0;

    printf("%s", st2);

    return 0;
}
