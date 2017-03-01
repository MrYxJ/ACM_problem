#include<cstdio>
#include<cstring>
using namespace std;
const int N=100000;
int f[N*2+10];
void init(){for(int i=0;i<=N*2+10;i++) f[i]=i;}
int Find(int x) {return x==f[x]? x: f[x]=Find(f[x]);}
int Merge(int x,int y){ x=Find(x);y=Find(y); if(x==y) return 0; f[x]=y; return 1;}
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        int n,m;scanf("%d%d",&n,&m);
        init();for(int i=0;i<m;i++){
         char c;int a,b;scanf(" %c %d %d",&c,&a,&b);
          if(c=='A'){
            if(Find(a)==Find(b)&&Find(a+N)==Find(b+N)) printf("In the same gang.\n");
            else if(Find(a)==Find(b+N)&&Find(a+N)==Find(b)) printf("In different gangs.\n");
            else printf("Not sure yet.\n");
          }
          else if(c=='D') Merge(a,b+N),Merge(a+N,b);
        }
    }
}
