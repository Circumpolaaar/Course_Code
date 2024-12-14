#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
int a[100010];
int dp[100010]; 
int leaf[100010];   
int m,n,l,r;
#define MOD 998244353
int main() {

    scanf("%d%d",&n, &m);
    scanf("%d%d",&l, &r);
    for(int i=0;i<n+2;i++){
        dp[i]=0;
        leaf[i]=0;
    }

    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
        leaf[a[i]]=1;
    }
    
    dp[0]=1;
    leaf[0]=1;
    leaf[n]=1;
    int sum=0;
    int left=0,right=0;
    for(int i=1;i<=n;i++){
        if(leaf[i]==0) continue;

        while (left < i - r) {
            sum = (sum - dp[left] + MOD) % MOD;
            left++;
        }
        while (right <= i - l) {
            sum = (sum + dp[right]) % MOD;
            right++;
        }

        dp[i] = sum % MOD;
       // printf("dp=%d\n",dp[i]);
    }
        /*
        int j=i-r;
        if(j<0) j=0;
        for(j;j<=i-l;j++){
            if(leaf[j]==1){
                dp[i]=dp[i]+(dp[j]%998244353);
                dp[i]=dp[i]%998244353;
            }
        }
        */
    


    printf("%d",dp[n]);
    return 0;
}
