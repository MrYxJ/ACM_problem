#include<cstdio>
#include<iostream>
using namespace std;
int n;
double H[1010],A,B;
bool check(double x)
{
   H[1]=A,H[2]=x;
   for(int i=3;i<=n;i++){
      H[i]=2.0*H[i-1]+2-H[i-2];
      if(H[i]<0) return false;
   }
   B=H[n];
   return true;
}

int main()
{
  while(~scanf("%d %lf",&n,&A)){
     double l=0,r=A;
     for(int i=0;i<=100;i++){
         double mid=(l+r)*0.5;
         if(check(mid)) r=mid;
         else l=mid;
     }
     printf("%.2f\n",B);
  }
}
