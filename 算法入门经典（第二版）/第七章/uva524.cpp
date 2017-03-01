#include<bits/stdc++.h>
using namespace std;
int n,a[20],v[20];
bool check(int x)
{
   for(int i=2;i<x;i++) if(x%i==0) return false;
   return true;
}

void dfs(int cur)
{
    if(cur==n+1){
        if(check(a[n]+a[1])){
           for(int i=1;i<n;i++) printf("%d ",a[i]);
           printf("%d\n",a[n]);
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!v[i]&&(cur==1||check(i+a[cur-1]))){
            a[cur]=i;
            v[i]=1;
            dfs(cur+1);
            v[i]=0;
        }
    }
}

int main()
{
    int t=1;
    while(~scanf("%d",&n)){
         memset(v,0,sizeof(v));
         if(t>1) printf("\n");
         printf("Case %d:\n",t++);
         a[1]=1;
         v[1]=1;
         dfs(2);
    }
}
