#include<bits/stdc++.h>
using namespace std;
const int inf=0x7ffffff;
int dp[210][60],has_train[210][60][2],t[60];

int main(){
     int n,T,cnt=1;
     while(scanf("%d",&n)&&n){
        scanf("%d",&T);
        for(int i=1;i<n;i++) scanf("%d",&t[i]);
        int M1;scanf("%d",&M1);
        memset(has_train,0,sizeof(has_train));
        for(int i=1;i<=M1;i++){
            int s;scanf("%d",&s);
            for(int j=1;j<n;j++){
               has_train[s][j][0]=1;
               s+=t[j];
            }
            has_train[s][n][0]=1;
        }
        int M2;scanf("%d",&M2);
        for(int i=1;i<=M2;i++){
            int s;scanf("%d",&s);
            for(int j=n;j>1;j--){
                has_train[s][j][1]=1;
                s+=t[j-1];
            }
            has_train[s][1][1]=1;
        }
        for(int i=0;i<=T;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=inf;
            }
        }
        dp[T][n]=0;
        for(int i=T-1;i>=0;i--){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i+1][j]+1;
                if(j<n&&has_train[i][j][0]&&i+t[j]<=T) dp[i][j]=min(dp[i+t[j]][j+1],dp[i][j]);
                if(j>1&&has_train[i][j][1]&&i+t[j-1]<=T) dp[i][j]=min(dp[i+t[j-1]][j-1],dp[i][j]);
            }
        }
        printf("Case Number %d: ",cnt++);
        if(dp[0][1]>=inf) printf("impossible\n");
        else printf("%d\n",dp[0][1]);
     }
}
