#include <stdio.h> 
#include<stdlib.h>
#include <string.h> 
#include <ctype.h> 
#define MAXWORD 32 
#define MAXSIZE 1024 
struct WORD {
    char word[MAXWORD];
	int count;
}words[MAXSIZE];
int num=0;

void insert(char *w);
int getWord(FILE *fp,char *w);
int cmp(void const *a,void const*b);

int main(){

	char w[MAXWORD]; 
	FILE *fp;
	fp=fopen("article.txt","r");
	int i,j=0;
    for(i=0;i<MAXSIZE;i++){
    	words[i].count=0;
	}
    while( getWord(fp,w) !=EOF){
    	//puts(w);
		insert(w);
	}
	qsort(words,num,sizeof(struct WORD),cmp);
	for(i=0;i<num;i++){
		for(j=0;j<strlen(words[i].word);j++){
			printf("%c",words[i].word[j]);
		}

		printf(" %d\n",words[i].count);
	}
	return 0; 
}

int getWord(FILE *fp,char *w){
    int c;
	
    while(!isalpha(c=fgetc(fp)))
    	if(c == EOF) return c;	

    do  {
		*w++ = tolower(c);
	//printf("%c",tolower(c));
	} while(isalpha(c=fgetc(fp))); 
	*w='\0';
	//puts(w);
	return 1; 
}
void insert(char *w){
	int i=0;
	for(i=0;i<num;i++){
		if(strcmp(words[i].word,w)==0){
			words[i].count++;
			return;
		}
	}
	words[num].count++;
	strcpy(words[num].word,w);
	num++;
}
int cmp(void const *a,void const*b){
	int x;
	x=strcmp((*(struct WORD *)a).word,(*(struct WORD *)b).word);
	if(x<0){
		return -1;
	}
	return 1;
}





