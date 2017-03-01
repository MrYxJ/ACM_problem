#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500+10];
int n,k;
bool v[500+10];

bool check(ll x)
{
   ll cnt=1,sum=0;
   for(int i=0;i<n;i++){
       if(sum+a[i]>x){
           cnt++;
           sum=a[i];
       }
       else sum+=a[i];
   }
   return  k>=cnt;
}

int main()
{
    int T;
    scanf("%d%*c",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        ll l=0,r=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            r+=a[i];
            l=max(l,a[i]);
        }
        while(l<=r){
           int mid=l+(r-l)/2;
           if(check(mid)) r=mid-1;
           else l=mid+1;
        }
        r+=1;
        ll sum=0;
        int t=1;
        memset(v,false,sizeof(v));
        for(int i=n-1;i>=0;i--){
            if(sum+a[i]>r){
                v[i]=true;
                sum=a[i];
                t++;
            }
            else sum+=a[i];
            if(k-t==i+1){
                for(int j=0;j<=i;j++) v[j]=true;
                break;
            }
        }
        for(int i=0;i<n-1;i++){
           printf("%lld ",a[i]);
           if(v[i]) printf("/ ");
        }
        printf("%lld\n",a[n-1]);
    }
}
