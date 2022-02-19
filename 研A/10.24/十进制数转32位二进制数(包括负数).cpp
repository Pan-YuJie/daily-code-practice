#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long DataType;  

void tenTobin(char* buff,int ten)
{
	int size=(sizeof(DataType)*8)+(sizeof(DataType)-1);
	char tmp[size];
	int count = 0;
    int index = 1;
    
    while(count<size)
    {
    	tmp[count++] = ((ten&1)+'0');
        ten = ten >> 1;
        
        if(index%8==0 && count!=size)
        {
        	tmp[count++]=' ';
		}
		
        index++; 
	}
    
    
    for (int i = 0; i < count; i++)
    {
        buff[i] = tmp[count -i-1];
    }
    
    buff[count]='\0';
    
}

int main()
{
    int ten;
    char *buff = (char*)malloc(sizeof(DataType)*8)+(sizeof(DataType)-1);
    
    while(1)
    {
    	
    printf("输入十进制数：");
    scanf("%d",&ten);
    
    tenTobin(buff,ten);
    
    printf("输出二进制数：");
    printf("%s\n\n",buff);
   	
   	
	}
    
    free(buff);
    
    return 0;
}





































