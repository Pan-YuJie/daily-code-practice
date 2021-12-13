#include<stdio.h>
int main()
{
	double max,min,ave,sum,a[100];
	int n;
	printf(" ‰»În\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf",&a[i]);
	}
	max=min=a[0];
	for(int i=0;i<n;i++){
		if(a[i]>max){
			max=a[i];
		}
		if(a[i]<min){
			min=a[i];
		}		
		sum+=a[i];
	}
	ave=sum/n;
	printf("max=%f min=%f ave=%f sum=%f",max,min,ave,sum);
	return 0;
}
