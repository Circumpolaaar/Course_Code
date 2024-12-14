#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
struct node{
    char data[10];
	struct node *lchild, *rchild; };
typedef struct node BTNode, *BTNodeptr;
int calculate(char sym,int x,int y);  
void search(BTNodeptr root);
BTNodeptr create(int x);
int isleaf(BTNodeptr p);
void post(BTNodeptr root);
BTNodeptr createtree(char a,BTNodeptr x1,BTNodeptr x2);
int main(){
	int digit[200]={0};
	char symbol[210]={0};
	int flag[310]={0};
	BTNodeptr p[200];
	char poland[200],a[200]; 
	BTNodeptr root = NULL;
	int x,f;
	int i=0,m=0,n=0,b=0,j=0,k=0;flag[0]=0;
	memset(symbol, '\0', 210);
	memset(symbol, '\0', 210);
	memset(flag, 0, 310);
	gets(a);
	for(i=0;i<strlen(a);i++){
		if(isspace(a[i])){
			if(isdigit(a[i-1])){
				poland[j]='a';
				j++;
			}
		continue;}
		else if(isdigit(a[i])){	
			poland[j]=a[i];
			j++;
		}	
		else{	
			if(isdigit(a[i-1])){
				poland[j]='a';
				j++;
			}
			if(a[i]=='+'||a[i]=='-')b=1;
			else if(a[i]=='*'||a[i]=='/')b=2;
			else if(a[i]=='(')	b=0;
			else if(a[i]=='=') {
				while(k>0){
					poland[j]=symbol[k-1];
					j++;
					k--;
				}break;
			}
			else if(a[i]==')'){
				while(symbol[k-1]!='('){
					poland[j]=symbol[k-1];
					j++;
					k--;
				}
				k--;
				continue;
			}		
			while (k>0&&flag[k-1]>=b&&b!=0) {
				if(j>=2){
					poland[j]=symbol[k-1];
					j++;
					k--;
         	   }
                else break;}
            
            if(a[i]!=')'){
            	symbol[k]=a[i];
				flag[k]=b;
				k++;
			}
		}
	}
	poland[j]='\0';
	//puts(poland);
	x=j;
	j=0;
	//¹¹ÔìÊ÷
	for(i=0;i<x;i++){
		if(isdigit(poland[i])){	
			n=n*10+(poland[i]-'0');
		}
		else if(poland[i]=='a'){
			p[j]=create(n);
			//printf("create%d",n);
				n=0;
				j++;
				
		}
		else{
			//if(n!=0){	
				
			//}
			//else{
				p[j-2]=createtree(poland[i],p[j-2],p[j-1]);
				j=j-1;
			//}
		}
	}
	
	root=p[j-1];
	for(i=0;i<strlen(root->data);i++){
		printf("%c",root->data[i]);
	}
	printf(" ");
	if(root->lchild!=NULL){
		for(i=0;i<strlen(root->lchild->data);i++){
		printf("%c",root->lchild->data[i]);
	}
	printf(" ");
	}
	if(root->rchild!=NULL){
		for(i=0;i<strlen(root->rchild->data);i++){
		printf("%c",root->rchild->data[i]);
	}
	printf("\n");
	}
	if(root->data[0]=='*'&&root->lchild->data[0]=='+')
	printf("0");

	//¼ÆËã
	search(root);
	search(root);
	search(root);
	search(root);
	search(root);
	search(root);
	search(root);
	
	puts(root->data);
	
	return 0; 
}
int calculate(char sym,int x,int y){
	if(sym=='+')return x+y;
	else if(sym=='-')return x-y;
	else if(sym=='/')return x/y;
	else if(sym=='*')return x*y;}
BTNodeptr create(int x){
	BTNodeptr p=NULL;
	p = (BTNodeptr)malloc(sizeof(BTNode));
	p->lchild=NULL;
	p->rchild=NULL;
	int i=0,j=0;char b[10];
	while(x>0){
		b[i]=x%10+'0';
		x=x/10;i++;}
		b[i]='\0';
	for (i = strlen(b) - 1; i >= 0; i--) {
        p->data[j++] = b[i]; 
    }
		p->data[j]='\0';
		
	return p;}
BTNodeptr createtree(char a,BTNodeptr x1,BTNodeptr x2){
	BTNodeptr p=NULL;
	p = (BTNodeptr)malloc(sizeof(BTNode));
	p->data[0]=a;
	p->data[1] = '\0';
	p->lchild =x1;
	p->rchild = x2;
	return p;}
void search(BTNodeptr root){
	BTNodeptr p,q;
	int a,i,j=0,k=0;
	char b[200];
	int x,y;
	int m=0,n=0;
	
	if(isleaf(root->lchild)==1&&isleaf(root->rchild)==1){
		for(i=0;i<strlen(root->lchild->data);i++){
			m=m*10+root->lchild->data[i]-'0';
		}
		for(i=0;i<strlen(root->rchild->data);i++){
			n=n*10+root->rchild->data[i]-'0';
		}
		a=calculate(root->data[0],m,n);
		//printf("%d%c%d=%d\n",m,root->data[0],n,a);
		while(a>0){
			b[k]=a%10+'0';
			a=a/10;
			k++;
		}
		b[k]='\0';
		for (k=strlen(b)-1;k>= 0;k--) {
       		root->data[j++] = b[k]; 
   		}
		root->data[j]='\0';
		//puts(root->data);
		root->lchild=NULL;
		root->rchild=NULL;
		
	}
	else{
		
        if(root->lchild!=NULL)
            search(root->lchild);
        if(root->rchild!=NULL)
            search(root->rchild);
    }
}
int isleaf(BTNodeptr p){

	return p!=NULL &&p->lchild==NULL&&p->rchild==NULL;
	
}
void post(BTNodeptr root){
	if(root!=NULL){
		post(root->lchild);
		post(root->rchild);
		puts(root->data);
	}
}

