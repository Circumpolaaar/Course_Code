#include <stdio.h>
int p[10010];//原始价格 
int r[10010];//切割方案 
int s[10010];//记录长度 
long long int dp[10010];
long long int cut(int n);
void record(int n);
void print(int n);
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0;i<=n+5;i++){
    	s[i]=0;
    	r[i]=0;
    	dp[i]=-1;
	}
    for(int i=1;i<=n;i++){
    	scanf("%d",&p[i]);
	}
	//总价格  
	record(n);
    printf("%lld\n",dp[n]);
   
    //段数 
    printf("%d\n", r[0]);
    //方案 
    for (int i=r[0];i>=1;i--) {
        printf("%d ",r[i]);
    }
    printf("\n");
    return 0;
}
long long int cut(int n){
	if(n==0){
		return 0;
	}
	if(dp[n]>=0){
		return dp[n];
	}
	long long int q=-1;
	for(int i=1;i<=n;i++){
        if (q<p[i]+cut(n-i)) {
            q=p[i]+cut(n-i);
            s[n]=i; // 记录最优切割长度
        }
	}
	dp[n]=q;
	return q;
}
//回溯
void print(int n) {
    if (n==0) return;
    r[++r[0]]=s[n];
    print(n-s[n]);
}


void record(int n) {
    r[0]=0;
    cut(n);
    print(n);
}