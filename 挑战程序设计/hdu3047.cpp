#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
int f[maxn],dist[maxn],n,m,ans;
void init()
{
    ans=0;
    memset(dist,0,sizeof(dist));
    for(int i=1;i<=maxn;i++)f[i]=i;
}

int Find(int x)
{
    int fx=f[x];
    if(x!=fx){
        f[x]=Find(f[x]);
        dist[x]+=dist[fx];
    }
    return f[x];
}

void Merge(int x,int y,int s)
{
    int fx=Find(x),fy=Find(y);
    if(fx!=fy){
        dist[fy]=dist[x]-dist[y]+s;
        f[fy]=fx;
    }
    else{
    if(dist[y]-dist[x]!=s)
        ans++;
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m)){
        init();
        for(int i=0;i<m;i++){
            int a,b,s;
            scanf("%d%d%d",&a,&b,&s);
            Merge(a,b,s);
        }
        printf("%d\n",ans);
    }
}
