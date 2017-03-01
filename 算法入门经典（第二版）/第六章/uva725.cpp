/*
#include<bits/stdc++.h>
using namespace std;
int a[10]={0,1,2,3,4,5,6,7,8,9},v[10],n;
bool ok;
bool check(int x)
{
    int vis[10];
    vector<int>e;
    while(x){
        e.push_back(x%10);
        x/=10;
    }
    if(e.size()==4&&v[0]==1) return false;
    else vis[0]=1;
    for(int i=0;i<=9;i++) if(v[i]==1) vis[i]=v[i];
    for(int i=0;i<e.size();i++) vis[e[i]]++;
    for(int i=0;i<=9;i++)  if(vis[i]==0) return false;
    return true;
}

void dfs(int cur)
{
   if(cur==5){
      int b[5],t=0;
      for(int i=0;i<=9;i++){
         if(v[i]) b[t++]=a[i];
      }
      do{
         int num=0;
         for(int i=0;i<5;i++) num=num*10+b[i];
         if(num%n==0&&check(num/n)){
             ok=true;
             printf("%d / %d = %d\n",num,num/n,n);
         }
      }while(next_permutation(b,b+5));
      return;
   }
   for(int i=0;i<=9;i++){
      if(!v[i]){
         v[i]=1;
         dfs(cur+1);
         v[i]=0;
      }
   }
}
int main()
{
     while(scanf("%d",&n)&&n){
        memset(v,0,sizeof(v));
        ok=false;
        dfs(0);
        if(!ok) printf("There are no solution for %d.\n\n",n);
        else printf("\n");
     }
}

#include<bits/stdc++.h>
using namespace std;
int x[10]={2,1,2,3,1,2,3,1,2,3},y[10]={4,1,1,1,2,2,2,3,3,3};
int main()
{
    int n;
    while(cin>>n){
        string s;cin>>s;
        int minx=3,maxx=1,miny=4,maxy=1;
        for(int i=0;i<n;i++){
            int d=(int)(s[i]-'0');
            minx=min(minx,x[d]);
            maxx=max(maxx,x[d]);
            miny=min(miny,y[d]);
            maxy=max(maxy,y[d]);
        }
        int ans=(maxx-minx+1)*(maxy-miny+1);
        //cout<<ans<<endl;
        if(ans>6) printf("YES\n");
        else printf("NO\n");
    }
}

#include<bits/stdc++.h>
using namespace std;
int a[200000+10];
int ans[200000+10];
const int inf=0x7fffff;
int main()
{
    int n;
    while(~scanf("%d",&n)){
        ans[1]=0;
        for(int i=2;i<=n+1;i++) ans[i]=inf;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            ans[i]=min(ans[i-1]+1,min(ans[i],ans[i+1]+1));
            if(a[i]>i) ans[a[i]]=min(ans[a[i]],ans[i]+1);
        }
        ans[0]=-1;
        for(int i=n;i>=1;i--) ans[i]=min(ans[i],min(ans[i-1]+1,ans[i+1]+1));
        for(int i=1;i<=n;i++) ans[i]=min(ans[i],min(ans[i-1]+1,ans[i+1]+1));
        for(int i=n;i>=1;i--) ans[i]=min(ans[i],min(ans[i-1]+1,ans[i+1]+1));
        for(int i=1;i<n;i++) printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
}

/*
using namespace std;
long long n,m;
long long judge(long long x){
    long long cnt,i,j;
    cnt=0;
    for(i=2;i<=1000000;i++){
        j=i*i*i;
        cnt+=x/j;
    }
    if(cnt>=m) return 1;
    else return 0;
}
int main(void) {
    long long left,right,mid;
    scanf("%lld",&m);
    left=0;right=1e18;
    while(left<right){
        mid=(right-left)/2+left;
        //cout<<mid<<endl;
        if(judge(mid)) right=mid;
        else left=mid+1;
    }
    long long cnt,i,j;
    cnt=0;
    for(i=2;i<=1000000;i++){
        j=i*i*i;
        cnt+=left/j;
    }
    if(cnt==m) printf("%lld\n",left);
    else printf("-1\n");
}

#include<bits/stdc++.h>
using namespace std;
int a[200000+10];
int ans[200000+10];
const int inf=0x7fffff;
int n,v[2000000+10];
struct node
{
    int to,v;
};
vector<node>E[200000+10];

void dijkstra()
{
   for(int i=0;i<E[1].size();i++) ans[E[1][i].to]=1;
   for(int i=1;i<n;i++){
      int minn=inf,index;
      for(int j=1;j<=n;j++){
         if(minn>ans[j]&&v[j]==0){
             minn=ans[j];
             index=j;
         }
      }
      cout<<index<<endl;
      v[index]=1;
      ans[index]=minn;
      for(int j=0;j<E[index].size();j++){
         ans[E[index][j].to]=min(ans[E[index][j].to],ans[index]+E[index][j].v);
      }
   }
}

int main()
{
    scanf("%d",&n);
    ans[1]=0;
    for(int i=2;i<=n+1;i++) ans[i]=inf;
    memset(v,0,sizeof(v));
    v[1]=1;
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        if(x!=i){
           if(i==1) ans[x]=1;
           E[i].push_back(node{x,1});
           E[i].push_back(node{i-1,1});
           E[i].push_back(node{i+1,1});
        }
    }
        for(int i=1;i<n;i++) printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
    dijkstra();
    for(int i=1;i<n;i++) printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
}
*/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x7ffffff;
int dist[2000000+10];

struct node
{
    int to,v;
};

vector<node>E[200000+10];

void dfs(int u)
{
    for(int i=0;i<E[u].size();i++){
        if(dist[E[u][i].to]>dist[u]+E[u][i].v){
            dist[E[u][i].to]=dist[u]+E[u][i].v;
            dfs(E[u][i].to);
        }
    }
    return;
}

int main()
{
    int n;
    while(~scanf("%d",&n)){
      for(int i=1;i<=n+1;i++){
           E[i].clear();
           dist[i]=inf;
      }
      for(int i=1;i<=n;i++){
         int x;scanf("%d",&x);
         E[i].push_back(node{x,1});
      }
      for(int i=1;i<=n;i++){
          if(i>1) E[i].push_back(node{i-1,1});
          if(i<n) E[i].push_back(node{i+1,1});
      }
      dist[1]=0;
      dfs(1);
      for(int i=1;i<n;i++) printf("%d ",dist[i]);
      printf("%d\n",dist[n]);
    }
}
