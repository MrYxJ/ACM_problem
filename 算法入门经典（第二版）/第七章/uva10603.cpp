#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
int ans[maxn],vis[maxn][maxn],cap[3],d;
struct node
{
    int v[3],dist;
    bool operator < (const node&u)const{
       return u.dist<dist;
    }
};

void update(const node &u)
{
    for(int i=0;i<3;i++){
        int d=u.v[i];
        if(ans[d]<0||ans[d]>u.dist) ans[d]=u.dist;
    }
}

void solve()
{
    memset(vis,0,sizeof(vis));
    memset(ans,-1,sizeof(ans));
    node now;
    now.v[0]=0;now.v[1]=0;now.v[2]=cap[2];now.dist=0;
    vis[0][0]=1;
    priority_queue<node>pque;
    pque.push(now);
    while(!pque.empty()){
        node u=pque.top();pque.pop();
        update(u);
        if(ans[d]>=0) break;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i!=j){
                    if(u.v[i]==0||u.v[j]==cap[j]) continue;
                    int amount=min(cap[j],u.v[i]+u.v[j])-u.v[j];
                    node u2;
                    memcpy(&u2,&u,sizeof(u));
                    u2.dist=u.dist+amount;
                    u2.v[i]-=amount;
                    u2.v[j]+=amount;
                    if(!vis[u2.v[0]][u2.v[1]]){
                        vis[u2.v[0]][u2.v[1]]=1;
                        pque.push(u2);
                    }
                }
            }
        }
    }
    while(d>=0){
        if(ans[d]>=0){
            printf("%d %d\n",ans[d],d);
            return;
        }
        d--;
    }
}

int main()
{
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d %d %d %d",&cap[0],&cap[1],&cap[2],&d);
        solve();
    }
}
