/*
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <ctime>
#include <assert.h>

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define eps 1e-8
#define M_PI 3.141592653589793

typedef long long ll;
const ll mod=1000000007;
const int inf=0x7fffffff;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
using namespace std;
int M[30][30],v[30],n,k,a[30],ans;
void check(int x)
{
    for(int i=1;i<=n;i++){
        if(M[x][i]&&!v[i]){
            v[i]=1;
            check(i);
        }
    }
    return;
}

void dfs(int cur)
{
   if(cur>n) return;
   if(a[cur-1]==k){
     ans++;
     for(int i=0;i<cur-1;i++) printf("%d ",a[i]);
     printf("%d\n",a[cur-1]);
     return;
   }
   for(int i=1;i<=n;i++){
      if(!v[i]&&M[a[cur-1]][i]==1){
         v[i]=1;
         a[cur]=i;
         dfs(cur+1);
         v[i]=0;
      }
   }
}
int main()
{
   int t=0;
   while(~scanf("%d",&k)){
      ans=0;
      printf("CASE %d:\n",++t);
      n=0;
      memset(M,0,sizeof(M));
      memset(v,0,sizeof(v));

      while(1){
        int a,b;scanf("%d%d",&a,&b);
        if(a==0&&b==0) break;
        n=max(n,max(a,b));
        M[a][b]=M[b][a]=1;
      }
      check(1);
      if(v[k]==0){
          printf("There are 0 routes from the firestation to streetcorner %d.\n",k);
          continue;
      }
      memset(v,0,sizeof(v));
      v[1]=1;
      a[0]=1;
      dfs(1);
      printf("There are %d routes from the firestation to streetcorner %d.\n",ans,k);
   }
}
*/
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <ctime>
#include <assert.h>

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define eps 1e-8
#define M_PI 3.141592653589793

typedef long long ll;
const ll mod=1000000007;
const int inf=0x7fffffff;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
using namespace std;
int M[30][30],v[30],dist[30][30],n,k,a[30],ans;
void dfs(int cur)
{
   if(cur>n) return;
   if(a[cur-1]==k){
     ans++;
     for(int i=0;i<cur-1;i++) printf("%d ",a[i]);
     printf("%d\n",a[cur-1]);
     return;
   }
   for(int i=1;i<=n;i++){
      if(!v[i]&&M[a[cur-1]][i]==1&&dist[k][i]!=0x7ffffff){
         v[i]=1;
         a[cur]=i;
         dfs(cur+1);
         v[i]=0;
      }
   }
}

int main()
{
   int t=0;
   while(~scanf("%d",&k)){
      ans=0;
      printf("CASE %d:\n",++t);
      n=0;
      memset(M,0,sizeof(M));
      memset(v,0,sizeof(v));
      for(int i=1;i<=21;i++){
        for(int j=1;j<=21;j++){
            dist[i][j]=0x7ffffff;
        }
      }
      while(1){
        int a,b;scanf("%d%d",&a,&b);
        if(a==0&&b==0) break;
        n=max(n,max(a,b));
        M[a][b]=M[b][a]=dist[a][b]=dist[b][a]=1;
      }
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int l=1;l<=n;l++){
                dist[i][j]=min(dist[i][l]+dist[l][j],dist[i][j]);
            }
        }
      }
      v[1]=1;
      a[0]=1;
      dfs(1);
      printf("There are %d routes from the firestation to streetcorner %d.\n",ans,k);
   }
}
