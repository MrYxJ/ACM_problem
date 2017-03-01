#include<bits/stdc++.h>
using namespace std;
char M[110][110];
int n,m,dir[8][2]={-1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1};
void dfs(int x,int y)
{
   M[x][y]='*';
   for(int i=0;i<8;i++){
      int nx=x+dir[i][0];
      int ny=y+dir[i][1];
      if(nx>=0&&ny>=0&&nx<n&&ny<m&&M[nx][ny]=='@') dfs(nx,ny);
   }
}

int main()
{
   while(~scanf("%d %d",&n,&m)){
      if(n==0&&m==0) break;
      int ans=0;
      for(int i=0;i<n;i++){
          scanf("%s",M[i]);
      }
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]=='@'){
                ans++;
                dfs(i,j);
            }
        }
      }
      printf("%d\n",ans);
   }
}
