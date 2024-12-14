#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct _Node
{
	int add;
	int size;
	int flag;
	struct _Node *link;
}Node, *Nodeptr;

Nodeptr creatlist(int n);
Nodeptr operate(int n,int a,Nodeptr x);

int main (){
	int b=0,i,n;
	Nodeptr f,q;
	scanf("%d",&n);
	f=creatlist(n);


	scanf("%d",&b);	
	while(b!=-1){
		//printf("操作：%d",b);
	q=operate(n,b,f);
	f=q;
	//printf("add:%d ",f->add);
		scanf("%d",&b);
		//printf("\n");
	}
	for(i=0;i<n;i++){
		if(f->size!=0){
			printf("%d %d\n",f->add,f->size);
		}
		f=f->link;
	}
	return 0;
}

Nodeptr creatlist(int n){
	int a,b,i;
	Nodeptr head=NULL;
	Nodeptr p=NULL,r;
	
	for(i=0;i<n;i++){
		r=(Nodeptr)malloc(sizeof(Node));
		scanf("%d%d",&a,&b);	
	//	printf("%d %d\n",a,b);
		r->add=a;
		r->size=b;
		r->flag=0;
		r->link=NULL;
		if(head==NULL)
			head=p=r;
		else
			p->link=r;
		p=r;
	}
	p->link=head;
	return head;
}
Nodeptr operate(int n,int a,Nodeptr x){
	Nodeptr r,m,p;
	int i,sum=0;
	r=x;
	p=x;

	//遍历看大小 
	for(i=0;i<n;i++){
	
		if((p->size)>a){
			p->flag=1;
			sum=2;
			//printf("大于%d ",p->add);
		} 	
		else if(a==(p->size)){
			p->size=0;
		//	r=p->link;
			sum=0;
		//	printf("等于%d ",p->add);
			break;
			
		}
		p=p->link;
		r=p;
	}
	
	if(sum==2){
		for(p=x;p->flag!=1;p=p->link);
		r=p;
		//找到起一个flag=1的 
		for(i=0;i<n;i++){
			if (p->size < r->size&&p->flag==1){
				r=p;
			}
			p=p->link;
		//printf("sum:%d,r:%d ",sum,r->add);	
		}
		r->size-=a;
		//printf("处理%d ",r->add);
		
		m=x;
		
	

	}
	for(i=0;i<n;i++){
			x->flag=0;
			x=x->link;
		}	sum=0;
	return r;
}



