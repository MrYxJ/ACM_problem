#include<bits/stdc++.h>
using namespace std;
int dp[200];
struct node{int x,y,z;}a[200];
bool cmp(node a,node b)
{
    return a.x==b.x ? a.y<=b.y : a.x<b.x;
}

int main()
{
    int n,cnt=1;
    while(scanf("%d",&n)&&n){
         int t=0;
         for(int i=0;i<n;i++){
             int x,y,z;scanf("%d%d%d",&x,&y,&z);
             a[t].x=x,a[t].y=y,a[t++].z=z;
             a[t].x=x,a[t].y=z,a[t++].z=y;
             a[t].x=y,a[t].y=x,a[t++].z=z;
             a[t].x=y,a[t].y=z,a[t++].z=x;
             a[t].x=z,a[t].y=x,a[t++].z=y;
             a[t].x=z,a[t].y=y,a[t++].z=x;
         }
         sort(a,a+t,cmp);
         for(int i=1;i<t;i++){
            dp[i]=a[i].z;
            for(int j=0;j<i;j++){
                if(a[i].x>a[j].x&&a[i].y>a[j].y){
                    dp[i]=max(dp[i],dp[j]+a[i].z);
                }
            }
         }
         printf("Case %d: maximum height = %d\n",cnt++,*max_element(dp,dp+t));
    }
}
