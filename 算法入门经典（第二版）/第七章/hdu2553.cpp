#include<bits/stdc++.h>
using namespace std;
int v[15][15],ans,n,dp[11];
bool check(int x,int  y)
{
   for(int i=1;i<=n;i++) if(v[i][y]||v[x][i]) return false;
   for(int i=1;x-i>=1&&y-i>=1;i++) if(v[x-i][y-i]) return false;
   int m=x+y;
   for(int i=1;x-i>=1&&y+i<=n;i++) if(v[x-i][y+i]) return false;
   return true;
}

void dfs(int cur)
{
    if(cur==n+1){
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(check(cur,i)){
            v[cur][i]=1;
            dfs(cur+1);
            v[cur][i]=0;
        }
    }
}

int main()
{
    while(scanf("%d",&n)&&n){
        if(dp[n]>0){
            printf("%d\n",dp[n]);
            continue;
        }
        memset(v,0,sizeof(v));
        ans=0;
        dfs(1);
        dp[n]=ans;
        printf("%d\n",ans);
    }
}
