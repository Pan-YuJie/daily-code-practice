#include <stdio.h>

int main()
{
    int i,x=0,y,m,d;

    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    scanf("%d%d%d",&y,&m,&d);

    for(i=1980;i<y;i++)

        if((i%4==0&&i%100!=0)||i%400==0)

            x=x+2;

            else x++;

             if((y%4==0&&y%100!=0)||y%400==0)

                a[1]=29;

                for(i=1;i<m;i++)

                    x+=a[i];

                    x=(x+d)%7;

                    switch(x)

                    {

                        case 0:printf("����һ");break;

                        case 1:printf("���ڶ�");break;

                        case 2:printf("������");break;

                        case 3:printf("������");break;

                        case 4:printf("������");break;

                        case 5:printf("������");break;

                        case 6:printf("������");break;

                    }
                    return 0;
}
