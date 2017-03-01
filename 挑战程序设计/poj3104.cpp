#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[100000+10],n,k;
bool check(int x)
{
    long long sum=0;
    for(int i=0;i<n;i++){
        int t=a[i]-x;
        if(t>0) sum+=(t+k-1)/k;
    }
    return sum<=x;
}

int main()
{
    while(~scanf("%d",&n)){
        int maxx=0;
        for(int i=0;i<n;i++) scanf("%d",&a[i]),maxx=max(maxx,a[i]);
        scanf("%d",&k);
        k--;
        if(k==0){
            printf("%d\n",maxx);
            continue;
        }
        int l=0,r=maxx+1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid)) r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",r+1);
    }
}
