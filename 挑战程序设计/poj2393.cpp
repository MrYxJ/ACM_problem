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
const int inf=0x7ffffff;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
using namespace std;
const int maxn=10100;
int main()
{
    /*
    #ifdef yxj
    freopen("C:\\Users\\MrYxJ\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\MrYxJ\\Desktop\\out.txt","w",stdout);
    #endif // yx
     int T=5;
     while(T--){
        int n=rand()%10000+1;
        int s=rand()%100+1;
        cout<<n<<" "<<s<<endl;
        for(int i=0;i<n;i++){
            int c=rand()%5000+1;
            int y=rand()%10000+1;
            cout<<c<<" "<<y<<endl;
        }
     }
    */
   int n,s;
   while(~scanf("%d%d",&n,&s)){
      int minc=inf;
      ll ans=0;
      for(int i=0;i<n;i++){
         int c,y;
         scanf("%d%d",&c,&y);
         minc=min(c,minc+s);
         ans+=minc*y;
      }
      printf("%lld\n",ans);
   }
}
