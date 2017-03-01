#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10,inf=0x7ffffff;
int l[maxn],r[maxn],in[maxn],post[maxn],n,sum,ans;

bool read(int *a)
{
    n=0;
    string s;
    if(!getline(cin,s)) return false;
    stringstream buf(s);
    int x;
    while(buf>>x){
        a[n++]=x;
    }
    return true;
}

int bulid(int l1,int r1,int l2,int r2)
{
    if(l1>r1) return 0;
    int root=post[r2];
    int p=l1;
    while(in[p]!=root) p++;
    int cnt=p-l1;
    l[root]=bulid(l1,p-1,l2,l2+cnt-1);
    r[root]=bulid(p+1,r1,l2+cnt,r2-1);
    return root;
}

void dfs(int t,int num)
{
   num+=t;
   if(l[t]==0&&r[t]==0){
       if(num<sum||(num==sum&&ans>t)){
           ans=t;
           sum=num;
       }
       return;
   }
   if(l[t]!=0) dfs(l[t],num);
   if(r[t]!=0) dfs(r[t],num);
}

int main()
{
    while(read(in)){
       read(post);
       memset(l,0,sizeof(l));
       memset(r,0,sizeof(l));
       bulid(0,n-1,0,n-1);
       sum=inf;
       dfs(post[n-1],0);
       printf("%d\n",ans);
    }
}
