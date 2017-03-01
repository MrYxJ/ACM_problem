#include<bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;
int dp[15][110],a[15][110],pah[15][110];
int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            pah[i][j]=0;
        }
      }
      for(int i=1;i<=n;i++) dp[i][m]=a[i][m];
      for(int j=m-1;j>=1;j--){
        for(int i=1;i<=n;i++){
            dp[i][j]=dp[i][j+1]+a[i][j];
            pah[i][j]=i;
            if(i>1&&dp[i-1][j+1]+a[i][j]<=dp[i][j]){
                dp[i][j]=dp[i-1][j+1]+a[i][j];
                pah[i][j]=i-1;
            }
            if(i==n&&dp[1][j+1]+a[i][j]<=dp[i][j]){
                dp[i][j]=dp[1][j+1]+a[i][j];
                pah[i][j]=1;
            }
            if(i<n&&dp[i+1][j+1]+a[i][j]<dp[i][j]){
                dp[i][j]=dp[i+1][j+1]+a[i][j];
                pah[i][j]=i+1;
            }
            if(i==1&&dp[n][j+1]+a[i][j]<dp[i][j]){
                dp[i][j]=dp[n][j+1]+a[i][j];
                pah[i][j]=n;
            }

        }
      }
      int ans=inf;
      for(int i=1;i<=n;i++) ans=min(ans,dp[i][1]);
      int p;
      for(int i=1;i<=n;i++) if(dp[i][1]==ans) {p=i;break;}
      for(int i=1;i<=m;i++){
        if(i<m) printf("%d ",p);
        else printf("%d\n%d\n",p,ans);
        p=pah[p][i];
      }
    }
}
