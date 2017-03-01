#include<bits/stdc++.h>
using namespace std;
char res[]={'A','D','J','K','S','W'};
char str[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
int s[16][4]=
{
    {0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},
    {0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},
    {1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},
    {1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}
};
int num[6];
int M[250][250],n,m,cnt;
bool in_M(int x,int y)
{
    return (x>=0&&x<=n+1&&y>=0&&y<=m+1);
}

void dfs(int x,int y)
{
   if(!in_M(x,y)||M[x][y]!=0) return;
   M[x][y]=-1;
   dfs(x+1,y);dfs(x-1,y);dfs(x,y+1);dfs(x,y-1);
}

void dfs2(int x,int y)
{
    if(M[x][y]==-1||!in_M(x,y)) return;
    if(M[x][y]==0){
        cnt++;
        dfs(x,y);
        return;
    }
    M[x][y]=-1;
    dfs2(x+1,y);dfs2(x-1,y);dfs2(x,y+1);dfs2(x,y-1);
}

int main()
{
   int t=0;
   while(scanf("%d %d",&n,&m)&&n&&m){
      memset(M,0,sizeof(M));
      for(int i=1;i<=n;i++){
        char tem[80]; scanf("%s",tem+1);
        int p=1;
        for(int j=1;j<=m;j++){
           for(int k=0;k<16;k++){
             if(tem[j]==str[k]){
                for(int l=0;l<4;l++){
                   M[i][p++]=s[k][l];
                }
                break;
             }
           }
        }
      }
      memset(num,0,sizeof(num));
      m*=4;
      dfs(0,0);
      for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(M[i][j]==1){
                cnt=0;
                dfs2(i,j);
                if(cnt==0) num[5]++;
                else if(cnt==1) num[0]++;
                else if(cnt==2) num[3]++;
                else if(cnt==3) num[2]++;
                else if(cnt==4) num[4]++;
                else if(cnt==5) num[1]++;
             }
        }
      }
     printf("Case %d: ",++t);
     for(int i=0;i<6;i++){
        for(int j=0;j<num[i];j++){
            printf("%c",res[i]);
        }
    }
    printf("\n");
   }
}
