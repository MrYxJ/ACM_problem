#include<bits/stdc++.h>
using namespace std;
char s1[100+10],s2[100+10];
int dp[110][110],ans[110];

int main(){
    while(~scanf("%s %s",s1+1,s2+1)){
       memset(dp,0,sizeof(dp));
       int n=strlen(s2+1);
       for(int i=n;i>=1;i--){
          for(int j=i;j<=n;j++){
            dp[i][j]=dp[i+1][j]+1;
            for(int k=i+1;k<=j;k++){
                if(s2[i]==s2[k]) dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
            }
          }
       }
       for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
       }
       for(int i=1;i<=n;i++) ans[i]=dp[1][i];
       for(int i=1;i<=n;i++){
         if(s1[i]==s2[i]) ans[i]=ans[i-1];
         else{
            for(int j=1;j<i;j++){
                ans[i]=min(ans[i],ans[j]+dp[j+1][i]);
            }
         }
       }
       printf("%d\n",ans[n]);
    }
}
