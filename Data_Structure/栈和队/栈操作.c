#include <stdio.h> 
#include<stdlib.h>
#include <string.h> 
#include <ctype.h>  
int main(){
	int a[200];
	int b,c;
	int i=0;
	

	while(scanf("%d",&b)!=EOF){
		
		if(b==1){
			scanf("%d",&c);
			if(i==99){
				printf("error ");
				i=99;
			}
			else{
				a[i]=c;	
				i++;
			}
		}
		else if(b==0){
			i--;
			if(i<0){
				printf("error ");
				i=0;
			}
			else
			printf("%d ",a[i]);
		}
		
		
	
	}	


	return 0; 
}



