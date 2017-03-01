#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1000000+10;
long long a[maxn],c[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        long long M=sum/n;
        c[0]=0;
        for(int i=1;i<=n;i++) c[i]=c[i-1]+a[i]-M;
        sort(c,c+n);
        long long x1=c[n/2],ans=0;
        for(int i=0;i<n;i++)
            ans+=abs(c[i]-x1);
        printf("%lld\n",ans);
    }
    return 0;
}
