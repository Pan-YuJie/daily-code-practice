#define _CRT_SECURE_NO_WARNINGS 1



#include <iostream>
using namespace std;
#include <string>
//n����ת��ʮ����
int nToten(int n, char nums[]);
//ʮ����ת����m����
void tenTom(int ten, int m, char nums[]);


int main()
{

    while (1)
    {
        int n = 0;
        int m = 0;
        char str[32] = { 0 };
        char ans[32] = { 0 };
        printf("�������������ݵĽ�����:>\n");
        cin >> n;
        printf("��������:>\n");
        cin >> str;
        printf("��������ת���Ľ�����:>\n");
        cin >> m;

        int ten = nToten(n, str);
        tenTom(ten, m, ans);

        printf("������:\n");
        cout << ans << endl << endl;
        
    }
    return 0;
}

int nToten(int n, char nums[])
{
    int len = strlen(nums);
    int ten = 0;
    int power = 1;//�η�
    for (int i = len - 1; i >= 0; i--)//��Ȩ
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


    for (int i = 0; i < len; i++)
    {
        nums[i] = tmp[len - 1 - i];
    }

}