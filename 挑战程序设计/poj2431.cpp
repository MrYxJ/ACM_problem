#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
  int d,f;
}a[10010];

bool cmp(node a,node b)
{
    return a.d<b.d;
}

priority_queue<int,vector<int>,less<int> >pque;

int main()
{
    int n,l,p;
    while(cin>>n){
        while(!pque.empty()) pque.pop();
        int ok=1;
        for(int i=0;i<n;i++){
            cin>>a[i].d>>a[i].f;
        }
        cin>>l>>p;
        for(int i=0;i<n;i++) a[i].d=l-a[i].d;
        a[n].d=l,a[n].f=0;
        sort(a,a+n,cmp);
        int ans=0,pos=0;
        for(int i=0;i<=n;i++){
            int d=a[i].d-pos;
            while(p<d){
                if(pque.empty()){
                    cout<<-1<<endl;
                    ok=0;
                    break;
                }
                else{
                    p+=pque.top();
                    pque.pop();
                    ans++;
                }
            }
            p-=d;
            pos=a[i].d;
            pque.push(a[i].f);
        }
        if(ok) cout<<ans<<endl;
    }
}
