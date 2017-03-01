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
const int maxn=2500+10;
pair<int,int>cow[maxn];
pair<int,int>bottle[maxn];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        priority_queue<int, vector<int>,greater<int> >pque;
        for(int i=0;i<n;i++) scanf("%d%d",&cow[i].first,&cow[i].second);
        for(int i=0;i<m;i++) scanf("%d%d",&bottle[i].first,&bottle[i].second);
        sort(cow,cow+n);
        sort(bottle,bottle+m);
        int cur=0,ans=0;
        for(int i=0;i<m;i++){
            while(cur<n&&cow[cur].first<=bottle[i].first){
                pque.push(cow[cur].second);
                cur++;
            }
            while(!pque.empty()&&bottle[i].second){
                int Min=pque.top();pque.pop();
                if(Min>=bottle[i].first){
                    ans++;
                    bottle[i].second--;
                }
            }
        }
        printf("%d\n",ans);
    }
}
