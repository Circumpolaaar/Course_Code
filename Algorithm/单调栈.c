#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int n[300010]={0}; 
int l[300010] = {0}; 
int r[300010] = {0}; 
int stack[300010] = {0};//存放下标 

int main(){
	int x;
	scanf("%d",&x);
	while(x--){
		int a;
		long long int sum=0;
		scanf("%d",&a);
		int top=0;//指向栈顶元素 
		for(int j=1;j<=a;j++){			
			scanf("%d",&n[j]);	
			while(top!=0&&n[j]>n[stack[top]]){
				top--;
			}
			//找到递减栈里第一个比当前元素大的,为n[stack[top]
			//能看到俩人中间的人 
		//	printf("bigger:n[%d]=%d ",stack[top],n[stack[top]]);
			if(top!=0){
				sum+=j-stack[top]-1;
			}
			else{//没有更大的 
				sum+=j-1;
			}
			//当前元素入栈 
			top++;
			stack[top]=j;
		}
		top=0;
		for(int j=a;j>=1;j--){			
			while(top!=0&&n[j]>n[stack[top]]){
				top--;
			}
			//找到递减栈里第一个比当前元素大的,为n[stack[top]
			//能看到俩人中间的人 
			if(top!=0){
				sum+=-j+stack[top] -1;
			}
			else{//没有更大的 
				sum+=a-j;
			}
			//当前元素入栈 
			top++;
			stack[top]=j;
			
		}
	printf("%lld\n",sum);
}
	return 0;
}