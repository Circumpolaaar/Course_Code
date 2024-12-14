#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()  {           
	char s[1000]={"0"};
	int i, k,j,b;
	
	gets(s);
	for(k=0; s[k]!='.'&&s[i]!='\0'; k++);
	for(i=k; s[i]!='\0';i++);
	//printf("%d %d\n",k,i );
	
	if(s[0]!='0'){
		printf("%c.",s[0]);
	
	for(j=1;j<i;j++){
		if(s[j]!='.')
		printf("%c",s[j]);
	}
	
	printf("e%d", k-1);
	}
	else{
		for(j=2;s[j]=='0';j++);
		printf("%c",s[j]);
		if(j!=i-1)printf(".");
		
		for(b=j+1;b<i;b++){
		if(s[b]!='.')
		printf("%c",s[b]);
	}
	
	printf("e-%d", j-1);
	}
	
	return 0;}



