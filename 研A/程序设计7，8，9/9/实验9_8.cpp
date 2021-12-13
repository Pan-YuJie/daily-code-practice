#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
struct Pai
{
	char Mingcheng[20];
	char Huase[20];
	char Dianshu[20];
	int Shuzhi;
}; 
char Huaseb[5][20]={"方片","草花","红桃","黑桃","王"};
char Dianshub[15][20]={"2","3","4","5","6","7","8","9","10","J","Q","K","A","小","大"};
Pai wang[2]={"大王","王","大",500,"小王","王","小",300};
int main()
{
	
	Pai APuke[54],aPai;
	int i,j;
	for(i=0;i<4;i++){
	  	for(j=0;j<13;j++){
	  		strcpy(aPai.Huase,Huaseb[i]);
	  		strcpy(aPai.Dianshu,Dianshub[j]);
			strcpy(aPai.Mingcheng,Huaseb[i]);
			strcat(aPai.Mingcheng,Dianshub[j]);
			if(j==0)
			aPai.Shuzhi=50;
			else
			aPai.Shuzhi=j+2;
			APuke[j*4+i]=aPai; 
	  	} 
	}
	APuke[52]=wang[1];
	APuke[53]=wang[0];
	  
	for(i=0;i<54;i++){
		printf("%s ",APuke[i].Mingcheng);
	}
	  
	printf("\n");
	
	int luanpai[54]={0},k;
	srand(time(NULL));
	int m;
	for(m=1;m<=2;m++){
	  	for(i=0;i<54;i++){
			luanpai[i]=0;
		}
	  	for(i=1;i<=54;i++){
	  		k=rand()%54;
	  		while(luanpai[k]!=0)
	  		k=rand()%54;
	  		luanpai[k]=i;
	  	}
	}  
	Pai BPuke[54];
	for(i=0;i<54;i++){
		BPuke[i]=APuke[luanpai[i]-1];
	}
    Pai CPuke[3][18];
	for(i=0;i<18;i++){
		for(j=0;j<3;j++){
			CPuke[j][i]=BPuke[i*3+j];
		}
	}
	printf("\n排序前的牌\n");
	for(i=0;i<3;i++){
		for(j=0;j<18;j++){
			printf("%s ",CPuke[i][j].Mingcheng);
		}
		printf("\n");
	} 
    for(k=0;k<3;k++)
	{
		for(i=0;i<17;i++){
			for(j=i+1;j<18;j++){
				if(CPuke[k][i].Shuzhi<CPuke[k][j].Shuzhi){
					aPai=CPuke[k][i];
					CPuke[k][i]=CPuke[k][j];
					CPuke[k][j]=aPai;
				}
			}
		}
	} 
	printf("排序后的牌\n");
	for(i=0;i<3;i++){
		for(j=0;j<18;j++){
			printf("%s ",CPuke[i][j].Mingcheng);
		}
		printf("\n");
	}
	return 0;
}
