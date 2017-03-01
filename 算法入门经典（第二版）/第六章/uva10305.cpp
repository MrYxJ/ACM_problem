#include<bits/stdc++.h>
using namespace std;
vector<int>E[110];
vector<int>ans;
int num[110],vis[110];
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m)){
       if(n==0&&m==0) break;
       for(int i=1;i<=n;i++) E[i].clear();
       ans.clear();
       memset(num,0,sizeof(num));
       memset(vis,0,sizeof(vis));
       for(int i=0;i<m;i++){
           int a,b;scanf("%d %d",&a,&b);
           E[a].push_back(b);
           num[b]++;
       }
       int t=n;
       while(t--){
         for(int i=1;i<=n;i++){
           if(num[i]==0&&vis[i]==0){
              ans.push_back(i);
              vis[i]=1;
              for(int j=0;j<E[i].size();j++){
                 if(vis[E[i][j]]==0) num[E[i][j]]--;
              }
           }
        }
       }
       for(int i=0;i<ans.size()-1;i++) printf("%d ",ans[i]);
       printf("%d\n",ans[ans.size()-1]);
    }
}
