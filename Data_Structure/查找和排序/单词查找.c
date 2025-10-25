#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define NHASH  3001
#define MULT  37

typedef struct _WordTable{
	char word[20];
	int count;
	struct _WordTable* link; 
} WordTable, * PWordTable;
PWordTable wordTable[10000] = { NULL };

int times=0;
int getword(char w[][20],FILE *bp,int max);
int op1(char w[][20],char str[],int max);
int op2(char w[][20],int low, int high,char str[]);
void create(int w[][3],char word[][20],int max);
int op3(char word[][20],int w[][3],char str[]);
unsigned int hash(char *str);
PWordTable Insert(char word[]);
PWordTable search(char word[]);
int op4(char str[],char word[][20],int max);

int main(){
	FILE *bp;
	int j,i,k=0;
	int op;
	int max;
	int sum;
	char word[3500][20];
	char str[20];
	char c;
	int w[30][3]={0};
	bp=fopen("dictionary3000.txt","r");
	max=getword(word,bp,3500);
	
	while(scanf("%c",&c)!=EOF){
		if(isalpha(c)){
			str[k]=c;k++;
		}
		else if(c==' '){
			str[k]='\0';
			scanf("%d",&op);
			getchar();			
			if(op==1){
				sum=op1(word,str,max);
				if(strcmp(str,word[sum-1])==0){
					printf("1 %d\n",sum);
					//puts(word[sum-1]);
				}
				else {
					printf("0 %d\n",sum);
				}
			}
			else if(op==2){
				sum=op2(word,0,max-1,str);
				if(sum==-1){
					printf("0 %d\n",times);				
				}
				else {
					printf("1 %d\n",times);
				}
				times=0;	
			}
			else if(op==3){
				create(w,word,max);
				sum=op3(word,w,str);
			} 
			else if(op==4){
				sum=op4(str,word,max);
			}
			
			break;
		}
	}
	 return 0;
}
int getword(char w[][20],FILE *bp,int max){
	int i=0;
	while(i<max&&fscanf(bp,"%19s",w[i])!= EOF){
		//puts(w[i]);
		i++;
	}
	return i;
}
int op1(char w[][20],char str[],int max){
	int i=0;
	while(i<max&&(strcmp(w[i],str)<0)){
		i++;
	}
	
	return i+1;
}
int op2(char w[][20],int low, int high,char str[]){
	int mid;
	if (low > high)
		return -1;
	else{
		times++;
		mid = (low + high) / 2;
		if (strcmp(w[mid],str)==0)
			return mid;
		else if (strcmp(w[mid],str)>0)
			return op2(w, low, mid-1, str);
		else
			return op2(w, mid + 1, high, str);
	}
}
void create(int w[][3],char word[][20],int max){
	int i,j=0;
	int lastnum1=0,lastnum2=0;
	char c='\0',lastc='\0';
	w[0][1]=0;
	for(i=0;i<max;i++){
		if(i==0){
			c=word[0][0];
			lastc=c;
		}
		else{
			lastc=c;
			c=word[i][0];
		}
		
		if(c==lastc){
			w[j][2]++;
			lastnum1=w[j][2];
		}
		else{	
			j=word[i][0]-'a';
			w[j][1]=lastnum1+lastnum2;
			lastnum2=w[j][1];
			w[j][2]++;	
		}
	}
	/*
	for(i=0;i<30;i++){
		printf("%d ",i);
		for(j=1;j<3;j++){
			printf("%d ",w[i][j]);
		}
		printf("\n");
	}
	*/
}
int op3(char word[][20],int w[][3],char str[]){
	int sum,low,high;
	low=w[str[0]-'a'][1];
	high=w[str[0]-'a'][1]+w[str[0]-'a'][2];
	//printf("%d %d\n",low,high);
	sum=op2(word,low,high-1,str);
	if(sum==-1){
		printf("0 %d\n",times);				
	}
	else {
		printf("1 %d\n",times);
	}
	times=0;
}
int op4(char str[],char word[][20],int max){
	int i;
	PWordTable p=NULL;
	for(i=0;i<max;i++){
		Insert(word[i]);
	}
	p=search(str);
	if(p==NULL){
		printf("0 %d\n",times);	
	}
	else {
		printf("1 %d\n",times);
	}
	times=0;
}

unsigned int hash(char *str)
{
       unsigned int h=0;
       char *p;
       for(p=str; *p!='\0'; p++)
              h = MULT*h + *p;
       return h % NHASH;

}
PWordTable Insert(char word[]){
	int h=hash(word); 
	PWordTable p = wordTable[h]; 
	PWordTable r = p; 
	while (p != NULL) {
		r=p; p=p->link;	
	}
	p = (PWordTable)malloc(sizeof(WordTable)); 
	strcpy(p->word, word);
	p->link = NULL;
	if (r == NULL) 
		wordTable[h] = p;
	else 
		r->link = p; 
	return r;
}
PWordTable search(char word[]){
	int h=hash(word);
	PWordTable p = wordTable[h]; 
	PWordTable r = p; 
	while (p != NULL) {
		times++;
		if (strcmp(p->word, word)==0){ 
            return p;
        }
        else if(strcmp(p->word, word)>0){
			return NULL;
		}
		else if(strcmp(p->word, word)<0){
			
			r=p; p=p->link;
		}
	}
	return NULL;
}


