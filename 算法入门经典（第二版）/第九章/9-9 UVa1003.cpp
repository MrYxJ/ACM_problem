#include<bits/stdc++.h>
using namespace std;
const int N=55,inf=0x7fffffff;
int a[N],dp[55][55];

int main(){
   int l;
   while(scanf("%d",&l)&&l){
      int n;scanf("%d",&n); a[0]=0; a[n+1]=l;
      for(int i=1;i<=n;i++) scanf("%d",&a[i]);
      memset(dp,0,sizeof(dp));
      for(int i=0;i<=n;i++){
        for(int j=i+2;j<=n+1;j++){
          dp[i][j]=inf;
        }
      }
      for(int i=n-1;i>=0;i--){
        for(int j=i+2;j<=n+1;j++){
          for(int k=i+1;k<j;k++){
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[j]-a[i]);
          }
        }
      }
      printf("The minimum cutting is %d.\n",dp[0][n+1]);
   }
}
