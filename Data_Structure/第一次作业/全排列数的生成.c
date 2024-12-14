#include <stdio.h>
#include <string.h>
#include <ctype.h>
int a[1000],flag[1000];
int n;
void swap(int step);
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		a[i]=i+1;
	}
	swap(1);
	return 0;}
	
void swap(int step){
	int i,j;
	if(step>n){
		for(j=1;j<=n;j++){
			printf("%d ",a[j]);	
		}
		printf("\n");
	}
	else{
		for(i=1;i<=n;i++){
			if(flag[i]==0){
				flag[i]=1;
				a[step]=i;
				swap(step+1);
				flag[i]=0;
			}
		}
	}
}
	



