#include<bits/stdc++.h>
using namespace std;
int n,L,cnt;
int s[100];
bool flag;
void dfs(int cur)
{
   if(flag) return;
   if(cnt++==n){
      for(int i=0;i<cur;i++){
         if(i%64==0&&i) printf("\n");
         if(i%4==0&&i&&i!=64) printf(" ");
         printf("%c",s[i]+'A');
      }
      flag=true;
      printf("\n%d\n",cur);
      return;
   }
   for(int i=0;i<L;i++){
      s[cur]=i;
      int ok=1;
      for(int j=1;j*2<=cur+1;j++){
         int equal=1;
         for(int k=0;k<j;k++){
           if(s[cur-k]!=s[cur-j-k]) {equal=0;break;}
         }
         if(equal){ok=0;break;}
      }
     if(ok) dfs(cur+1);
   }
}

int main()
{
    while(~scanf("%d %d",&n,&L)&&n&&L){
        memset(s,0,sizeof(s));
        cnt=0;
        flag=false;
        dfs(0);
    }
}
