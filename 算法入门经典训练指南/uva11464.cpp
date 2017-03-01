/*
#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >dict;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        dict.clear();
        for(int i=1;i<=n;i++){
            int x;scanf("%d",&x);
            if(!dict.count(x)) dict[x]=vector<int>();
            dict[x].push_back(i);
        }
        for(int i=0;i<m;i++){
            int k,v;scanf("%d%d",&k,&v);
            if(!dict.count(v)||dict[v].size()<k) printf("0\n");
            else printf("%d\n",dict[v][k-1]);
        }
    }
}
*/
#include<bits/stdc++.h>
using namespace std;
int mod=9973;
int tree[100000+10];
char s[100000+10];
int ex_gcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int ret=ex_gcd(b,a%b,x,y),t=x;
    x=y;y=t-a/b*x;
    return ret;
}
int lowbit(int x)
{
    return x&(-x);
}
void update(int i,int c)
{
   while(i<=100000){
      tree[i]=(tree[i]*c)%mod;
      i+=lowbit(i);
   }
}

int get_ans(int i)
{
    int sum=1;
    while(i){
        sum=(sum*tree[i])%mod;
        i-=lowbit(i);
    }
    return sum;
}

int main()
{
    int n,x,y,ans,anss,i;
    while(~scanf("%d",&n)){
        scanf("%s",s);
        for(i=0;i<100010;i++){
            tree[i]=1;
        }
        for(i=0;s[i]!='\0';i++){
            update(i+1,s[i]-28);
        }
        for(i=0;i<n;i++){
            int a,b;scanf("%d%d",&a,&b);
            anss=get_ans(b);
            ans=get_ans(a-1);
            ex_gcd(ans,mod,x,y);
            if(x<0) x+=mod;
            printf("%d\n",(anss*x)%mod);
        }
    }
}
