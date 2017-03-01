#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100000+10],n,m;
bool check(int x)
{
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=n-(lower_bound(a,a+n,a[i]+x)-a);
    }
    return sum>(n*(n-1)/2-m);
}

int main()
{
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        int l=0,r=a[n-1]-a[0];
        m=((n-1)*n/2+1)/2;
        while(l<=r){
           int mid=(l+r)/2;
           if(check(mid)) l=mid+1;
           else r=mid-1;
        }
        printf("%d\n",l-1);
    }
}
