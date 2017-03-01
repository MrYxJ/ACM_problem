#include<bits/stdc++.h>
using namespace std;
const int N=5000+5,inf=0x7fffffff;
int dp[N][N],c[N][N],sp[30],ep[30],sq[30],eq[30];
char p[N],q[N];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",p+1);
        scanf("%s",q+1);
        int n=strlen(p+1),m=strlen(q+1);
        for(int i=1;i<=n;i++) p[i]-='A';
        for(int i=1;i<=m;i++) q[i]-='A';
        for(int i=0;i<26;i++){
            sp[i]=sq[i]=inf;
            ep[i]=eq[i]=0;
        }
        for(int i=1;i<=n;i++){
           sp[p[i]]=min(sp[p[i]],i);
           ep[p[i]]=i;
        }
        for(int i=1;i<=m;i++){
           sq[q[i]]=min(sq[q[i]],i);
           eq[q[i]]=i;
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                c[i][j]=0;
            }
        }
        for(int i=0;i<=n;i++){//求c[i][j],表示p从0到i,q从0到j目前为止有多少个已经开始但未结束的的字母。
          for(int j=0;j<=m;j++){
             if(i){
                c[i][j]=c[i-1][j];
                if(sp[p[i]]==i&&sq[p[i]]>j) c[i][j]++;
                if(ep[p[i]]==i&&j>=eq[p[i]]) c[i][j]--;
             }
             if(j){
                c[i][j]=c[i][j-1];
                if(sq[q[j]]==j&&sp[q[j]]>i) c[i][j]++;
                if(eq[q[j]]==j&&i>=ep[q[j]]) c[i][j]--;
             }
          }
        }
        dp[n][m]=0;
        for(int i=n-1;i>=0;i--) dp[i][m]=dp[i+1][m]+c[i][m];
        for(int i=m-1;i>=0;i--) dp[n][i]=dp[n][i+1]+c[n][i];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+c[i][j];
            }
        }
        printf("%d\n",dp[0][0]);
    }
    return 0;
}


