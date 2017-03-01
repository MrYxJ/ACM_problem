#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int head[20005],can[20005];
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)&&n&&m)
   {
       for(int i=0;i<n;i++)
      {
         scanf("%d",&head[i]);
      }
      for(int i=0;i<m;i++)
      {
        scanf("%d",&can[i]);
      }
      sort(head,head+n);
      sort(can,can+m);
      if(n>m)
      {
          printf("Loowater is doomed!\n");
          continue;
      }
      int flag=1;
      for(int i=n-1,j=m-1;i>=0;i--,j--)
      {
          if(head[i]>can[j])
          {
             flag=0;
             break;
          }
      }
      if(!flag)
      {
          printf("Loowater is doomed!\n");
          continue;
      }
      else
      {
          int sum=0;
          for(int i=0,j=0;i<n;)
          {
               if(can[j]>=head[i])
               {
                   sum+=can[j];
                   i++,j++;
               }
               else
                   j++;
          }
          printf("%d\n",sum);
      }

   }
}
