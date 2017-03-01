#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10000;
int Left[maxn];
int Right[maxn];

void link(int l,int r){
    Right[l]=r;
    Left[r]=l;
}

int main()
{
    int n,m,cnt=1;
    while(~scanf("%d %d",&n,&m)){
       Right[0]=1;Left[0]=n;
       for(int i=1;i<n;i++){
          Left[i]=i-1;
          Right[i]=i+1;
       }
       Left[n]=n-1;Right[n]=0;
       int inv=0;
       for(int i=0;i<m;i++){
           int op;
           scanf("%d",&op);
           if(op==4){
               inv=!inv;
               continue;
           }
           int x,y;scanf("%d %d",&x,&y);
           if(op!=3&&inv) op=3-op;
           if(op==1&&Left[y]==x) continue;
           if(op==2&&Right[y]==x) continue;
           int lx=Left[x],rx=Right[x],ly=Left[y],ry=Right[y];
           if(op==1){
              link(lx,rx);link(ly,x);link(x,y);
           }
           else if(op==2){
              link(lx,rx);link(y,x);link(x,ry);
           }
           else if(op==3){
              if(Right[x]==y){
                 link(lx,y);link(x,ry);link(y,x);
              }
              else if(Right[y]==x){
                 link(ly,x);link(y,rx);link(x,y);
              }
              else{
                link(lx,y);link(y,rx);link(ly,x);link(x,ry);
              }
           }
       }
       long long ans=0;
       int p=0;
       for(int i=1;i<=n;i++){
           p=Right[p];
           if(i%2) ans+=p;
       }
       if(inv&&n%2==0) ans=(long long)n*(n+1)/2-ans;
       printf("Case %d: %lld\n",cnt++,ans);
    }
}
