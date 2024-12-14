#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void bubbleSort(int a[][5], int n);
int main(){
	int n;
	int i,j;
	int a[110][5];
	int k;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		a[i][4]=1;
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	bubbleSort(a,n);
	for(i=0;i<n;i++){
		//printf("sort:%d %d\n",i,a[i][4]);
		for(j=0;j<i;j++){
			
			if(a[j][0]==a[i][2]&&a[j][1]==a[i][3]){
				a[i][4]=a[j][4]+1;
				//a[i][4]=a[j][4];
			
	}	
		//printf("i:%dj:%d %d %d\n",i,j,a[i][4],a[j][4]);
				
	}	
		
	}
	for(i=0;i<n;i++){
		if (a[i][4] >= a[j][4]){
		j = i;	
	//	printf("%d %d\n",j,a[j][4]);
		}
		
	}
	printf("%d %d %d",a[j][4],a[j][0],a[j][1]);
	return 0;
} 
void bubbleSort(int a[][5], int n)
{//½µÐò 
	int i, j;
	int temp;
	for (i = 0; i < n - 1; i++) {
		int flag = 1;
		for (j = 0; j < n - 1 - i; j++)
			if (a[j][0] < a[j + 1][0])
			{
				temp = a[j][0];
				a[j][0] = a[j + 1][0];
				a[j + 1][0] = temp;
				
				temp = a[j][1];
				a[j][1] = a[j + 1][1];
				a[j + 1][1] = temp;
				
				temp = a[j][2];
				a[j][2] = a[j + 1][2];
				a[j + 1][2] = temp;
				
				temp = a[j][3];
				a[j][3] = a[j + 1][3];
				a[j + 1][3] = temp;
				flag = 0;
			}
		if(flag == 1)
			break;
	}
}

