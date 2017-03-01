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
struct node
{
    int x,y;
}a[25000+10];
bool cmp(node a,node b)
{
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}

int main()
{
  int n,m;
  while(~scanf("%d%d",&n,&m)){
    int Max=0;
    for(int i=0;i<n;i++) { scanf("%d%d",&a[i].x,&a[i].y); Max=max(Max,a[i].y);}
    sort(a,a+n,cmp);
    if(a[0].x > 1){
          printf("-1\n");
          continue;
    }
    int cur=0,ans=1;
    for(int i=0;i<n;){
        int temp=0;
        for(int j=i+1;j<n;j++){
            if(a[j].x>a[cur].y+1) break;
            if(a[j].y>a[cur].y){
                if(a[j].y>a[temp].y){
                    temp=j;
                }
            }
        }
        if(temp==0){
            i++;
        }
        else{
            cur=temp;
            ans++;
            i=cur;
        }
    }
    if(a[cur].y==m) printf("%d\n",ans);
    else printf("-1\n");
  }
}
