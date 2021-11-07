#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define k  NULL
typedef struct student{
	int num;
	char name[20];
	int english,math,computer;
	double average;
	struct student *last;
	struct student *next;
}str;

str *input(str *first);
void update(str *first);
//str *order(str *first);
str *delet(str *first);
void menu(); 
str *check(str *first,int m);
str *clear(str *first); 
void print(str *first);
void write_to_file(str *head);
str *read_from_file(str *first);

/*str *order(str *first){
	if(first==k){
		printf("��������ѧ����Ϣ,������ϵͳ\n");
	 
	}
	str *p,*p1,*head=k,*tail=k,*pmin,*pb;
	while(first!=k)
	{
		for(p1=first,pmin=first;p1->next!=k;p1=p1->next)
		{	 
			if(pmin->average>p1->next->average)
			{
				pb=p1;
				pmin=p1->next;
			}
		}
		if(pmin==first){
			first=(first)->next;
		}
		else{
			pb->next=pmin->next;
		}
		if(head==k)
		{
			head=pmin;
			tail=pmin;
		}
		else{
		tail->next=pmin;
		pmin->next=k;
		tail=pmin;
		}
  }
  		first =head;
  		for(p=first;p!=k;p=p->next)
		  {
		printf("%d \n",p->num);
	}
	return first;
}*/
int main()
{
	int n;
	int _scanf; 
	str *head=k;	
	for(;;)
	{	menu();
	fflush(stdin);
	_scanf=scanf("%d",&n);
	if(_scanf!=1){
		printf("�����������������!\n");
		continue;
	}
	switch(n)
		{
		case 1:head =input(head);
			break;
		case 2:update(head);
			break;
		case 3:head=delet(head);	
		break;
		case 4:head=clear(head);
		break;
		case 5:print(head);
		break;
		case 6:write_to_file(head);
			break;
		case 7:head=read_from_file(head);
			break;
		case 0:clear(head);return 0;
		}
	} 
	clear(head);
}	


void menu(void){
	printf("*********��ӭ����ѧ������ϵͳ*********\n");
	printf("****      1--����ѧ����Ϣ         ****\n");
		printf("****      2--�޸�ѧ����Ϣ         ****\n");
					printf("****      3--ɾ��ѧ����Ϣ         ****\n");
					printf("****      4--���ѧ����Ϣ         ****\n");
					printf("****      5--��ӡѧ����Ϣ         ****\n");
					printf("****      6--д��ѧ����Ϣ         ****\n");
					printf("****      7--����ѧ����Ϣ         ****\n");
					printf("****      0--�˳�ϵͳ             ****\n");
	printf("**************************************\n");
}

void write_to_file(str *head){
	FILE *fp;
	str *p;
	char filename[101];
	printf("Please input filename:\n");
	scanf("%s",filename);
	fp=fopen(filename,"w");
	if(fp==k)
	{
	printf("Open fail\n");
	exit(1);
	}
	for(p=head;p!=k;p=p->next){
	fprintf(fp,"%d %s %d %d %d %lf\n",p->num,p->name,p->english,p->math,p->computer,p->average);	
	}
	fclose(fp);
}

str *read_from_file(str *head)
{
	str *p;
	str *cur;
	FILE *fp;
	int _scanf;
	char filename[101];
	printf("Please input filename\n");
	scanf("%s",filename);
	if((fp=fopen(filename,"r"))==k){
	printf("Open fair!\n");
	exit(1);
	}
	while(!feof(fp)&&!ferror(fp)){
	p=(str *)malloc(sizeof(str));
	_scanf=fscanf(fp,"%d %s %d %d %d %lf\n",&p->num,p->name,&p->english,&p->math,&p->computer,&p->average);
	if(_scanf!=6){
	printf("д��ʧ��!\n");
	break;
	}
	if(check(head,p->num)!=k){
		printf("Already exist!\n");
		continue;
	}
	if (head == k) {
				head = p;
				p->last = k;
				p->next = k;
				continue;
			}
		for (cur = head; cur->next != k && p->num > cur->num; cur = cur->next);
			if (cur->next== k) 
			{
				p->last = cur;
				cur->next = p;
				p->next = k;
				continue;
			}
			if(cur==head){
				head = p;
				cur->last = p;
				p ->next= cur;
				p->last = k;
				continue;
			}
			cur->last->next = p;
			p->last = cur->last;
			p->next = cur;
			cur->last = p;}

	fclose(fp);
	return head;
}

