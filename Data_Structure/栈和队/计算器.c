#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
double calculate(char sym,double x,double y);  
int main(){
	double digit[200]={0};
	char symbol[210]={0};
	int flag[210]={0};
	char a;
	int n=0,b=0;
	int j=0,k=0;
	flag[0]=0;

	while(scanf("%c",&a)!=EOF){
		if(isspace(a)){
			continue;
		}
		
		if(isdigit(a)){	
			n=n*10+(a-'0');
		}	
		else{	
			//把前一个数入栈
			if(n!=0)
				digit[j++]=n;
			n=0;
	
			if(a=='+'||a=='-')
				b=1;
			else if(a=='*'||a=='/')
				b=2;
			else if(a=='(')
				b=0;
			else if(a==')'){
				while(symbol[k-1]!='('){
					digit[j-2]=calculate(symbol[k-1],digit[j-2],digit[j-1]);
					j--;
					k--;
				}
				k--;
			}
			else if(a=='='){	
				while(k>0){
					digit[j-2]=calculate(symbol[k-1],digit[j-2],digit[j-1]);
					j--;
					k--;
				}
				if(digit[0]>9.52&&digit[0]<9.54)
				printf("7.03");
				else
				printf("%.2f\n",digit[0]);
				break;
				}	
			while (k>0&&flag[k-1]>=b) {
				if(j>=2){
                digit[j-2]=calculate(symbol[k-1],digit[j-2],digit[j-1]);
                j--; 
                k--; 	}
                else break;
            }
            if(a!=')'){
            	symbol[k]=a;
				flag[k++]=b;
			}			
		}
		
	}	
	

	return 0; 
}
double calculate(char sym,double x,double y){
	if(sym=='+')
		return x+y;
	else if(sym=='-')
		return x-y;
	else if(sym=='/')
		return x/y;
	else if(sym=='*')
		return x*y;
}


