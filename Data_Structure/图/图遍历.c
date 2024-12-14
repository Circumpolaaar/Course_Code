
#include<stdio.h>
#include<stdlib.h>
#define MaxV 256
typedef struct  edge{
    int  adj;
    struct edge *next;
}Elink;
typedef struct ver{
    Elink *link;
}Vlink;
Vlink  G[MaxV];
Elink *Q[256];

Elink *insertEdge(Elink *head, int v1,int avex);
int  createGraph(Vlink graph[]);
void depth(Vlink G[], int n);
void DFS(Vlink G[], int v) ;
void width(Vlink G[], int n);
void BFS(Vlink G[], int v );

int emptyQ(Elink *queque[]);
int deQueue(Elink *queque[]);
void enQueue(Elink *queue[], int data);
int dele=0;
int flag=0;
int Visited[256] = {0}; int Visited1[256] = {0}; 
int main(){
	int dot;
	int i;
	Elink *p=NULL,*q=NULL;
	
	
	dot=createGraph(G);
		
	printf("\n");
	depth(G,dot);
	printf("\n");
	width(G,dot);
	printf("\n");
	
	
	scanf("%d",&dele);
	flag=1;
	G[dele].link=NULL;

  
	for (i = 0; i < dot; i++) {
   	 p = G[i].link;
    while (p != NULL) {
        if (p->adj == dele) {
            if (p == G[i].link) { 
                G[i].link = p->next;
            } 
			else { 
                q->next = p->next;
            }
            
            p = p->next;
            
        } 
		else {
            q = p;
            p = p->next;
        }
    }
}
	
	
	
	depth(G,dot);
	printf("\n");
	width(G,dot);
	printf("\n");
	return 0;
}
Elink *insertEdge(Elink *head, int v1,int avex) {
	Elink *e,*q,*p;
	e =(Elink *)malloc(sizeof(Elink)); 
	e->adj= avex;  
	e->next=NULL; 
	if(head == NULL){
		head=e; 
		return head;
	}


		if (head->adj > avex) {
            e->next = head;
            head = e;
            return head;
        } 
		else {
		q=p=head;
		for(p=head;p->next != NULL; p=p->next){
			if(p->adj>avex){
				e->next=p;
				q->next = e;
				return head;	
			}
				q=p;		
		}
		if(p->adj<avex)
			p->next=e;
		else{
			q->next=e;
			e->next=p;
		}	
	}		
    return head;
}
int  createGraph(Vlink graph[]){
	int i,dot,edge,v1,v2; 
	scanf("%d%d",&dot,&edge); 
	for(i=0; i<edge; i++){
    	scanf("%d %d",&v1,&v2);
		graph[v1].link=insertEdge(graph[v1].link, v1,v2); 
		graph[v2].link=insertEdge(graph[v2].link, v2,v1); 		
	}
	return dot; 
}


void depth(Vlink G[], int n){
    int i;
    for (i = 0; i < n; i++){
    	Visited[i] = 0; 
	}
	if(flag==1){
		Visited[dele]=1;
	}
			for (i = 0; i < n; i++)
        if (!Visited[i])
            DFS(G, i);
}
void DFS(Vlink G[], int v) {
	Elink *p;
	Visited[v] = 1; 
	printf("%d ", v);
	for (p = G[v].link; p != NULL; p = p->next)
		if (!Visited[p->adj]) 
			DFS(G, p->adj);
}


void width(Vlink G[], int n){
    int i;
    for (i = 0; i < n; i++){
    	Visited1[i] = 0;
	}
	if(flag==1){
		Visited1[dele]=1;
	}
	for (i = 0; i < n; i++)
		if (!Visited1[i])
			BFS(G,i);
}

void BFS(Vlink G[], int v){ 
	Elink *p;
	printf("%d ",v);
	Visited1[v] = 1; 
	enQueue(Q, v);
	while (!emptyQ(Q)) {
		v = deQueue(Q); 
		p = G[v].link; 
		for (; p != NULL; p = p->next)
			if (!Visited1[p->adj]) {
				printf("%d ",p->adj);
				Visited1[p->adj] = 1; 
				enQueue(Q, p->adj);
			} 
	}
}


int front = 0, rear = -1;
int emptyQ(Elink *queue[]) {
    return rear < front;
}
int deQueue(Elink *queue[]) {
    if (emptyQ(queue)) {
        return -1; 
    }
    Elink *temp = queue[front]; 
    int data = temp->adj; 
    front++; 
    return data;
}
void enQueue(Elink *queue[], int data) {
     Elink *newNode = (Elink *)malloc(sizeof(Elink)); 
    newNode->adj = data; 
    newNode->next = NULL;
    rear++; 
    queue[rear] = newNode; 
}



