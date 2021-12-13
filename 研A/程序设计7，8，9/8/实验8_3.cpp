#include<stdio.h>
int main()
{
	double a[40]={2},b[40]={1};
	double sum=a[0]/b[0];
	for(int i=1;i<40;i++){
		a[i]=a[i-1]+b[i-1];
		b[i]=a[i-1];
		sum+=a[i]/b[i];
	}
	printf("%f",sum);
	return 0;
}
