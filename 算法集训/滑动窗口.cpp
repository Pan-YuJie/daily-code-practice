#include<iostream>

using namespace std;

const int N=1000010;

int n,k;  //k:���ڴ�С
int a[N],q[N]; // q[]:��¼�����±� 
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    int hh=0,tt=-1; // hh:��ͷ  tt:��β 
    for(int i=0;i<n;i++) // Ѱ����Сֵ�� 
    {
        if(hh<=tt&&q[hh]<i-k+1) hh++;   // �����Ƿ��ڵ�ǰ������ 
        while(hh<=tt&&a[q[tt]]>=a[i]) tt--;  // ��Ϊa[q[tt]]>a[i],����a[q[tt]] ��Զ���޷���Ϊ��Сֵ�����Ե���
        q[++tt] = i;  // ��Ԫ����ӡ�

        if(i>=k-1) printf("%d ",a[q[hh]]); // ��Ϊ�ǵ����� ���Զ�ͷ������Сֵ�� 
    } 
    puts(""); //���У�

    hh=0,tt=-1;
    for(int i=0;i<n;i++) // Ѱ�����ֵ�� 
    {
        if(hh<=tt&&q[hh]<i-k+1) hh++;
        while(hh<=tt&&a[q[tt]]<=a[i]) tt--;   
        q[++tt] = i;  

        if(i>=k-1) printf("%d ",a[q[hh]]); 
    } 
    return 0;
}

