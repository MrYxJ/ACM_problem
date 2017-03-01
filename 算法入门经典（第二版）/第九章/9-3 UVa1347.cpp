#include<bits/stdc++.h>
using namespace std;
const int N=1010;
const double inf=0x7ffffff;
double dist[N][N],dp[N][N],x[N],y[N];
int main(){
   int n;
   while(~scanf("%d",&n)){
      for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
         }
      }
      for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=inf;
        }
      }
      for(int i=1;i<n;i++) dp[n-1][i]=dist[n-1][n]+dist[i][n];
      for(int i=n-2;i>=1;i--){
        for(int j=1;j<i;j++){
           dp[i][j]=min(dp[i+1][j]+dist[i+1][i],dp[i+1][i]+dist[i+1][j]);
        }
      }
      printf("%.2f\n",dp[2][1]+dist[1][2]);
   }
}
