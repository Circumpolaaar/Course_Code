#include <stdio.h>

struct node{
    int data;
    int num;
	struct node *lchild, *rchild; 
};
typedef struct node BTNode, *BTNodeptr; 
BTNodeptr insertBST(BTNodeptr p, int item,int depth); 
void search(BTNodeptr p);
int main(){
	int i, item;
	int n;
	BTNodeptr root = NULL;
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{ 
        scanf("%d", &item);
		root = insertBST(root, item,1); 
	}
	search(root); 

	return 0; 
}

BTNodeptr insertBST(BTNodeptr p, int item, int depth) {
    if (p == NULL) {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->num = depth; // Set the depth of the new node
        p->lchild = p->rchild = NULL;
    } else if (item < p->data) {
        p->lchild = insertBST(p->lchild, item, depth + 1); // Increase depth for left child
    } else if (item >= p->data) {
        p->rchild = insertBST(p->rchild, item, depth + 1); // Increase depth for right child
    }
    return p;
}
void search(BTNodeptr p){
	if(p==NULL){
		return;	
	}

	if (p->rchild == NULL&&p->lchild==NULL)
    {
		printf("%d %d\n",p->data,p->num);
    }
	search(p->lchild);
	search(p->rchild);
}


