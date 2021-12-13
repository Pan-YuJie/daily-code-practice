#include<stdio.h>
int main()
{
	int a[100]={1,5,6,7};
	int x,n=4,i,j;
	printf("输入一个数\n");
	scanf("%d",&x);
	for(i=0;i<n;i++){
		if(a[i]>=x)
		break;
	}
	j=i;
	for(i=n;i>j;i--){
		a[i]=a[i-1];
	}
	
	a[j]=x;
	n++;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