str *input(str *head){
	str *p=k,*cur=k;
	int i,n;
	int _scanf;
	printf("���������ѧ��������:");
	for(;;){
	fflush(stdin); 
	_scanf=scanf("%d",&n);
	if(_scanf==0){
		printf("�����������������!\n");
		continue;
	}
	break;
	}
	_scanf=0;
	for(i=0;i<n;i++)
	{
		p=(str *)malloc(sizeof (str)); 
		if(p==k)
		{
			printf("Malloc fair!");
			break;
		}
		for(;;){	
		printf("�������%d��ѧ����ѧ��:",i+1);
		_scanf=scanf("%d",&p->num);
		fflush(stdin);
		if(check(head,p->num)==k&&_scanf==1)
		{
		break;
		}
		printf("���������ѧ���Ѿ����ڵ���Ϣ�����������룡\n");
		}
		for(;;){
		fflush(stdin);
		printf("�������%d��ѧ��������,Ӣ��ɼ�,��ѧ�ɼ�,������ɼ�:",i+1);
		_scanf=scanf("%s%d%d%d",p->name,&p->english,&p->math,&p->computer);
		if(_scanf!=4){
			printf("����������������룡\n");
			continue;
		}
		break;
		}
		p->average=(p->english+p->math+p->computer)/3.0;
		if (head == k) {
				head = p;
				p->last = k;
				p->next = k;
				continue;
			}
		for (cur = head; cur->next != k && p->num > cur->num; cur = cur->next);
			if (cur->next== k) 
			{
				p->last = cur;
				cur->next = p;
				p->next = k;
				continue;
			}
			if(cur==head){
				head = p;
				cur->last = p;
				p ->next= cur;
				p->last = k;
				continue;
			}
			cur->last->next = p;
			p->last = cur->last;
			p->next = cur;
			cur->last = p;			
	}
	//first=order(first);
	return head;
}
void update(str *first){
	if(first==k){
		printf("ѧ����ϢΪ�գ���������ѧ����Ϣ!\n");
		return;		
	}
	str *p=first;
		int n,_scanf;
	printf("�������ѧ����ѧ��:");
	for(;;){
	fflush(stdin); 
	_scanf=scanf("%d",&n);
	if(_scanf==0){
		printf("�����������������!\n");
		continue;
	}
	break;
	}
	if(check(first,n)==k)
	{
	printf("û�и�ѧ��!\n");
	return;
	}
	do{
		if(p->num==n){
			break;
		}
	p=p->next;		
	}while(p!=k);
	if(p!=k){			
	printf("����������Ҫ���µĿγ̣�1-Ӣ��  2-��ѧ  3-����� 0-ȡ����:");
	scanf("%d",&n);		
	switch(n)
		{
		case 1:
			printf("���¸�ѧ����Ӣ��ɼ�Ϊ:");
			scanf("%d",&p->english);
			break;
		case 2:
		printf("���¸�ѧ������ѧ�ɼ�Ϊ:");
			scanf("%d",&p->math);
			break;
		case 3:
			printf("���¸�ѧ���ļ�����ɼ�Ϊ:");
			scanf("%d",&p->computer);
			break;
		default:
		printf("�����������������!!\n");
		break;				
		}	
}
	p->average=(p->english+p->math+p->computer)/3.0;
	printf("\n");
}

str *delet(str *first){
	if(first==k){
		printf("Error!\n");
		printf("��������ѧ����Ϣ��ѧ����Ϣ�Ѿ���ɾ��\n");
		return k;		
	}
	str *cur;
	int num;
	int _scanf;
	printf("����������Ҫɾ����ѧ����ѧ��:\n");
	for(;;){
	fflush(stdin); 
	_scanf=scanf("%d",&num);
	if(_scanf==0){
		printf("�����������������!\n");
		continue;
	}
	break;
	}
	if(check(first,num)==k){
	printf("û�д�ѧ������Ϣ��\n");
		return first;
		}		
	for(cur=first;cur->num!=num;cur=cur->next);
	if(first->next==k){
	free(cur);
	return k;
	}
	if(cur==first){	
	first=first->next;
	first->last=k;
	free(cur);
	return first;
	}
	cur->last->next=cur->next;
	if(cur->next!=k){
		cur->next->last=cur->last;
	}
	
	free(cur);
	return first;
}

str *check(str *first,int m){
	str *p;
	for(p=first;p!=k;p=p->next)
	{
	if(p->num==m)
		return p;
	}
	return k;
}

str *clear(str *first)	{
	str *p=k,*p1=k;		
	for(p=first;p!=k;)
	{	p1=p->next;
		free(p);
		p=p1;
	}
	first =k;
	printf("��Ϣ����ɹ�\n");
	return first;
}
void print(str *first)
{
	str *p;
	printf("***ѧ��   ����   Ӣ��ɼ�   ��ѧ�ɼ�   ������ɼ�   ƽ���ɼ�***\n");
	for(p=first;p!=k;p=p->next)
	{
		
		printf("***%2d       %s       %d           %d           %d       %.21f***\n",p->num,p->name,p->english,p->math,p->computer,p->average);
	}
}
