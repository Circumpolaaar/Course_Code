#include<stdio.h>
#include<cstdio>

long long  x,y,a,b;
void exgcd(long long  a, long long  b)
{
    if(b==0)
    {
        x=1;
        y=0;
        return ;
    }
    exgcd(b,a%b);
    long long  t=x;
    x=y;
    y=t-a/b*y;
    return ;
}
int main()
{
    long long  a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        exgcd(a,b);
        printf("%lld\n",(x+b)%b);
    }
}