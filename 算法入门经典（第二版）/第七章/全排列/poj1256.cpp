#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char str[20],a[20];
int v[20],n;
bool cmp(char a,char b)
{
   double t1=a,t2=b;
   if(a>='A'&&a<='Z') t1+=31.5;
   if(b>='A'&&b<='Z') t2+=31.5;
   return t1<t2;
}

void dfs(int cur)
{
   if(cur==n){
      printf("%s\n",a);
      return;
   }
   int last=0;
   for(int i=0;i<n;i++){
      if(!v[i]&&last!=str[i]){
          a[cur]=str[i];
          last=str[i];
          v[i]=1;
          dfs(cur+1);
          v[i]=0;
      }
   }
}

int main()
{
    int T;scanf("%d",&T);
    while(T--){
         memset(v,0,sizeof(v));
         scanf("%s",str);
         n=strlen(str);
         a[n]='\0';
         sort(str,str+n,cmp);
         dfs(0);
    }
}
