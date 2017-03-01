#include<bits/stdc++.h>
using namespace std;
int dp[1010],s[1010];
const int inf=0x7fffff;

struct node{
   int v,k,c,l;
}a[1010];
bool cmp(node a,node b){
   return a.v<b.v;
}

int main(){
    int n;
    while(scanf("%d",&n)&&n){
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++){
            scanf("%d%d%d%d",&a[i].v,&a[i].k,&a[i].c,&a[i].l);
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++) s[i]=(s[i-1]+a[i].l);
        for(int i=1;i<=n;i++) dp[i]=inf;
        dp[0]=0;
        for(int i=1;i<=n;i++){
          for(int j=0;j<i;j++){
            dp[i]=min(dp[j]+(s[i]-s[j])*a[i].c+a[i].k,dp[i]);
          }
        }
        printf("%d\n",dp[n]);
    }
}
