#include <stdio.h>
#include <string.h>
#define NodeNum 200
struct tnode
{
    int num;
    int now;
    struct tnode *child1, *child2,*child3;
}; 

struct tnode *createnode(); 
void createtree(struct tnode *root,struct tnode *p);
void search(struct tnode *root,struct tnode *p);
void sort(int x,int(*w)[200]);
void fillin(int x,int (*w)[200],struct tnode *t);



int main() {
	struct tnode *root = NULL,*p=NULL;
	int w[4][200];
	int x=0,i=0;
	int num,flow;
    root=createnode();
    while ((p=createnode())!=NULL){
    	
    	createtree(root,p);
		//printf("%d",root->num);
	}
	while(scanf("%d%d",&num,&flow)!=EOF){
		w[0][x]=num;
		w[1][x]=flow;
		//printf("%d %d\n",num,flow);
		x++;
	}
	sort(x,w);
	
	/*for(i=0;i<x;i++){
		printf("%d ",w[0][i]);
	}*/
	fillin(x,w,root);	
	
	for(i=0;i<x;i++){
		if(i<200)
		printf("%d->%d\n",w[0][i],w[3][i]);
		else break;
	}
	return 0;
}



struct tnode *createnode(){
	struct tnode * p=NULL;
	int r=0,flag1=-1,flag2=-1;

	scanf("%d",&r);

	if(r!=-1){
		p = (struct tnode *)malloc(sizeof(struct tnode));
		p->child1=p->child2=p->child3=NULL;
		p->child1 = (struct tnode *)malloc(sizeof(struct tnode));
		
		p->child1->child1=p->child1->child2=p->child1->child3=NULL;
		
		p->num=r;
		scanf("%d%d",&p->child1->num,&flag1);
		
		if(flag1!=-1){
			p->child2 = (struct tnode *)malloc(sizeof(struct tnode));
			p->child2->child1=p->child2->child2=p->child2->child3=NULL;
			p->child2->num=flag1;
			scanf("%d",&flag2);
			if(flag2!=-1){
				p->child3 = (struct tnode *)malloc(sizeof(struct tnode));
			p->child3->child1=p->child3->child2=p->child3->child3=NULL;

			p->child3->num=flag2;
			scanf("%d",&flag1);
			}
			
		}
		//printf("%d %d %d\n",p->child1->num,p->child2->num,p->child3->num);
		return p;		
	}
	else{
		return NULL;
	}


}
void createtree(struct tnode *root,struct tnode *p){
	struct tnode *parent=NULL;
	if(root==NULL){
		root=p;
		return;
	}
	else{
		search(root,p);
	}
	
	//printf("root=%d",root->num);
}
void search(struct tnode *root,struct tnode *p){
	struct tnode *r;

    if (root == NULL){
    //	printf("NULL ");
    	return;
    	
	} 
       
    if (root->child1 != NULL){
    	if(root->child1->num == p->num){
    		root->child1=p;
    		return;
    		//printf("%d",root->child1->num);
		}
    	
	}
    if (root->child2 != NULL){
    	if(root->child2->num == p->num){
    		//printf("%d",root->child2->num);
    		root->child2=p;
    		return;
		}
    	
	}
    if (root->child3 != NULL){
    	if(root->child3->num == p->num){
    		//printf("%d",root->child3->num);
    		root->child3=p;
    		return;
		}
    	
	}
	
    search(root->child1, p);
    search(root->child2, p);
    search(root->child3, p);
    
}
void sort(int x,int (*w)[200]){
	int i, j, temp;
	for (i = 0; i < x - 1; i++) { 
        for (j = 0; j < x - i - 1; j++) {
            if (w[1][j] < w[1][j + 1]) {
            	
                temp = w[0][j];
                w[0][j] = w[0][j + 1];
                w[0][j + 1] = temp;
                
                
                temp = w[1][j];
                w[1][j] = w[1][j + 1];
                w[1][j + 1] = temp;
            }
            else if (w[1][j] == w[1][j + 1]&&w[0][j]>w[0][j+1]) {
            	
                temp = w[0][j];
                w[0][j] = w[0][j + 1];
                w[0][j + 1] = temp;
                
                
                temp = w[1][j];
                w[1][j] = w[1][j + 1];
                w[1][j + 1] = temp;
            }
        }
    }
    
}
void fillin(int x,int (*w)[200],struct tnode *t){
	int i=0;
	
	struct tnode *queue[NodeNum];
	struct tnode *p; 
	int front, rear;
	if (t != NULL) {
		queue[0] = t;
		front = -1;
		rear = 0;
		while (front < rear){ 
			p = queue[++front];
			if(i<x){
				if(p->num<100&&p->num>0){
					
					w[3][i]=p->num;
					//printf("%d\n",p->num);
					i++;
				}
			
						
			}
			else break;
			if (p->child1 != NULL)
				queue[++rear] = p->child1;
			if (p->child2 != NULL)
				queue[++rear] = p->child2;
			if (p->child3 != NULL)
				queue[++rear] = p->child3;
		}
	} 
}



