#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main (){
	char a[100],b[100];
	char c[10000];
	char alpha[30];
	int i=0,j=0,k=0;
	int m=0,flag=0;
	char z='z';
	char A='a';
	for(i=0;i<26;i++){
		alpha[i]=A;
		A++;
	}
//	puts(alpha);
	for(i=0;i<10000;i++)
		c[i]='\0';
	
	FILE *in,*out;	
	in=fopen("encrypt.txt","r");
	out=fopen("output.txt","w");
	if(in==NULL){
		return -1;
	}
	if(out==NULL){
		return -1;
	}
	fread(c,1,10000,in); 
//	printf("%s",c);

	gets(a);
	for(i=0;i<strlen(a);i++){
		for(j=0;j<i;j++){
			if(a[i]==a[j])flag=1;
		}
		if(flag==0){
			b[k]=a[i];
			k++;
		}
		flag=0;
	}
	flag=0;
	for(k;k<26;k++){
		for(j=0;j<strlen(b);j++){
			if(z==b[j]){
				flag=1;
			}	
		}
		if(flag==0){
			b[k]=z;
		//	printf("%d%c ",k, b[k]);
			z--;	
		}
		else{
			z--;
			k--;
		}
		flag=0;
	}
	puts(b);
	fread(c,1,10000,in);
	for(i=0;i<strlen(c);i++){
		if(isalpha(c[i])){
			for(k=0;k<26;k++){
				if(c[i]==alpha[k]){
					
					printf("i=%d k=%d c=%c b=%c\n",i,k,c[i],b[k]);
			c[i]=b[k];	break;}
			}
		}
	
	}
	
	
	
	
	
	fputs(c,out);	
	
	fclose(in);
	fclose(out);
	
	
	return 0;
} 

