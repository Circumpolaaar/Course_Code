#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main (){
	char a[100],b[100];
	char c[10000];
	int i=0,j=0,flag=0;
	
	for(i=0;i<10000;i++)
		c[i]='\0';
	
	FILE *in,*out;
	gets(a);gets(b);	
	int sza=strlen(a),szb=strlen(b);
	in=fopen("filein.txt","r");
	out=fopen("fileout.txt","w");
	if(in==NULL){
	//	printf("1");
		return -1;
	}
	if(out==NULL){
	//	printf("0");
		return -1;
	}
	fread(c,1,10000,in); 
//	printf("%s",c);
//	if(fgets(c,1000,in)==NULL)printf("null");

	
	for(i=0;i<strlen(c);i++){
		if(isalpha(c[i])){
			for(j=0;j<sza;j++){
				if(tolower(c[i+j])==tolower(a[j])){
					flag++;
				//	printf("2\n");
				}
				
			}
			if(flag!=sza){
				fputc(c[i],out);
				//	printf("%c",c[i]);
			}
			else{
				fputs(b,out);
				i=i+sza-1;
			//	printf("4\n");
			}
			flag=0;
		}
		
		else
			fputc(c[i],out);
		
	}
	fclose(in);
	fclose(out);
	
	
	return 0;
} 

