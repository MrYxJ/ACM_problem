/*
#include<bits/stdc++.h>
using namespace std;
const int maxn=103000+10;
typedef long long ll;
set<ll>ban;
int maxed;
ll v[maxn],ans[maxn];
ll get_first(ll a,ll b){
   return b/a+1;
}

ll gcd(ll a,ll b){
   return b==0 ? a : gcd(b,a%b);
}

bool better(int d){
  for(int i=d;i>=0;i--){
    if(ans[i]!=v[i]){
       return ans[i]==-1||v[i]<ans[i];
    }
  }
  return false;
}

bool dfs(int cur,ll from,ll a,ll b){
   if(cur==maxed){
       if(b%a||ban.count(b/a)) return false;
       v[cur]=b/a;
       if(better(cur)) memcpy(ans,v,sizeof(ll)*(cur+1));
       return true;
   }
   bool ok=false;
   from=max(from,get_first(a,b));
   for(int i=from;;i++){
      if(ban.count(i)) continue;
      if(b*(maxed+1-cur)<=i*a) break;
      v[cur]=i;
      ll b2=b*i;
      ll a2=a*i-b;
      ll g=gcd(a2,b2);
      if(dfs(cur+1,i+1,a2/g,b2/g)) ok=true;
   }
   return ok;
}

int main()
{
    int T;scanf("%d",&T);
    int t=0;
    while(T--){
       ban.clear();
       memset(ans,-1,sizeof(ans));
       int k;
       ll a,b;
       scanf("%lld %lld %d",&a,&b,&k);
       while(k--){
          ll x;scanf("%lld",&x);ban.insert(x);
       }
       for(maxed=1;;maxed++){
          memset(ans,-1,sizeof(ans));
          if(dfs(0,get_first(a,b),a,b)) break;
       }
       printf("Case %d: %lld/%lld=1/%lld",++t,a,b,ans[0]);
       for(int i=1;i<=maxed;i++) printf("+1/%lld",ans[i]);
       printf("\n");
    }
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=103000+10;
typedef long long ll;
set<ll>ban;
int maxed;
bool ok;
ll v[maxn],ans[maxn];
ll get_first(ll a,ll b){
   return b/a+1;
}

ll gcd(ll a,ll b){
   return b==0 ? a : gcd(b,a%b);
}

bool better(int d){
  for(int i=d;i>=0;i--){
    if(ans[i]!=v[i]){
       return ans[i]==-1||v[i]<ans[i];
    }
  }
  return false;
}

void dfs(int cur,ll from,ll a,ll b)
{
    if(cur==maxed){
        if(b%a||ban.count(b/a)) return;
        v[cur]=b/a;
        if(better(cur)) memcpy(ans,v,sizeof(ll)*(cur+1));
        ok=true;
        return;
    }
    from=max(from,get_first(a,b));
    for(int i=from;;i++){
       if(b*(maxed-cur+1)<=a*i) return;
       if(ban.count(i)) continue;
       v[cur]=i;
       ll b2=b*i;
       ll a2=a*i-b;
       ll g=gcd(a2,b2);
       dfs(cur+1,i+1,a2/g,b2/g);
    }
    return;
}

int main()
{
    int T;scanf("%d",&T);
    int t=0;
    while(T--){
       ban.clear();
       memset(ans,-1,sizeof(ans));
       int k;
       ll a,b;
       scanf("%lld %lld %d",&a,&b,&k);
       while(k--){
          ll x;scanf("%lld",&x);ban.insert(x);
       }
       ok=false;
       for(maxed=1;;maxed++){
          memset(ans,-1,sizeof(ans));
          dfs(0,get_first(a,b),a,b);
          if(ok) break;
       }
       printf("Case %d: %lld/%lld=1/%lld",++t,a,b,ans[0]);
       for(int i=1;i<=maxed;i++) printf("+1/%lld",ans[i]);
       printf("\n");
    }
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,s,x;
    cin>>t>>s>>x;
    long long p;
    int ok=0;
    if(t==x) ok=1;
    for(int i=1;;i++){
        p=i*s+t;
        if(p==x||p+1==x) ok=1;
        if(p>=x) break;
    }
    printf("%s\n",ok==1?"YES":"NO");
}
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,ans;
    while(cin>>s){
        string a,d;int b=0;
        int dian=0,E=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0'&&s[i]<='9'){
              if(!dian&&!E) a+=s[i];
              else if(dian&&!E) d+=s[i];
              else if(E&&dian) b=b*10+s[i]-'0';
            }
            else if(s[i]=='.') dian=1;
            else if(s[i]=='e') E=1;
        }
        if(a=="0"&&d=="0") cout<<"0"<<endl;
        else{
            if(b==0){
                cout<<a<<"."<<d<<endl;
            }
            else{
                int n=b-d.size();
                if(a!="0") cout<<a;
                if(n>0){
                    cout<<d;
                    for(int i=0;i<n;i++) cout<<"0";
                    cout<<endl;
                }
                else if(n<0){
                    for(int i=0;i<b;i++) cout<<d[i];
                    cout<<".";
                    for(int i=b;i<d.size();i++) cout<<d[i];
                    cout<<endl;
                }
                else cout<<d<<endl;
            }
        }
    }
}

/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    ll a[4];
} A[1005];
set<long long> s,ss;
int main(void) {
    long long i,j,t,a,b,rt,ch,cnt,ans;
    ll n;
    scanf("%I64d",&n);
    i=0;
    while(n--) {
        scanf("%I64d",&ch);
        if(ch==1) {
            scanf("%I64d %I64d %I64d",&A[i].a[0],&A[i].a[1],&A[i].a[2]);
            s.clear();
            t=A[i].a[0];
            while(t) {
                s.insert(t);
                t/=2;
            }
            t=A[i].a[1];
            while(t) {
                if(s.count(t)) break;
                t/=2;
            }
            A[i++].a[3]=t;

        } else {
            scanf("%I64d %I64d",&a,&b);
            ss.clear();
            t=a;
            while(t) {
                ss.insert(t);
                t/=2;
            }
            t=b;
            while(t) {
                if(ss.count(t)) break;
                t/=2;
            }
            rt=t;
            ans=0;
            for(j=0; j<i; j++) {
                cnt=0;
                s.clear();
                ss.clear();
                t=A[j].a[0];
                while(t) {
                    s.insert(t);
                    if(t==A[j].a[3]) break;
                    t/=2;
                }
                t=A[j].a[1];
                while(t) {
                    s.insert(t);
                    if(t==A[j].a[3]) break;
                    t/=2;
                }

                t=a;
                while(t) {
                    if(s.count(t)){ cnt++; ss.insert(t);}
                    if(t==rt) break;
                    t/=2;
                }
                t=b;
                while(t) {
                    if(s.count(t)&&!ss.count(t)){ cnt++;}
                    if(t==rt) break;
                    t/=2;
                }
                ans+=max(0LL,cnt-1)*A[j].a[2];
            }
            printf("%I64d\n",ans);
        }
    }
}
*/
