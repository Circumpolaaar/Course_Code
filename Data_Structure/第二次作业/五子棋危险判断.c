#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int a[100][100],flag[1000];
	int n;
	int i,j;
	//初始化 
	for(i=0;i<30;i++){
		for(j=0;j<30;j++){
			a[i][j]=3;
		}
	}
	//读入 
	for(i=1;i<20;i++){
		for(j=1;j<20;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	for(i=0;i<19;i++){
		for(j=0;j<19;j++){
			//横 
			if(a[i][j]==1&&a[i][j+1]==1&&a[i][j+2]==1&&a[i][j+3]==1){
				if(a[i][j-1]==0||a[i][j+4]==0){
					printf("1:%d,%d\n",i,j);
					n=1;
				}
			}
			else if(a[i][j]==2&&a[i][j+1]==2&&a[i][j+2]==2&&a[i][j+3]==2){
				if(a[i][j-1]==0||a[i][j+4]==0){
					printf("2:%d,%d\n",i,j);
					n=1;
				}
			}
			//竖
			else if(a[i][j]==2&&a[i+1][j]==2&&a[i+2][j]==2&&a[i+3][j]==2){
				if(a[i-1][j]==0||a[i+4][j]==0){
					printf("2:%d,%d\n",i,j);
					n=1;
				}
			}
			else if(a[i][j]==1&&a[i+1][j]==1&&a[i+2][j]==1&&a[i+3][j]==1){
				if(a[i-1][j]==0||a[i+4][j]==0){
					printf("1:%d,%d\n",i,j);
					n=1;
				}
			}
			//西北-东南 
			
			else if(a[i][j]==1&&a[i+1][j+1]==1&&a[i+2][j+2]==1&&a[i+3][j+3]==1){
				if(a[i-1][j-1]==0||a[i+4][j+4]==0){
					printf("1:%d,%d\n",i,j);
					n=1;
				}
			}
			else if(a[i][j]==2&&a[i+1][j+1]==2&&a[i+2][j+2]==2&&a[i+3][j+3]==2){
				if(a[i-1][j-1]==0||a[i+4][j+4]==0){
					printf("2:%d,%d\n",i,j);
					n=1;
				}
			}
			//东北-西南
			else if(i>3&&a[i][j]==1&&a[i+1][j-1]==1&&a[i+2][j-2]==1&&a[i+3][j-3]==1){
				if(a[i-1][j+1]==0||a[i+4][j-4]==0){
					printf("1:%d,%d\n",i,j);
					n=1;
				}
			} 
			else if(i>3&&a[i][j]==2&&a[i+1][j-1]==2&&a[i+2][j-2]==2&&a[i+3][j-3]==2){
				if(a[i-1][j+1]==0||a[i+4][j-4]==0){
					printf("2:%d,%d\n",i,j);
					n=1;
				}
			} 
			
		}
	}
	if(n!=1)
	printf("No\n");


	return 0;}
	


