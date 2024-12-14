#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct menu{
	char name[52];
	char author[22];
	char press[32];
	char year[12];
	int flag;
}*pmenu;
int cmp(const void*p1,const void *p2);
int input(struct menu m[]); 
int insert(int sum,struct menu m[]);
void search(int sum,struct menu m[]);
void delet(int sum,struct menu m[]);
void save(int sum,struct menu m[]);
int main (){
	struct menu books[500];
	struct menu de[500];
	int i,j;
	for(i=0;i<500;i++){
		for(j=0;j<12;j++){
			books[i].name[j]='\0';
			de[i].name[j]='\0';
			books[i].author[j]='\0';
			de[i].author[j]='\0';
			books[i].press[j]='\0';
			de[i].press[j]='\0';
			books[i].year[j]='\0';
			de[i].year[j]='\0';
		}
	}

	int n=0;
	int a=0;
	scanf("%d", &a);

	n=input(books);
	while(a>=0){
		
		getchar();

		if(1==a){
			//printf("n=%d",n);
			n=insert(n,books);
			//printf("nn=%d\n",n);
		}
		else if(2==a){
			search(n,books);
		}
		else if(3==a){
			delet(n,books);

		}
		else if(0==a){
				save(n,books);
				break;
		}
		scanf("%d", &a);
	
	
	}
		
	return 0;
}
int cmp(const void* p1,const void*p2){
	return strcmp((char *)p1,(char *)p2);
}
//录入信息 
int input(struct menu m[]){
	FILE *in;
	in=fopen("books.txt","r");

	int i=0,j=0,k=0;
	char b[120];

	for(j=0;fgets(b,115,in)!=NULL;j++){
		for(i=0;b[i]!=' ';i++){
			m[j].name[i]=b[i];	
		}
		m[j].name[i]='\0';
		
		k=0;
		for(i=i+1;b[i]!=' ';i++){
			m[j].author[k]=b[i];
			k++;
		//	printf("%c",m[j].author[k]);
		}
		//puts(m[j].author);
		m[j].author[k]='\0';
		
		k=0;
		for(i=i+1;b[i]!=' ';i++){
			m[j].press[k]=b[i];
			k++;
		}
		m[j].press[k]='\0';
		
		k=0;
		for(i=i+1;b[i]!='\0';i++){
			m[j].year[k]=b[i];
			k++;
		}
		m[j].year[k]='\0';
		//getchar();
		m[j].flag=0;
	}
	//printf("\nj1=%d\n",j);

	
	qsort(m,j,sizeof(m[0]),cmp);

	
	fclose(in);
	return j;
} 
//插入
int insert(int sum,struct menu m[]){

	int i=0,k=0;
	int j=sum;
	char b[130];
	
	gets(b);


		for(i=0;b[i]!=' ';i++){
			m[j].name[i]=b[i];
			//printf("%d%c",i,b[i]);	
		}
		m[j].name[i]='\0';
		//puts(m[j].name);
		for(i=i+1;b[i]!=' ';i++){
			m[j].author[k]=b[i];
			k++;
		}
		m[j].author[k]='\0';
		k=0;
		for(i=i+1;b[i]!=' ';i++){
			m[j].press[k]=b[i];
			k++;
		}
		m[j].press[k]='\0';
		k=0;
		for(i=i+1;b[i]!='\0';i++){
			m[j].year[k]=b[i];
			k++;
		}
		m[j].year[k]='\0';
		m[j].flag=0;
		//puts(m[j].author);
		qsort(m,j+1,sizeof(m[0]),cmp);
		/*for(i=0;i<=j;i++){
			printf("%c",m[i].name[0]);
		}
		*/
		
		
	//printf("j=%d",j);
	return j+1;
} 
void search(int sum,struct menu m[]){
	char a[120];
	gets(a);
	int i=0;
	int j=0;
	char *p;
	
	for(i=0;i<sum;i++){
		p=strstr(m[i].name,a);
		if(p!=NULL&&m[i].flag==0){
			//printf("%d",i);
			puts(m[i].name);
			//printf("%d",strlen(m[i].name));
			for(j=strlen(m[i].name);j<50;j++){
				printf(" ");
			}
			puts(m[i].author);
			for(j=strlen(m[i].author);j<20;j++){
				printf(" ");
			}
			puts(m[i].press);
			for(j=strlen(m[i].press);j<30;j++){
				printf(" ");
			}
			puts(m[i].year);
			for(j=strlen(m[i].year);j<10;j++){
				printf(" ");
			}
			printf("\n");
				
		}
	}
	
}
void delet(int sum,struct menu m[]){
	char a[120];
	gets(a);
	int i=0;
	char *p;
	for(i=0;i<sum;i++){
		p=strstr(m[i].name,a);
		if(p!=NULL){
		m[i].flag=1;
		}
	}	
}
void save(int sum,struct menu m[]){
	FILE *out;
	out=fopen("ordered.txt","w");
	int i=0,j;

	
	for(i=0;i<sum;i++){
		if(m[i].flag==0){
			
			fputs(m[i].name,out);
			for(j=strlen(m[i].name);j<50;j++){
				fputc(' ',out);
			}
			//printf("%d",strlen(m[i].author));
			
			fputs(m[i].author,out);
			for(j=strlen(m[i].author);j<20;j++){
				fputc(' ',out);
			}
			fputs(m[i].press,out);
			for(j=strlen(m[i].press);j<30;j++){
				fputc(' ',out);
			}
			fputs(m[i].year,out);
			for(j=strlen(m[i].year);j<10;j++){
				fputc(' ',out);
			}
			fputc('\n',out);	
		}	
	}

	fclose(out);
}

