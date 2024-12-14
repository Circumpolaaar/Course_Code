#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()  {   
	char a1[1000],b1[1000];        
	int a[1000]={0};
	int b[1000]={0};
	int c[1000]={0};

	int i=0,o,j, k,m,n;
	int p,q,flag=2,y=0,x=0;
	int e=0,f=0;
	gets(a1);gets(b1);
	for(i=0;i<strlen(a1);i++)
		a[i]=a1[i]-'0';
	for(j=0;j<strlen(b1);j++)
		b[j]=b1[j]-'0';
		
	for(m=0; a[m]==0; m++);
	for(n=0; b[n]==0; n++);
	//printf("i=%d j=%d m=%d n=%d",i,j,m,n);
//一样多 
	if(i-m==j-n){
		x=m;y=n;
		for(y;a[x]-b[y]==0&&y<j;y++){
			x++;
		}
		if(x==i)printf("0");
		else if(a[x]>b[y])flag=1;
		else if(a[x]<b[y])flag=0;
	}
	//a位数多 	
	if(i-m>j-n||flag==1){
		p=j-1;q=i-1;	

		//以有效数字duo的q为准 
		for(q;q>=0;q--){
			o=q;
			if(p>n-1){	
				if(a[q]-b[p]>=0){
				c[o]=a[q]-b[p];
				
				p--;
				}
				else{
				
				c[o]=a[q]-b[p]+10;
				a[q-1]=a[q-1]-1;
				p--;
				}
			}
			else if(p<=n-1){
				if(a[q]>=0){
					c[o]=a[q];
					p--;
				}
				else if(a[q]<0){
					c[o]=a[q]+10;
					a[q-1]=a[q-1]-1;
					p--;
				}
				
			}
	//		printf("o=%d %d\n",o,c[o] );
		}
		
		//处理0 
		
		for(e=0;c[e]==0;e++);
	//	printf("e=%d m=%d\n",e,m);	
		//if(e-n==1000){
		//	printf("0");
		//}
		//else{
			for(o=e;o<i;o++){
		
			printf("%d",c[o]);
		}
		//}
		
	}
	//b位数多 
	if(i-m<j-n||flag==0){
		p=j-1;q=i-1;	
	
		//以有效数字duo的p为准 
		for(p;p>=0;p--){
			o=p;
			if(q>m-1){	
				if(b[p]-a[q]>=0){
				c[o]=b[p]-a[q];
				
				q--;
				}
				else{
				
				c[o]=b[p]-a[q]+10;
				b[p-1]=b[p-1]-1;
				q--;
				}
			}
			else if(q<=m-1){
				if(b[p]>=0){
					c[o]=b[p];
					q--;
				}
				else if(b[p]<0){
					c[o]=b[p]+10;
					b[p-1]=b[p-1]-1;
					q--;
			}
			
		}}
		printf("-");
		
		//处理0 
		for(f=n;c[f]==0;f++);
		for(o=f;o<j;o++){
			//printf("o=%d,%d\n",o,c[o]);
			printf("%d",c[o]);
		}
		
		
		
		}
		
	

	
	
	return 0;}

