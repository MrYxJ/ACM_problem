/*

#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll dp[1010][6];
void solve(){
   memset(dp,0,sizeof(dp));
   for(int i=1;i<=1000;i++){
      dp[i][0]=1;
      dp[i][1]=(dp[i-1][0]+dp[i-1][1]*2)%mod;
      dp[i][2]=(dp[i-1][0]+dp[i-1][2])%mod;
      dp[i][3]=(dp[i-1][1]+dp[i-1][3]*2)%mod;
      dp[i][4]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][4]*2)%mod;
      dp[i][5]=(dp[i-1][3]+dp[i-1][4]+dp[i-1][5]*2)%mod;
   }
}

int main(){
   solve();
   int n;
   while(~scanf("%d",&n)){
      printf("%lld\n",dp[n][5]);
   }
}

#include<bits/stdc++.h>
using namespace std;
struct node{
  int x,y;
};
char M[70][70];
int sx,sy,ex,ey,n,m,v[70][70],dir[4][2]={-1,0,0,1,0,-1,1,0},ok;
queue<struct node>q;
void  bfs(int x,int y,int va){
    while(!q.empty()) q.pop();
    q.push(node{x,y});
    v[x][y]=va;
    while(!q.empty()){
       node now=q.front();q.pop();
       if(M[now.x][now.y]=='+'||M[now.x][now.y]=='T'||M[now.x][now.y]=='S'){
            if(M[now.x][now.y]=='T') ok=1;
            int nx,ny;
            for(int i=0;i<4;i++){
            nx=now.x+dir[i][0];
            ny=now.y+dir[i][1];
             if(nx>0&&ny>0&&nx<=n&&ny<=m&&v[nx][ny]!=va&&M[nx][ny]!='#'){
                v[nx][ny]=va;
                q.push(node{nx,ny});
             }
            }
        }
        else if(M[now.x][now.y]=='-'){
            int nx,ny;
            for(int i=1;i<3;i++){
               nx=now.x+dir[i][0];
               ny=now.y+dir[i][1];
               if(nx>0&&ny>0&&nx<=n&&ny<=m&&v[nx][ny]!=va&&M[nx][ny]!='#'){
                   v[nx][ny]=va;
                   q.push(node{nx,ny});
               }
            }
        }
        else if(M[now.x][now.y]=='|'){
            int nx,ny;
            for(int i=0;i<4;i+=3){
              nx=now.x+dir[i][0];
              ny=now.y+dir[i][1];
              if(nx>0&&ny>0&&nx<=n&&ny<=m&&v[nx][ny]!=va&&M[nx][ny]!='#'){
                v[nx][ny]=va;
                q.push(node{nx,ny});
              }
            }
        }
        else if(M[now.x][now.y]=='.'){
             int nx=now.x+1,ny=now.y;
             if(nx>0&&ny>0&&nx<=n&&ny<=m&&v[nx][ny]!=va&&M[nx][ny]!='#'){
                v[nx][ny]=va;
                q.push(node{nx,ny});
             }
        }
    }
}

void bfs2(int x,int y,int va){
  while(!q.empty()) q.pop();
    q.push(node{x,y});
    v[x][y]=va;
    while(!q.empty()){
       node now=q.front();q.pop();
       for(int i=0;i<4;i++){
          int nx=now.x+dir[i][0];
          int ny=now.y+dir[i][1];
          if((nx>0&&ny>0&&nx<=n&&ny<=m&&v[nx][ny]!=va)&&(M[nx][ny]=='+'||M[nx][ny]=='S'||M[nx][ny]=='T'||(M[nx][ny]=='-'&&(i==1||i==2)||(M[nx][ny]=='|'&&(i==0||i==3))||(M[nx][ny]=='.'&&i==0)))){
                v[nx][ny]=va;
                q.push(node{nx,ny});
          }
       }
    }
}

int main(){
   while(~scanf("%d%d",&n,&m)){
      for(int i=1;i<=n;i++){
         scanf("%s",M[i]+1);
         for(int j=1;j<=m;j++){
            if(M[i][j]=='S') sx=i,sy=j;
            else if(M[i][j]=='T') ex=i,ey=j;
         }
      }
      ok=0;
      memset(v,0,sizeof(v));
      bfs(sx,sy,1);
      if(!ok) printf("I'm stuck!\n");
      else{
         int ans=0;
         bfs2(ex,ey,2);
         for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(v[i][j]==1) ans++;
            }
         }
         printf("%d\n",ans);
      }
   }
}
*/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x7ffffff;
int s[1010][1010],dp[1010];
char str[1010];
int main(){
     int t;scanf("%d",&t);
     while(t--){
        scanf("%s",str+1);
        memset(s,0,sizeof(s));
        int n=strlen(str+1);
        for(int i=1;i<=n;i++) s[i][i]=1;
        for(int i=1;i<=n;i++){
           int j=1;
           while(i-j>=0&&i+j<=n){
              if(str[i-j+1]==str[i+j]) { s[i-j+1][i+j]=1;j++;}
              else break;
           }
           j=1;
           while(i-j>=1&&i+j<=n){
             if(str[i+j]==str[i-j]) { s[i-j][i+j]=1;j++;}
             else break;
           }
        }
        for(int i=1;i<=n;i++) dp[i]=i;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(s[j][i]) dp[i]=min(dp[i],dp[j-1]+1);
            }
        }
        printf("%d\n",dp[n]);
     }
}
