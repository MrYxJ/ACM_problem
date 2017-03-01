#include<cstdio>
#include<algorithm>
using namespace std;
struct Job
{
  int b,j;
}job[1010];

bool cmp(Job a,Job b)
{
    return a.j>b.j;
}

int main()
{
   int n,T=0;
   while(scanf("%d",&n)&&n)
   {
       T++;
       for(int i=0;i<n;i++)
           scanf("%d %d",&job[i].b,&job[i].j);
       sort(job,job+n,cmp);
       int t=0,ans=0;
       for(int i=0;i<n;i++)
       {
           t+=job[i].b;
           ans=max(ans,t+job[i].j);
       }
       printf("Case %d: %d\n",T,ans);
   }
   return 0;
}
