#include<cstdio>
#include<algorithm>
typedef long long ll;
ll n;
int ok;
/*
void dfs(long long i,int step)
{
    if(flag) return;
    if(step>=DEP) return;//让第一个方向搜不到就像第二个方向收
    if(i%n==0)
    {
        printf("%lld\n",i);
        flag=true;
        return;
    }
    dfs(i*10,step+1);
    dfs(i*10+1,step+1);
}
*/
void dfs(int cur,ll num)
{
    if(ok) return;
    if(num%n==0&&num>0){
       ok=1;
       printf("%lld\n",num);
       return;
    }
    if(cur==19) return;
    dfs(cur+1,num*10+1);
    dfs(cur+1,num*10);
}

int main()
{
    while(~scanf("%lld",&n)&&n)
    {
        ok=0;
        dfs(0,1);
    }
}

/*
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    while(~scanf("%lld",&n)){
        queue<ll>q;
        while(!q.empty()) q.pop();
        q.push(1);
        while(!q.empty()){
            ll x=q.front();q.pop();
            if(x%n==0){
                printf("%lld\n",x);
                break;
            }
            q.push(x*10+1);
            q.push(x*10);
        }
    }
}
*/
