#include<bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;
struct node
{
    int x,y;
}a[1010];
int M[1010][1010],dp[1010],n;
int dfs(int i)
{
    int& ans=dp[i];
    if(ans>0) return ans;
    ans=1;
    for(int j=0;j<n;j++){
        if(M[i][j]) ans=max(ans,dfs(j)+1);
    }
    return ans;
}

int main()
{
    cout<< (-1 << 30)<<endl;
    cout<< (-1 >> 30)<<endl;
    int T;scanf("%d",&T);
    while(T--){
       memset(M,0,sizeof(M));
       scanf("%d",&n);
       for(int i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
       for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
             if((a[i].x<a[j].x&&a[i].y<a[j].y)||(a[i].y<a[j].x&&a[i].x<a[j].y)) M[i][j]=1;
          }
       }
       int maxx=0;
       memset(dp,0,sizeof(dp));
       for(int i=0;i<n;i++){
           dfs(i);
           maxx=max(maxx,*max_element(dp,dp+n));
       }
       printf("%d\n",maxx);
    }
}

/*
#include<bits/stdc++.h>
using namespace std;
int dp[1010];
struct node{
  int a,b;
}c[1010];
bool cmp(node x,node y){
  return x.a==y.a ?  x.b<y.b: x.a<y.a;
}

int main(){
   int T;scanf("%d",&T);
   while(T--){
       int n;scanf("%d",&n);
       for(int i=0;i<n;i++){
           scanf("%d%d",&c[i].a,&c[i].b);
           if(c[i].a>c[i].b) swap(c[i].a,c[i].b);
       }
       sort(c,c+n,cmp);
       for(int i=0;i<=n;i++) dp[i]=1;
       for(int i=0;i<n-1;i++){
         for(int j=i+1;j<n;j++){
             if(c[j].a>c[i].a&&c[j].b>c[i].b) dp[j]=max(dp[j],dp[i]+1);
         }
       }
       printf("%d\n",*max_element(dp,dp+n));
   }
}
*/
