#include<iostream>

using namespace std;

const int N=1000010;

int n,k;  //k:窗口大小
int a[N],q[N]; // q[]:记录数的下标 
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    int hh=0,tt=-1; // hh:队头  tt:队尾 
    for(int i=0;i<n;i++) // 寻找最小值。 
    {
        if(hh<=tt&&q[hh]<i-k+1) hh++;   // 队列是否在当前窗口内 
        while(hh<=tt&&a[q[tt]]>=a[i]) tt--;  // 因为a[q[tt]]>a[i],所以a[q[tt]] 永远都无法作为最小值，所以弹出
        q[++tt] = i;  // 新元素入队。

        if(i>=k-1) printf("%d ",a[q[hh]]); // 因为是单调的 所以队头就是最小值。 
    } 
    puts(""); //换行；

    hh=0,tt=-1;
    for(int i=0;i<n;i++) // 寻找最大值。 
    {
        if(hh<=tt&&q[hh]<i-k+1) hh++;
        while(hh<=tt&&a[q[tt]]<=a[i]) tt--;   
        q[++tt] = i;  

        if(i>=k-1) printf("%d ",a[q[hh]]); 
    } 
    return 0;
}

