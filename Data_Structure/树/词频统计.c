#include <stdio.h>
#include <string.h>
#define MAXWORD 32
struct tnode
{
    char word[MAXWORD];
    int count;
    struct tnode *left, *right;
}; 

int getWord(FILE *bfp, char *w); 
struct tnode *treeWords(struct tnode *p,char *w);
void treePrint(struct tnode *p);


int main() {
	char word[MAXWORD]; 
	FILE *bfp;

	struct tnode *root = NULL;
    
    bfp = fopen("article.txt", "r");
    while (getWord(bfp, word) >0)
		root = treeWords(root, word);
		
	
	if(root!=NULL){
		printf("%s ",root->word);
		if(root->right!=NULL){
			printf("%s ",root->right->word);
			if(root->right->right!=NULL)
				printf("%s",root->right->right->word);
		}
	}
	printf("\n");
		
	treePrint(root);
	
	fclose(bfp); 
	return 0;
}

struct tnode *treeWords(struct tnode *p, char *w){
	int cond;
	if (p == NULL){
        p = (struct tnode *)malloc(sizeof(struct tnode));
        strcpy(p->word, w); 
		p->count = 1;
        p->left = p->right = NULL;   
	}
	else if ((cond = strcmp(w, p->word)) == 0) 
		p->count++;
	else if (cond < 0) 
		p->left = treeWords(p->left, w);
	else 
		p->right = treeWords(p->right, w);
	return p; 
}
void treePrint(struct tnode *p){
	if (p != NULL) {
		treePrint(p->left);
		printf("%s %d\n", p->word, p->count);
		treePrint(p->right);		
	} 
}
int getWord(FILE *bfp, char *w){
	char c;
	int i=0;
	
	while ((c = fgetc(bfp)) != EOF) {
        if (isalpha(c)) {
            break;
        }
    }
    while (isalpha(c) && i < MAXWORD - 1) {
        w[i++] = tolower(c);
        c = fgetc(bfp);
    }

	w[i]='\0';
	return i;
}




