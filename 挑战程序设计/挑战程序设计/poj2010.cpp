#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<limits>
#include<algorithm>
using namespace std;
const int maxn=100000+10,inf=10*0x7ffffff;
pair<int,int>cow[maxn];
int low[maxn],up[maxn];

int main()
{
   int n,c,f;
   //cout<<inf<<" "<<10*0x7ffffff<<endl;
   while(~scanf("%d%d%d",&n,&c,&f)){
     int half=n/2;
     for(int i=0;i<c;i++){
        scanf("%d%d",&cow[i].first,&cow[i].second);
     }
     sort(cow,cow+c);
     priority_queue<int>pque;
     int total=0;
     for(int i=0;i<c;i++){
        low[i]=pque.size()==half ? total : inf;
        total+=cow[i].second;
        pque.push(cow[i].second);
        while(pque.size()>half){
            int temp=pque.top();
            total-=temp;
            pque.pop();
        }
     }
     while(!pque.empty()) pque.pop();
     total=0;
     for(int i=c-1;i>=0;i--){
        up[i]=pque.size()==half ? total : inf;
        total+=cow[i].second;
        pque.push(cow[i].second);
        while(pque.size()>half){
            int temp=pque.top();
            total-=temp;
            pque.pop();
        }
     }
     int ans=-1;
     for(int i=c-1;i>=0;i--){
        if(low[i]+cow[i].second+up[i]<=f){
            ans=cow[i].first;
            break;
        }
     }
     printf("%d\n",ans);
   }
}
