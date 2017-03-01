#include<bits/stdc++.h>
using namespace std;
int num[30],f[30],in[30],out[30],vis[30];
char s[1010];
int F(int x) {return f[x]==x? x:f[x]=F(f[x]);}
void Merge(int a,int b) {a=F(a);b=F(b);if(a!=b) f[a]=b;}
int main()
{
    int T;scanf("%d",&T);
    while(T--){
      int n;scanf("%d",&n);
      memset(in,0,sizeof(in));
      memset(out,0,sizeof(out));
      memset(vis,0,sizeof(vis));
      for(int i=0;i<=26;i++) f[i]=i;
      for(int i=0;i<n;i++){
         scanf("%s",s);
         int a=s[0]-'a',b=s[strlen(s)-1]-'a';
         out[a]++;in[b]++;
         vis[a]=1;vis[b]=1;
         Merge(a,b);
      }
      int cnt=0;
      for(int i=0;i<=26;i++){
        if(vis[i]&&F(i)==i) cnt++;
      }
      if(cnt>=2){
        printf("The door cannot be opened.\n");
        continue;
      }
      cnt=0;
      int t1=-1,t2=-1;
      bool ok=true;
      for(int i=0;i<=26;i++){

        if(vis[i]){
            if(in[i]!=out[i]){
                if(in[i]+1==out[i]&&t1==-1) t1=i;
                else if(in[i]==out[i]+1&&t2==-1) t2=i;
                else ok=false;
            }
        }
      }
      printf("%s\n",ok ? "Ordering is possible.":"The door cannot be opened.");
    }
}
