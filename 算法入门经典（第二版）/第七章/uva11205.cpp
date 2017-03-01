/*
#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[110][20];
map<int,int>st;
void dfs(int cur,int *vis)
{
   if(cur==m){
    int t=0;
    st.clear();
    for(int i=0;i<n;i++){
     int num=0,p=1;
     for(int j=0;j<m;j++){
        if(vis[j]) { t++;num+=a[i][j]*p;}
        p*=2;
     }
     if(!st[num]) st[num]=1;
     else return;
    }
    ans=min(ans,t/n);
    return;
   }
   vis[cur]=1;
   dfs(cur+1,vis);
   vis[cur]=0;
   dfs(cur+1,vis);
}

int main()
{
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d %d",&m,&n);
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
             scanf("%d",&a[i][j]);
           }
        }
        int vis[20];
        ans=m;
        dfs(0,vis);
        printf("%d\n",ans);
    }
}
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{

}
