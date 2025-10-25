#include <stdio.h> 
#include<stdlib.h>
#include <string.h> 
#include <ctype.h>  
int main(){
	char a[200][200];
	char b[210];
	int bline[200];
	int i=0,j=0,k=0,m=1,n=0;
	FILE *fp;
	fp=fopen("example.c","r"); 
	while(fgets(a[i],200,fp)!=NULL)	{
	//	puts(a[i]);	
		i++;
	
	}
	for(k=0;k<i;k++){
		for(j=0;j<strlen(a[k]);j++){

		if(a[k][j]=='/'&&a[k][j+1]=='/'){
			a[k][j]='0';a[k][j+1]='0';
			for(j=j;j<strlen(a[k]);j++){
				a[k][j]='0';
			}
		}
		else if(a[k][j]=='/'&&a[k][j+1]=='*'){
			a[k][j]='0';a[k][j+1]='0';
			for(n=j+2;a[k][n]!='*'&&a[k][n+1]!='/';n++){
				a[k][n]='0';
			}
			a[k][n]='0';a[k][n+1]='0';
		}
		else if(a[k][j]=='"'){
			a[k][j]='0';
			for(n=j+1;a[k][n]!='"';n++){
				a[k][n]='0';
			}
			a[k][n]='0';
		}
		}	
	}	
	/*for(k=0;k<i;k++){
		puts(a[k]);
	}
	*/
	for(k=0;k<i;k++){
		for(j=0;j<strlen(a[k]);j++){
			//printf("%c",a[k][j]);		
		if(a[k][j]=='('){
			//ÈëÕ» 
			b[m]=a[k][j];
			bline[m]=k;
			m++;
			//printf("b[%d]=%c\n",m-1,b[m-1]);
			
		}
		else if(a[k][j]=='{'){
			if(b[m-1]=='('){
			
				printf("without maching '(' at line %d",bline[m-1]+1);
				return 0;
			}
			else {
				//ÈëÕ» 
				b[m]=a[k][j];
				bline[m]=k;
				m++;
				//printf("b[%d]=%c\n",m-1,b[m-1]);
			}
		}
		else if(a[k][j]==')'){
			if(b[m-1]=='('){
				m--;
				//printf("match()\n");
			}
			else{
				printf("without maching ')' at line %d",k+1);
			return 0;
			}
		}
		else if(a[k][j]=='}'){
			if(b[m-1]=='{'){
				m--;
				//printf("match{}\n");
			}
			else{
				printf("without maching '}' at line %d",k+1);
			return 0;
			}
		}	
		}
		
	}	
	if(m==2){
		printf("without maching '%c' at line %d",b[m-1],bline[m-1]+1);
	}

	else if(m==1){
		for(k=0;k<i;k++){
			for(j=0;j<strlen(a[k]);j++){
				if(a[k][j]=='('||a[k][j]==')'||a[k][j]=='{'||a[k][j]=='}')
				printf("%c",a[k][j]);}}}
	fclose(fp);

	return 0; 
}



