#include<bits/stdc++.h>
using namespace std;
const int N=100,inf=0x7ffffff;
int dp[N*180+678+2],a[N+10];

int main(){
   int T;scanf("%d",&T);
   int cas=1;
   while(T--){
      int n,t;scanf("%d%d",&n,&t);
      for(int i=0;i<n;i++) scanf("%d",&a[i]);
      for(int i=0;i<=t;i++) dp[i]=-inf;
      dp[0]=0;
      for(int i=0;i<n;i++){
        for(int j=t;j>=a[i];j--){
            dp[j]=max(dp[j],dp[j-a[i]]+1);
        }
      }
      int ant=0,ans=0;
      for(int i=t-1;i>=1;i--){
        if(dp[i]>ant){
            ant=dp[i];
            ans=i;
        }
      }
      printf("Case %d: %d %d\n",cas++,ant+1,ans+678);
   }
}
