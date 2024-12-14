#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct _ElemType{
	int coe;
	int pow;
}ElemType;
typedef struct _Node
{
	ElemType data;
	struct _Node *link;
}Node, *Nodeptr;

Nodeptr creatNode(ElemType item);
void insertSortNode(Nodeptr list,ElemType item);
void insertNode(Nodeptr list,ElemType item);
Nodeptr creatNode(ElemType item){
	Nodeptr p;
	p=(Nodeptr)malloc(sizeof(Node));
	p->data=item;
	p->link=NULL;
	return p;
}
void insertSortNode(Nodeptr list,ElemType item){
	Nodeptr p,q,r;
	for(q=list,p=list->link;p!=NULL&&p->data.pow>item.pow;q=p,p=p->link);
	if(p==NULL){
		r=creatNode(item);
		q->link=r;
	}
	else{
		r=creatNode(item);
		r->link=p;
		q->link=r;
	}
}
void insertNode(Nodeptr list,ElemType item){
	Nodeptr p,q,r;
	for(q=list,p=list->link;p!=NULL&&p->data.pow>item.pow;q=p,p=p->link);
	if(p==NULL){
		r=creatNode(item);
		q->link=r;
	}
	else{
		if (p->data.pow == item.pow) 
			p->data.coe += item.coe;
		else{
			
		
		r=creatNode(item);
		r->link=p;
		q->link=r;}
	}
}

int main (){
	ElemType item;
	char ch;
	Nodeptr p,q,list1,list2,list3;
	item.coe=0;item.pow=0;
	list1=creatNode(item);	
	list2=creatNode(item);
	list3=creatNode(item);
	do{
		scanf("%d%d%c",&item.coe,&item.pow,&ch);
		insertSortNode(list1,item);
	}while(ch!='\n');
	do{
		scanf("%d%d%c",&item.coe,&item.pow,&ch);
		insertSortNode(list2,item);
	}while(ch!='\n');
	
	for(p=list1;p!=NULL;p=p->link){
		for(q=list2;q!=NULL;q=q->link){
			item.coe=(p->data.coe)*(q->data.coe);
			//printf("%d %d ",p->data.coe,q->data.coe);
			item.pow=(p->data.pow)+(q->data.pow);
			insertNode(list3,item);
		}
		
	}
	
	
	for(p=list3;p!=NULL;p=p->link){
		if(p->data.coe!=0)
		printf("%d %d ",p->data.coe,p->data.pow);
	}
	return 0;
}


