
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 512
typedef struct edge{
	int eno; 
	int adj; 
	int weight;
	struct edge *next;
}Elink;
typedef struct ver
{ 
	Elink *link;
}Vlink;
Vlink Graph[MAXSIZE]={0}; 
char Visited[MAXSIZE]={0};
int Paths[MAXSIZE];
void eDFS(int v, int level);
Elink *insertEdge(Elink *head, int avex,int eno);
int V0, V1;
int main(){
	int en,eno,i,v1,v2,Vnum;
	scanf("%d %d", &Vnum, &en);
	for(i=0; i<en; i++){
		scanf("%d %d %d", &eno, &v1, &v2);
		Graph[v1].link = insertEdge(Graph[v1].link,v2, eno);
		Graph[v2].link = insertEdge(Graph[v2].link,v1, eno);
	}
	V0 = 0; 
	V1 = Vnum-1; 
	Visited[V0] = 1;
	eDFS(V0,0);
	return 0;
}
Elink *insertEdge(Elink *head, int avex,int eno){
	Elink *e,*p;
	e =(Elink *)malloc(sizeof(Elink));
	e->adj= avex; 
	e->eno=eno; 
	e->next=NULL;
	if(head == NULL){
		head=e; 
		return head;
	}
	for(p=head;p->next != NULL; p=p->next);
	p->next = e; 
	return head;
}

void eDFS(int v, int level){
	struct edge *p;
	int i;
	if(v == V1) {
		for (i=0;i<level;i++) {
            printf("%d ", Paths[i]);
        }
        printf("\n");
		return;
	}
	for(p=Graph[v].link; p!= NULL; p=p->next) 
		if( !Visited[p->adj]){
			Paths[level] = p->eno;
			Visited[p->adj] = 1;
			eDFS(p->adj,level+1);
			Visited[p->adj] = 0;
		}
}



