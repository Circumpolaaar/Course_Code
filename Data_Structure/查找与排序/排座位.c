#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct _Node{
	int id;
	char name[30];
	int seat;
}Node, *PNode; 

void input(FILE *fp,int n,PNode menu[]);
void bubbleSort(PNode menu[], int n);
int insert(PNode menu[],PNode done[],int q);
int pickout(PNode menu[],PNode done[],int q,int n);
void Sort(PNode menu[], int n);
void deletenull(PNode menu[], int n);

int main(){
	FILE *in=NULL,*out=NULL;
	int n,m;
	int i;
	int k=0;
	int q;
	int b=0;
	PNode menu[100]={0};
	PNode done[100]={0};
	in=fopen("in.txt","r");
	out=fopen("out.txt","w");
	scanf("%d",&n);
	input(in,n,menu);
	bubbleSort(menu,n);
	int que;
	m=menu[n-1]->seat;
	//if(m<=n) q=m;
	//else
	 q=n;
	que=insert(menu,done,q);
	b=pickout(menu,done,que,n);
	deletenull(done,b);
	Sort(done,n);
	printf("%d\n",b);
	
	
	for(i=0;i<n;i++){
		//printf("%d:%d %s %d\n",i,menu[i]->id,menu[i]->name,menu[i]->seat);

		if(done[i]!=NULL){
			printf("%d %s %d\n",done[i]->id,done[i]->name,done[i]->seat);
		fprintf(out,"%d %s %d\n",done[i]->id,done[i]->name,done[i]->seat);
	}
	}
	
	
	return 0;
}
void input(FILE *fp,int n,PNode menu[]){
	int i,j,k=0;
	char a[100];
	int digit=0;
	for(i=0;i<n;i++){
		menu[i]=(PNode)malloc(sizeof(Node));
		fgets(a,100,fp);
		//学号 
		for(j=0;a[j]!=' ';j++){
			digit=digit*10+a[j]-'0';
		}
		menu[i]->id=digit;
		digit=0;
		//姓名 
		for(j=j+1;a[j]!=' ';j++){
			menu[i]->name[k++]=a[j];
		}
		menu[i]->name[k]='\0';
		k=0;
		//座位号
		for(j=j+1;isdigit(a[j])!=0;j++){
			digit=digit*10+a[j]-'0';
		} 
		menu[i]->seat=digit;
		digit=0;
	}
}

void bubbleSort(PNode menu[], int n){
	int i, j;
	int temp;
	PNode p=NULL;
	for (i=0;i<n-1;i++) {
		int flag = 1;
		for (j=0;j<n-1-i;j++){
			if (menu[j]->seat>menu[j+1]->seat){
				p=menu[j];
				menu[j]=menu[j+1];
				menu[j+1]=p;
				flag = 0;
			}	
		}	
		if(flag == 1)
			break;
	}
}
int insert(PNode menu[],PNode done[],int q){
	int j=q-1,que=1;
	int i;
	int k=0;
	for(i=0;i<q;i++){
		if(menu[i]->seat==que){
			done[k]=menu[i];
			k++;
			que++;
		}
		else{
			//空位 
			if(menu[i]->seat>que){
				menu[j]->seat=que;
				done[k]=menu[j];
			//	done[k]->seat=que;
				j--;
				k++;
				que++;
				i--;
			}
			//重复 
			else if(menu[i]->seat<que){
				done[k]=menu[i];
				k++;			
			}
		}
	}
	return que;
}
int pickout(PNode menu[],PNode done[],int q,int n){
	int i;
	int que=1;
	int b=n;
	int m=q;
	for(i=0;i<n;i++){
		//重复 
		if(done[i]->seat<que){
			done[b]=done[i];
			done[b]->seat=m;
			b++;
			m++;
			done[i]=NULL;
		}
		else{
			que++;
		}
	}
	return b;
}
void Sort(PNode menu[], int n){
	int i, j;
	int temp;
	PNode p=NULL;
	for (i=0;i<n-1;i++) {
		int flag = 1;
		for (j=0;j<n-1-i;j++){
			if (menu[j]->id>menu[j+1]->id){
				p=menu[j];
				menu[j]=menu[j+1];
				menu[j+1]=p;
				flag = 0;
			}	
		}	
		if(flag == 1)
			break;
	}
}
void deletenull(PNode menu[], int n){
	int i,j;
	for(i=0;i<n;i++){
		if(menu[i]==NULL){
			for(j=i;j<n;j++){
				menu[j]=menu[j+1];
			}
		}
	}
}

