#include<bits/stdc++.h>
using namespace std;
int a[20];
int main()
{
    int n,t=0;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
              long long num=1;
              for(int k=i;k<=j;k++) num*=a[k];
              ans=max(ans,num);
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",++t,ans);
    }
}
