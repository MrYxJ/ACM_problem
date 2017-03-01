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
int f[100010],n,m;
void init()
{
    for(int i=1;i<=n;i++) f[i]=i;
}

int Find(int x)
{
   if(x!=f[x]) return Find(f[x]);
   else return x;
}

int main()
{
   while(scanf("%d%d",&n,&m)&&n&&m){
       init();
       for(int i=2;i<=n;i++){
          scanf("%d",&f[i]);
       }
       ll ans=0;
       for(int i=1;i<=m;i++){
          char c;int a;
          scanf("\n%c%d",&c,&a);
          getchar();
          if(c=='Q'){
            ans+=Find(a);
          }
          else if(c=='M'){
              f[a]=a;
          }
       }
       printf("%lld\n",ans);
   }
}
