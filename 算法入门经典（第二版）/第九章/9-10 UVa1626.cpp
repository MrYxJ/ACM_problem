#include<bits/stdc++.h>
using namespace std;
const int N=100+10,inf=0x7fffffff;
int dp[N][N];
char s[N];
bool match(int i,int j){
   if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']')) return true;
   return false;
}

void print(int i,int j){
    if(i>j) return;
    if(i==j){
        if(s[i]=='('||s[i]==')') printf("()");
        else  printf("[]");
        return;
    }
    int ans=dp[i][j];
    if(match(i,j)&&ans==dp[i+1][j-1]){
        printf("%c",s[i]);print(i+1,j-1);printf("%c",s[j]);
        return;
    }
    for(int k=i;k<j;k++){
        if(dp[i][k]+dp[k+1][j]==ans){
           print(i,k);print(k+1,j);
           return;
        }
    }
}

int main(){
    int T;scanf("%d",&T);
    getchar();
    while(T--){
        gets(s);
        gets(s);
        int n=strlen(s);
        for(int i=0;i<n;i++){
           dp[i][i]=1;
           dp[i+1][i]=0;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j]=n;
                if(match(i,j)) dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                for(int k=i;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
        print(0,n-1);
        printf("\n");
        if(T) printf("\n");
    }
}
