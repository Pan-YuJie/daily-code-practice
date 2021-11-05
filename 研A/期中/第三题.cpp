#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//n进制转成十进制
int nToten(int, char*);
//十进制转化成m进制
void tenTom(int, int , char*);

int main()
{

    while (1)
    {
        int n = 0;
        int m = 0;
        int len=0;
        
		char*str=(char*)malloc(sizeof(char)*32);
        char*ans=(char*)malloc(sizeof(char)*32);
        
        printf("输入你输入数据的进制数:>\n");
        scanf("%d",&n);
        getchar();
        
        printf("输入数据:>\n");
        gets(str);
        
        printf("输入你想转化的进制数:>\n");
        scanf("%d",&m);

        int ten = nToten(n, str);
        tenTom(ten, m, ans);

        printf("输出结果:\n");
        printf("%s\n\n",ans);
        
        free(str);
        str=NULL;
        free(ans);
        ans=NULL;
        
        
    }
    return 0;
}

int nToten(int n, char* nums)
{
	
    int len = strlen(nums);
    
    int ten = 0;
    int power = 1;//次方
    for (int i = len - 1; i >= 0; i--)//加权
    {
        //nums[i]*pow(n,k)
        if (nums[i] >= '0' && nums[i] <= '9')
        {

            ten += (nums[i] - '0') * power;

        }

        else//'A'--'F'--10-15
        {
            ten += (nums[i] - 'A' + 10) * power;

        }

        power = power * n;
    }

    return ten;
}


void tenTom(int ten,int m, char nums[])
{
    char tmp[32] = { 0 };
    int len = 0;
    while (ten != 0)
    {

        int n = ten % m;
        ten = ten / m;


        if (n >= 0 && n <= 9)
        {
            tmp[len] = n + '0';

        }
        else//A-F
        {
            tmp[len] = n + 'A' - 10;
        }

        len++;

    }

	int i = 0;
    for (i = 0; i < len; i++)
    {
        nums[i] = tmp[len - 1 - i];
    }
    
    nums[i]='\0'; 

}

