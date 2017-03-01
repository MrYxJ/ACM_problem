#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1200],v[1200],b[1200],n,k,t,ok;
void dfs(int cur)
{
    if(ok) return;
    if(cur==n){
        t++;
        if(t==k+1){
            for(int i=0;i<n-1;i++) printf("%d ",b[i]);
            printf("%d\n",b[n-1]);
            ok=1;
        }
        return;
    }
    int last=0;
    for(int i=0;i<n;i++){
        if(!v[i]&&a[i]>last){
            b[cur]=a[i];
            last=a[i];
            v[i]=1;
            dfs(cur+1);
            v[i]=0;
        }
    }
}
/*
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        memset(v,0,sizeof(v));
        t=0;ok=0;
        while(t<=k){
          dfs(0);
          sort(a,a+n);
          memset(v,0,sizeof(v));
        }
    }
}

int main()
{
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        t=0;
        k+=1;
        while(t<k){
          do{
              t++;
              if(t==k) break;
          }while(next_permutation(a,a+n));
          if(t==k) break;
          sort(a,a+n);
        }
        for(int i=0;i<n-1;i++) printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
    }
}
*/

int main()
{
    int T;scanf("%d",&T);
    while(T--){
        int n,k;scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int  t=0;
        while(t<k){
           int p=-1;
           for(int i=n-1;i>0;i--){
              if(a[i]>a[i-1]){
                  p=i;break;
              }
           }
           if(p==-1) sort(a,a+n);
           else{
             int index=p;
             for(int i=p;i<n;i++){
                if(a[i]>a[p-1]&&a[i]<a[index]) index=i;
             }
             swap(a[p-1],a[index]);
             sort(a+p,a+n);
           }
           t++;
        }
        for(int i=0;i<n-1;i++) printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
    }
}

