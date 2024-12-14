#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LEN 105
//定义结构体，存储数据
typedef struct _Person
{
	char name[25]; //姓名
	char phone[15];//电话号码
} Person, * PPerson;

//输入电话号码簿，返回读入的数量
int input(Person p[]);

//重命名姓名重复的人员
void reName(Person p[], int n);

//按照名字从小到大的比较函数
int cmp(const void* p1, const void* p2);

int main(){
	Person persons[LEN];
	int i, n;
	n = input(persons);
	reName(persons, n);
	qsort(persons, n, sizeof(persons[0]), cmp);
	for (i = 0; i < n; i++) {
	printf("%s %s\n", persons[i].name, persons[i].phone);
	}
	return 0;
}

int input(Person p[]){
	int n;
	char s[100][100];
	scanf("%d", &n);
	getchar();
	int i,j,m=0,k,l=0,flag=0;
	char *f;
	//边读入边比较 
	for(i=0;i<n;i++){
		gets(s[i]);
		for(k=0;k<i;k++){
			f=strstr(s[k],s[i]);
			if(f!=NULL){
				flag=1;	
			}
		}
		//printf("%d %d\n",i, flag);
		if(flag==0){
		//	puts(s[i]);
			for(j=0;isalpha(s[i][j])!=0;j++){
				p[m].name[j]=s[i][j];
				
			}
			p[m].name[j]='\0';
			//puts(p[m].name);
			j++; 
			for(j;isdigit(s[i][j])!=0;j++){
				p[m].phone[l]=s[i][j];
				l++;
			}
			m++;
		}
		flag=0;
		l=0;
	}
	
	return m;}
	
void reName(Person p[], int n){
	int i,k,j;
	char *f;
	int flag[200];

	//创造flag记录重复次数 
	for(i=0;i<200;i++){
		flag[i]=0;
	}
	for(i=0;i<n;i++){
		for(k=0;k<i;k++){
			f=strstr(p[k].name,p[i].name);
			if(f!=NULL){
				flag[i]++;
				
				}
		//	printf("i=%d k=%d flag=%d ",i,k,flag[i]);
		}
		//		puts(p[i].name);
	}
	for(i=0;i<n;i++){
		if(flag[i]!=0){
			for(j=0;p[i].name[j]!='\0';j++);
			p[i].name[j]='_';
			p[i].name[j+1]=(char)(48+flag[i]);
			p[i].name[j+2]='\0';
			//printf("%d %d\n",j,strlen(p[i].name));
		} 
	}
}
int cmp(const void* p1, const void* p2){
//	char *d1=(char *)p1;
//	char *d2=(char *)p2;
//	if(*d1 < *d2) return -1;
//	else if(*d1 > *d2) return 1;
//	else{
//		printf("=");
//	 return 0;}
	return strcmp((char *)p1,(char *)p2);
}


