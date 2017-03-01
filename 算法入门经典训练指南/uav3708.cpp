#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m){
       double ans=0;
       for(int i=1;i<n;i++){
          double pos=(double)i/n*(n+m);
          ans+=abs(pos-floor(0.5+pos))/(n+m);
       }
       printf("%.4lf\n",ans*10000);
    }
}
