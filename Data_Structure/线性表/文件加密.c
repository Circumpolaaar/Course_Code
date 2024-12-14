#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct _Node{
	char ch;
	struct _Node *link; 
}Node, *PNode;	

void removeDup(char *key);
//�ַ���ȥ��
PNode buildCircle(char key[], char allchar[]);
//������Կ�����ַ��� 
void getPasswordTab(PNode list, char passtab[]);
//������Կ��
void encodeFile(char tab[]);
//�����ļ�

int main(){
	char key[40], passtab[95]; 
	int i=0;
	PNode list = NULL; 
	for(i=0;i<40;i++){
		key[i]='\0';
	}
	gets(key);
	removeDup(key); //ȥ���ظ��ַ� 
	
	for (i = 0; i < 95; i++)
	passtab[i] = i+' ';
//	puts(passtab);	
	//����ȫ���ַ����� 
	for (i = 0; key[i] != '\0'; i++)
	passtab[key[i]-' '] = '\0'; 
	//ɾ����Կ�е��ַ�

	list = buildCircle(key, passtab); 
	//������Կ��ʣ����ַ��������ַ�����
	
	getPasswordTab(list, passtab); 
	//������Կ��
	
	encodeFile(passtab); 
	//������Կ�Լ����ļ�
	return 0; 
}
void removeDup(char *key){
	int i=0,j=0,k=0;
	int flag=0;
	int n=strlen(key);
	for(i=1;i<n;i++){
		j=i-1;
		while(j>=0){
			if(key[i]==key[j]){
				++flag;
				break;
			}
			else{
				--j;
			}
		}
		if(j<0)
			key[i-flag]=key[i];
	}
	
	key[n-flag]='\0';
	//puts(key);

}

PNode buildCircle(char key[], char allchar[]){
	int a=0,i;
	PNode head=NULL;
	PNode p=NULL,r;
	
	for(i=0;i<strlen(key);i++){
		r=(PNode)malloc(sizeof(Node));
		r->ch=key[i];
		r->link=NULL;
		if(head==NULL)
			head=p=r;
		else
			p->link=r;
		p=r;
	}
	for(a=0;a<95;a++){
		if(allchar[a]!='\0'){
			r=(PNode)malloc(sizeof(Node));
			r->ch=allchar[a];
			r->link=NULL;
			p->link=r;
			p=r;	
		}
	
	}
	p->link=head;

	return head;
}

void getPasswordTab(PNode list, char passtab[]){
	int i=0,j=0;
	PNode p=NULL,q=NULL,r=NULL;
	p=list;
	//ȥ����һ�� 
	//for(p=list;p->link!=list;p=p->link);
	//p->link=list->link; 
	q=p;
	for(r=list;r->link!=q;r=r->link);
	while(p->link!=p){
		//��pɾ�� 
		r->link=q->link;
		for(i=0;i<(int)q->ch;i++){

			r=p;
			p=p->link;
		}
		
		//printf("Ų%d ",(int)q->ch);
	//	printf("����%c\n",passtab[q->ch-' ']);	
		passtab[q->ch-' ']=p->ch;
		//printf("����%c\n",p->ch);		

		q=p;		
		
		
		//printf("1:%c %c\n",r->ch,p->ch);
		
	}
	passtab[p->ch-' ']=list->ch;
	
	puts(passtab);
	
}
void encodeFile(char tab[]){
	FILE *in,*out;
	char c;
	int i=0;
	in=fopen("in.txt" ,"r");
	out=fopen("in_crpyt.txt","w");
	while((c=fgetc(in))!=EOF){
		if(32<=(int)c&&(int)c<=126)
		fputc(tab[(int)c-' '],out);
		else
		fputc(c,out);
	}
	fclose(in);
	fclose(out);
}


